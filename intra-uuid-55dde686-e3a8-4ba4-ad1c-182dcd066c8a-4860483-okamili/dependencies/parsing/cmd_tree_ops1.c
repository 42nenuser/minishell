/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree_ops1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:25:58 by okamili           #+#    #+#             */
/*   Updated: 2023/06/09 10:26:10 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	*get_next_cmd(t_cmd *head, int *err)
{
	t_cmd	*result;

	if (head->next)
		head->next->prev_error = head->error;
	else
		*err = head->error;
	result = remove_cmd_from_tree(head, head);
	if (result)
		parsing(result);
	return (result);
}

void	erase_cmd_node(t_cmd *cmd_pointer)
{
	if (cmd_pointer)
	{
		free(cmd_pointer->cmd);
		free(cmd_pointer->exec);
		free2d((void **)cmd_pointer->args);
		free2d((void **)cmd_pointer->redir_files);
		free2d((void **)cmd_pointer->redir_sym);
		free(cmd_pointer->sep);
		free(cmd_pointer->heredoc_data);
		free(cmd_pointer);
	}
}

void	free_cmd_tree(t_cmd *head)
{
	while (head)
		head = remove_cmd_from_tree(head, head);
}
