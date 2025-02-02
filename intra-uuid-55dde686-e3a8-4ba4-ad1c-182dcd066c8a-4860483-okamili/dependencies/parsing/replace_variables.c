/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:42:17 by okamili           #+#    #+#             */
/*   Updated: 2023/06/20 23:33:18 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	next_variable(char *str, int index)
{
	int	i;
	int	dquotes;
	int	squotes;

	i = -1;
	dquotes = 0;
	squotes = 0;
	while (++i < index && str[i])
	{
		dquotes += (!(squotes & 1) && str[i] == '"');
		squotes += (!(dquotes & 1) && str[i] == '\'');
	}
	while (str[i] && ((squotes & 1) || (str[i] != '$')))
	{
		dquotes += (!(squotes & 1) && str[i] == '"');
		squotes += (!(dquotes & 1) && str[i] == '\'');
		i++;
	}
	if (str[i] == '$' && !ft_strchr("\t $|<>;\"", str[i + 1]))
		return (i);
	return (-1);
}

static char	*get_variable_name(char *str, int index)
{
	int	i;

	i = index + 1;
	while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9')
			|| ft_strchr("@_?", str[i])))
	{
		i++;
		if ((str[i - 1] >= '0' && str[i - 1] <= '9')
			|| ft_strchr("@?", str[i - 1]))
			break ;
	}
	return (ft_substr(str, index, i - index));
}

static char	*skip_and_replace(char *str, char *w0, char *w1, int count)
{
	char	*tmp0;
	char	*tmp1;
	char	*result;

	if (!str)
		return (NULL);
	tmp0 = ft_substr(str, 0, count);
	tmp1 = ft_substr(str, count, ft_strlen(str));
	tmp1 = replace_word(tmp1, w0, w1, 1);
	result = ft_strjoin(tmp0, tmp1);
	free(tmp0);
	free(tmp1);
	free(str);
	free(w0);
	return (result);
}

static char	*clean_unused_var_sym(char *str)
{
	int	i;
	int	dquotes;
	int	squotes;

	i = -1;
	dquotes = 0;
	squotes = 0;
	while (str[++i])
	{
		dquotes += (!(squotes & 1) && str[i] == '"');
		squotes += (!(dquotes & 1) && str[i] == '\'');
		if (str[i] == '$' && !(squotes & 1))
		{
			if ((str[i + 1] == '"' || str[i + 1] == '\'') && !(dquotes & 1))
				str = skip_and_replace(str, ft_strdup("$"), NULL, i--);
		}
	}
	return (str);
}

char	*replace_variables(char *str, int err)
{
	int		var_index;
	char	*var_name;
	char	*temp;
	char	*result;

	result = clean_unused_var_sym(ft_strdup(str));
	var_index = next_variable(result, 0);
	while (var_index != -1)
	{
		var_name = get_variable_name(result, var_index);
		temp = replace_all_words(var_name, "$", NULL, 0);
		if (ft_strncmp("$?", var_name, 3) && temp[0])
			result = skip_and_replace(result, var_name, fetch(temp), var_index);
		else if (temp[0])
		{
			free(temp);
			temp = ft_itoa(err);
			result = skip_and_replace(result, var_name, temp, var_index);
		}
		free(temp);
		var_index = next_variable(result, var_index + 1);
	}
	return (result);
}
