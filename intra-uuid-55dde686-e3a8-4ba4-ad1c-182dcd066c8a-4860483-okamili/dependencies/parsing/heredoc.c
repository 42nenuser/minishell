/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:11:48 by okamili           #+#    #+#             */
/*   Updated: 2023/06/20 18:29:30 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../core.h"

static char	*read_heredoc(char *str)
{
	char	*buffer;
	char	*result;
	char	*tmp;

	result = ft_strdup("");
	while (1)
	{
		buffer = readline(">");
		if (!buffer)
		{
			free(result);
			return (NULL);
		}
		if (ft_strlen(buffer) == ft_strlen(str)
			&& !ft_strncmp(str, buffer, ft_strlen(str)))
		{
			free(buffer);
			return (result);
		}
		tmp = ft_strjoin(result, buffer);
		free(result);
		result = ft_strjoin(tmp, "\n");
		free(tmp);
		free(buffer);
	}
}

static char	*extract_data(int pfd[2])
{
	int		len;
	char	*data[2];
	int		index;
	char	*result;

	close(pfd[1]);
	index = 0;
	data[0] = ft_calloc(10, 1);
	read(pfd[0], data[0], 9);
	len = ft_atoi(data[0]);
	while (data[0][index] >= '0' && data[0][index] <= '9')
		index++;
	data[0] += index;
	data[1] = ft_calloc((len - index) + 1, 1);
	read(pfd[0], data[1], (len - index));
	close(pfd[0]);
	result = ft_strjoin(data[0], data[1]);
	data[0] -= index;
	free(data[0]);
	free(data[1]);
	return (result);
}

static void	heredoc_child_work(char *str, int pfd[2])
{
	char	*tmp0;
	char	*tmp1;

	signal(SIGINT, SIG_DFL);
	close(pfd[0]);
	tmp0 = read_heredoc(str);
	tmp1 = ft_itoa(ft_strlen(tmp0));
	write(pfd[1], tmp1, ft_strlen(tmp1));
	write(pfd[1], tmp0, ft_strlen(tmp0));
	close(pfd[1]);
	free(tmp0);
	free(tmp1);
	exit(0);
}

static char	*run_heredoc(char *str, int *err)
{
	int		pfd[2];
	int		status;
	pid_t	child;

	pipe(pfd);
	signal(SIGINT, SIG_IGN);
	child = fork();
	if (!child)
		heredoc_child_work(str, pfd);
	wait(&status);
	signal(SIGINT, sig_handler);
	*err = WEXITSTATUS(status);
	if (WTERMSIG(status) == SIGINT)
		*err = 130;
	return (extract_data(pfd));
}

void	manage_heredoc(t_cmd *cmds)
{
	int		i;
	t_cmd	*tmp;

	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (tmp->redir_sym && tmp->redir_sym[++i])
		{
			if (ft_strlen(tmp->redir_sym[i]) == 2
				&& !ft_strncmp("<<", tmp->redir_sym[i], 2))
			{
				free(tmp->heredoc_data);
				tmp->heredoc_data = run_heredoc(tmp->redir_files[i],
						&(tmp->error));
			}
		}
		tmp = tmp->next;
	}
}
