/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:19:06 by okamili           #+#    #+#             */
/*   Updated: 2023/06/01 04:48:51 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

static char	*env_name(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == '=')
			break ;
	if (str)
		return (ft_substr(str, 0, i));
	return (NULL);
}

static char	*env_val(char *str)
{
	int	i;
	int	start;
	int	len;

	i = -1;
	len = 0;
	while (str && str[++i])
		if (str[i] == '=')
			break ;
	start = i + 1;
	while (str && str[++i])
		len++;
	if (str)
		return (ft_substr(str, start, len));
	return (NULL);
}

void	env_init(int argc, char **argv, char **env)
{
	int			i;
	char		*name;
	char		*val;

	(void)argc;
	(void)argv;
	i = -1;
	while (env && env[++i])
	{
		name = env_name(env[i]);
		val = env_val(env[i]);
		g_env = add_env(g_env, name, val);
		free(name);
		free(val);
	}
}

static int	g_env_length(void)
{
	int		len;
	t_env	*tmp;

	len = 0;
	tmp = g_env;
	while (tmp)
	{
		if (!tmp->hide)
			len++;
		tmp = tmp->next;
	}
	return (len);
}

char	**export_env(void)
{
	t_env	*tmp;
	int		len;
	int		index;
	char	*holder;
	char	**result;

	index = 0;
	len = g_env_length();
	tmp = g_env;
	result = ft_calloc(len + 1, sizeof(char *));
	while (index < len && tmp)
	{
		if (!tmp->hide)
		{
			holder = replace_word("#NAME#=#VALUE#", "#NAME#", tmp->name, 0);
			result[index++] = replace_word(holder, "#VALUE#", tmp->value, 1);
		}
		tmp = tmp->next;
	}
	return (result);
}
