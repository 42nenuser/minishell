/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 03:06:38 by okamili           #+#    #+#             */
/*   Updated: 2023/06/20 17:49:26 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	sig_handler(int sign)
{
	if (sign == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	struct_execution(t_cmd *head, int *err)
{
	while (head)
	{
		if (head->sep && head->sep[0] == '|')
			head = run_pipe_commands(head, err);
		else
			run_commands(head);
		head = get_next_cmd(head, err);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		err;
	char	*input;
	t_cmd	*cmds;

	env_init(argc, argv, env);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	err = 0;
	while (1)
	{
		input = prompt();
		if (!input)
		{
			printf("\nexit\n");
			close_prgm(NULL);
		}
		add_history(input);
		cmds = input_split(input, &err);
		if (cmds)
			cmds->prev_error = err;
		parsing(cmds);
		free(input);
		struct_execution(cmds, &err);
	}
	return (0);
}
