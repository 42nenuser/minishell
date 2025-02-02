/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:43:26 by okamili           #+#    #+#             */
/*   Updated: 2023/06/01 02:20:03 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_builtin(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	if ((len == 3 && !ft_strncmp("pwd", cmd, 3))
		|| (len == 2 && !ft_strncmp("cd", cmd, 2))
		|| (len == 3 && !ft_strncmp("env", cmd, 3))
		|| (len == 4 && !ft_strncmp("echo", cmd, 4))
		|| (len == 5 && !ft_strncmp("unset", cmd, 5))
		|| (len == 6 && !ft_strncmp("export", cmd, 6))
		|| (len == 4 && !ft_strncmp("exit", cmd, 4)))
		return (1);
	return (0);
}
