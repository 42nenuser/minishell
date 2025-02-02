/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:07:33 by okamili           #+#    #+#             */
/*   Updated: 2023/06/09 16:49:59 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "dependencies/libft/libft.h"
# include "dependencies/parsing/parsing.h"
# include "dependencies/executions/executions.h"
# include <signal.h>

void	sig_handler(int sign);
#endif