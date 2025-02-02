/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:49:27 by okamili           #+#    #+#             */
/*   Updated: 2023/06/15 00:25:56 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	print_error(char *s)
{
	ft_putstr_fd("Minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("'\n", 2);
}

static char	*get_separator(char *str)
{
	int		index[3];
	char	*result;

	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	result = ft_calloc(3, 1);
	while (str[0])
	{
		if ((!(index[1] & 1) && !(index[2] & 1)))
		{
			if (str[1] && ft_strchr("<>", str[0]) && ft_strchr(";|", str[1]))
				str++;
			else if (ft_strchr(";|", str[0]))
			{
				result[index[0]++] = str[0];
				result = ft_realloc(result, ft_strlen(result) + 2);
			}
		}
		index[1] += (!(index[2] & 1) && str[0] == '"');
		index[2] += (!(index[1] & 1) && str[0] == '\'');
		str++;
	}
	return (result);
}

int	check_separator(t_cmd *cmds)
{
	char	*temp;

	while (cmds)
	{
		temp = get_separator(cmds->cmd);
		if (ft_strlen(temp) == ft_strlen(cmds->cmd)
			|| (temp[0] == '|' && !cmds->next))
		{
			print_error(temp);
			free(temp);
			return (1);
		}
		cmds->sep = ft_strdup(temp);
		free(temp);
		cmds = cmds->next;
	}
	return (0);
}
