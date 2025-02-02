/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:48:06 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 15:57:59 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

void	pwd(void)
{
	char	*holder;

	holder = getcwd(NULL, 0);
	if (holder)
		printf("%s\n", holder);
	else
		perror("Minishell: pwd");
	free(holder);
}

void	cd(t_cmd *cmd)
{
	char	*temp;
	char	*path;

	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("Minishell: cd: too many arguments\n", 2);
		cmd->error = 1;
		return ;
	}
	if (!cmd->args[1])
		path = ft_strdup(fetch("HOME"));
	else if (ft_strlen(cmd->args[1]) == 1 && cmd->args[1][0] == '-')
		path = ft_strdup(fetch("OLDPWD"));
	else
		path = replace_word(ft_strdup(cmd->args[1]), "~", fetch("HOME"), 1);
	temp = getcwd(NULL, 0);
	if (chdir(path))
	{
		perror("Minishell: cd");
		cmd->error = 1;
	}
	g_env = add_env(g_env, "OLDPWD", temp);
	free(path);
	free(temp);
}

void	echo(t_cmd *cmd)
{
	int		i;
	int		j;
	int		new_line;

	i = 1;
	new_line = 0;
	while (cmd->args[i] && cmd->args[i][0] == '-')
	{
		j = 1;
		while (cmd->args[i][j] && cmd->args[i][j] == 'n')
			j++;
		if (j > 1 && !cmd->args[i][j])
			new_line = 1;
		else
			break ;
		i++;
	}
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[++i])
			printf(" ");
	}
	if (!new_line)
		printf("\n");
}

void	run_builtins(t_cmd *cmd)
{
	int	len;

	len = ft_strlen(cmd->exec);
	if (cmd->error)
		return ;
	if (len == 2 && !ft_strncmp("cd", cmd->exec, 2))
		cd(cmd);
	if (len == 3 && !ft_strncmp("pwd", cmd->exec, 3))
		pwd();
	if (len == 4 && !ft_strncmp("echo", cmd->exec, 4))
		echo(cmd);
	if (len == 4 && !ft_strncmp("exit", cmd->exec, 4))
		close_prgm(cmd);
	if (len == 3 && !ft_strncmp("env", cmd->exec, 3))
		list_env();
	if (len == 5 && !ft_strncmp("unset", cmd->exec, 5))
		unset_env(cmd);
	if (len == 6 && !ft_strncmp("export", cmd->exec, 6))
		run_export(cmd);
}
