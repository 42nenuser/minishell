/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:52:06 by okamili           #+#    #+#             */
/*   Updated: 2023/06/09 10:25:56 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	*allocate_cmd_node(char *whole_command)
{
	t_cmd	*result;

	result = ft_calloc(1, sizeof(t_cmd));
	result->cmd = whole_command;
	return (result);
}

t_cmd	*last_cmd_node(t_cmd *head)
{
	if (head)
	{
		while (head->next)
			head = head->next;
	}
	return (head);
}

t_cmd	*previous_cmd_node(t_cmd *head, t_cmd *current_node)
{
	while (head && head->next != current_node)
		head = head->next;
	return (head);
}

t_cmd	*append_cmd_to_tree(t_cmd *head, t_cmd *new_command)
{
	if (head)
	{
		last_cmd_node(head)->next = new_command;
		return (head);
	}
	return (new_command);
}

t_cmd	*remove_cmd_from_tree(t_cmd *head, t_cmd *todelete)
{
	t_cmd	*temp;

	temp = previous_cmd_node(head, todelete);
	if (temp)
		temp->next = todelete->next;
	else
		head = todelete->next;
	erase_cmd_node(todelete);
	return (head);
}
