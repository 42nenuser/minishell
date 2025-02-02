/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_prgm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:26:37 by okamili           #+#    #+#             */
/*   Updated: 2023/06/15 04:28:38 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

static long long	parse_num(char *str, int *err)
{
	int			dig;
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	while (str && !*err && str[0] >= '0' && str[0] <= '9')
	{
		dig = (str[0] - '0');
		if (result > 922337203685477580
			|| (result == 922337203685477580 && dig > 7 && sign == 1)
			|| (result == 922337203685477580 && dig > 8 && sign == -1))
			*err = 1;
		result = (result * 10) + dig;
		str++;
	}
	return (result * sign);
}

static int	extract_err_code(char *code)
{
	int			err;
	long long	i;

	if (!code)
		return (-1);
	i = -1;
	if (code[0] == '-' || code[0] == '+')
		i++;
	while (code[++i])
	{
		if (code[i] < '0' || code[i] > '9')
		{
			ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
			return (255);
		}
	}
	err = 0;
	i = parse_num(code, &err);
	if (err)
	{
		ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
		return (255);
	}
	return ((size_t)i % 256);
}

void	close_prgm(t_cmd *cmd)
{
	int		errnm;

	if (!cmd)
		exit(0);
	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		cmd->error = 1;
		return ;
	}
	rl_clear_history();
	destory_all_env(g_env);
	errnm = extract_err_code(cmd->args[1]);
	if (errnm < 0)
		errnm = cmd->prev_error;
	free_cmd_tree(cmd);
	printf("exit\n");
	exit(errnm);
}
