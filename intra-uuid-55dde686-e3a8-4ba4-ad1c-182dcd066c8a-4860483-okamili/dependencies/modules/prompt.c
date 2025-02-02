/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:41:39 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 18:25:14 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"
#include <fcntl.h>

char	*get_work_dir(void)
{
	char	*home_dir;
	char	*work_dir;
	size_t	work_len;
	size_t	home_len;

	home_dir = fetch("HOME");
	work_dir = getcwd(NULL, 0);
	home_len = ft_strlen(home_dir) - 1;
	work_len = ft_strlen(work_dir);
	if (!work_dir)
		return (NULL);
	if (home_dir && !ft_strncmp(work_dir, home_dir, home_len))
	{
		home_dir = ft_substr(work_dir, home_len, (work_len - home_len));
		home_dir[0] = '~';
		free(work_dir);
		return (home_dir);
	}
	return (work_dir);
}

char	*get_host_name(void)
{
	int		fd;
	char	*buff;

	buff = NULL;
	fd = open("/etc/hostname", O_RDONLY);
	if (fd > 0)
	{
		buff = ft_calloc(1024, 1);
		read(fd, buff, 1024);
	}
	close(fd);
	if (buff && buff[ft_strlen(buff)-1] == '\n')
		buff[ft_strlen(buff) - 1] = '\0';
	return (buff);
}

char	*get_branch_name(void)
{
	int		fd;
	char	**temp;
	char	*result;

	result = NULL;
	fd = open(".git/HEAD", O_RDONLY);
	if (fd > 0)
	{
		result = ft_calloc(1024, 1);
		read(fd, result, 1024);
		close(fd);
	}
	if (result)
	{
		fd = -1;
		temp = ft_split(result, '/');
		free(result);
		while (temp[++fd])
			result = temp[fd];
		result[ft_strlen(result) - 1] = '\0';
		result = replace_all_words(" (b)", "b", result, 0);
		free2d((void **)temp);
	}
	return (result);
}

char	*prompt_msg(void)
{
	char	*host;
	char	*dir;
	char	*branch;
	char	*prompt;

	host = get_host_name();
	dir = get_work_dir();
	branch = get_branch_name();
	prompt = ft_strdup("\001\033[1;32m\002USER@Minishell"
			"\001\033[1;0m\002:\001\033[1;34m\002"
			"D\001\033[1;35m\002B\001\033[1;0m\002$ ");
	if (fetch("USER"))
		prompt = replace_all_words(prompt, "USER", fetch("USER"), 1);
	if (host)
		prompt = replace_all_words(prompt, "Minishell", host, 1);
	free(host);
	prompt = replace_all_words(prompt, "D", dir, 1);
	free(dir);
	prompt = replace_all_words(prompt, "B", branch, 1);
	free(branch);
	return (prompt);
}

char	*prompt(void)
{
	char	*input;
	char	*prompt_txt;

	prompt_txt = prompt_msg();
	input = readline(prompt_txt);
	free(prompt_txt);
	return (input);
}
