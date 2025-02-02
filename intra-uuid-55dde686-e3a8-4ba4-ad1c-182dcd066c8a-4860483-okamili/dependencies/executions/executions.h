/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:48:10 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 16:03:38 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTIONS_H
# define EXECUTIONS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../modules/modules.h"
# include "../parsing/parsing.h"

/**
 * @brief Print the current working directory.
 */
void	pwd(void);
/**
 * @brief Navigate to a different working directory.
 * 
 * @param cmd Reference to the node for the cd command.
 */
void	cd(t_cmd *cmd);
/**
 * @brief Output the text to the standard output (STDOUT).
 * 
 * @param cmd Reference to the node for the echo command.
 */
void	echo(t_cmd *cmd);
/**
 * @brief Free allocated memory followed by terminating the program.
 * 
 * @param cmd Reference to the node for the exit command.
 */
void	close_prgm(t_cmd *cmd);
/**
 * @brief Print the list of env variables to standard output (STDOUT).
 */
void	list_env(void);
/**
 * @brief Unset one or more env variable.
 * 
 * @param cmd Reference to the node for the unset command.
 */
void	unset_env(t_cmd *cmd);
/**
 * @brief Either list or define one or more env variable.
 * 
 * @param cmd Reference to the node for the export command.
 */
void	run_export(t_cmd *cmd);
/**
 * @brief Execute built-in commands.
 * 
 * @param cmd Reference to the command node.
 */
void	run_builtins(t_cmd *cmd);
/**
 * @brief Execute system commands.
 * 
 * @param cmd Reference to the command node.
 */
void	run_commands(t_cmd *cmd);
/**
 * @brief Execute commands that are piping to each others.
 * 
 * @param cmds Reference to the first command node.
 * @param err Reference to a variable that will contain the error
 * return code of this execution.
 * @return t_cmd* Reference to the last command node that used pipe.
 */
t_cmd	*run_pipe_commands(t_cmd *cmds, int *err);
/**
 * @brief Redirect data file descriptors according to the specified redirections.
 * 
 * @param cmd Reference to the command node.
 * @return int Error code.
 */
int		handle_redir(t_cmd *cmd);
/**
 * @brief Redirect data file descriptors according to the pipe file descriptors.
 * 
 * @param pfd Pipe file descriptors.
 * @param red[2]: A switch that determines the redirection of which data stream,
 * Set each index to 1 for true or 0 for false.
 * (index0) for input and (index1) for output.
 * @param newpfd another pipe file descriptors
 * if you need the first pipe to redirect to this pipe.
 */
void	handle_fds(int pfd[2], int red[2], int newpfd[2]);
/**
 * @brief A function at a low level that carries out command execution.
 * 
 * @param cmd Reference to the command node.
 * @param pfd Pipe file descriptors.
 * @param red[2]: A switch that determines the redirection of which data stream,
 * Set each index to 1 for true or 0 for false.
 * (index0) for input and (index1) for output.
 * @param newpfd another pipe file descriptors
 * if you need the first pipe to redirect to this pipe.
 */
void	execute_cmd(t_cmd *cmd, int pfd[2], int red[2], int newpfd[2]);

#endif