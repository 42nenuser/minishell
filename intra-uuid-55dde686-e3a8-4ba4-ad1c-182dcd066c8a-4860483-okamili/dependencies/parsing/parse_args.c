/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:42:01 by okamili           #+#    #+#             */
/*   Updated: 2023/05/31 02:37:52 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*next_arg(char *cmd)
{
	int	dquotes;
	int	squotes;

	dquotes = 0;
	squotes = 0;
	while (!ft_strchr("\t ><|;", cmd[0]) || ((dquotes & 1) || (squotes & 1)))
	{
		dquotes += (!(squotes & 1) && cmd[0] == '"');
		squotes += (!(dquotes & 1) && cmd[0] == '\'');
		cmd++;
	}
	return (cmd);
}

static int	args_count(char *cmd)
{
	int	count;

	count = 0;
	while (cmd[0])
	{
		if (ft_strchr("><", cmd[0]))
		{
			while (ft_strchr("><", cmd[0]))
				cmd++;
			count--;
		}
		else if (!ft_strchr("\t |;", cmd[0]))
		{
			count++;
			cmd = next_arg(cmd);
		}
		else
			cmd++;
	}
	return (count);
}

char	**parse_args(char *cmd)
{
	int		index;
	int		count;
	char	*tmp;
	char	**result;

	index = 0;
	count = args_count(cmd);
	result = ft_calloc(count + 1, sizeof(char *));
	while (index < count)
	{
		while (cmd[0] && ft_strchr("\t ", cmd[0]))
			cmd++;
		if (ft_strchr("><", cmd[0]))
			while (ft_strchr("\t ><", cmd[0]))
				cmd++;
		else
		{
			tmp = ft_substr(cmd, 0,
					(ft_strlen(cmd) - ft_strlen(next_arg(cmd))));
			result[index++] = clean_quotes(tmp);
			free(tmp);
		}
		cmd = next_arg(cmd);
	}
	return (result);
}
