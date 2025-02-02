/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:53:11 by okamili           #+#    #+#             */
/*   Updated: 2023/06/15 21:12:08 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

static int	check_unset_arg(char *arg)
{
	int		i;
	char	*tmp;

	i = -1;
	while (arg && arg[++i])
	{
		if (!((arg[i] >= 'a' && arg[i] <= 'z')
				|| (arg[i] >= 'A' && arg[i] <= 'Z')
				|| ((arg[i] >= '0' && arg[i] <= '9') && i)
				|| arg[i] == '_'))
		{
			tmp = replace_word("Minishell: unset: `X': "
					"not a valid identifier\n", "X", arg, 0);
			ft_putstr_fd(tmp, 2);
			free(tmp);
			return (1);
		}
	}
	return (0);
}

void	unset_env(t_cmd *cmd)
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (cmd->args[++i])
	{
		cmd->error = check_unset_arg(cmd->args[i]);
		if (!cmd->error)
		{
			tmp = find_env(g_env, cmd->args[i]);
			if (tmp)
			{
				free(tmp->value);
				tmp->value = NULL;
				tmp->hide = 1;
			}
		}
		else
			break ;
	}
}

void	list_env(void)
{
	t_env	*temp;

	temp = g_env;
	while (temp)
	{
		if (!temp->hide && temp->value)
			printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
}
