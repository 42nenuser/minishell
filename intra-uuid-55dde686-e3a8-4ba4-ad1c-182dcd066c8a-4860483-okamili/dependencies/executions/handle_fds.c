/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:42:45 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 16:02:00 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

void	handle_fds(int pfd[2], int red[2], int newpfd[2])
{
	if (pfd)
	{
		if (red[0])
			dup2(pfd[0], STDIN_FILENO);
		if (red[1])
		{
			if (newpfd)
			{
				dup2(newpfd[1], STDOUT_FILENO);
				close(newpfd[1]);
			}
			else
				dup2(pfd[1], STDOUT_FILENO);
		}
		close(pfd[0]);
		close(pfd[1]);
	}
}

static int	handle_outred(char *file, int append)
{
	int		fd;
	char	*tmp;

	if (append)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0664);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
	{
		tmp = replace_word("Minishell: file", "file", file, 0);
		perror(tmp);
		free(tmp);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	handle_inred(char *file, int useheredoc, char *heredoc_data)
{
	int		pfd[2];
	int		fd;
	char	*tmp;

	if (useheredoc)
	{
		pipe(pfd);
		write(pfd[1], heredoc_data, ft_strlen(heredoc_data));
		close(pfd[1]);
		fd = pfd[0];
	}
	else
		fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		tmp = replace_word("Minishell: file", "file", file, 0);
		perror(tmp);
		free(tmp);
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	handle_redir(t_cmd *cmd)
{	
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (cmd->redir_sym[++i] && !result)
	{
		if (ft_strlen(cmd->redir_sym[i]) == 1)
		{
			if (!ft_strncmp(">", cmd->redir_sym[i], 1))
				result = handle_outred(cmd->redir_files[i], 0);
			else if (!ft_strncmp("<", cmd->redir_sym[i], 1))
				result = handle_inred(cmd->redir_files[i], 0, NULL);
		}
		else if (ft_strlen(cmd->redir_sym[i]) == 2)
		{
			if (!ft_strncmp(">>", cmd->redir_sym[i], 2))
				result = handle_outred(cmd->redir_files[i], 1);
			else if (!ft_strncmp("<<", cmd->redir_sym[i], 2))
				result = handle_inred(cmd->redir_files[i],
						1, cmd->heredoc_data);
		}
	}
	return (result);
}
