/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:50:54 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 20:59:41 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../modules/modules.h"

typedef struct cmd_data
{
	char			*cmd;
	char			*exec;
	char			**args;
	char			**redir_files;
	char			**redir_sym;
	char			*sep;
	char			*heredoc_data;
	int				error;
	int				prev_error;
	pid_t			process_id;
	struct cmd_data	*next;
}	t_cmd;

/**
 * @brief Generate a new node to store command information.
 * 
 * @param whole_command The command initially inputted by the user.
 * @return t_cmd* Reference to a node that holds that command information.
 */
t_cmd	*allocate_cmd_node(char *whole_command);
/**
 * @brief Locate the final node within the t_cmd tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @return t_cmd* Reference to the last node.
 */
t_cmd	*last_cmd_node(t_cmd *head);
/**
 * @brief Locate the node that is pointing to your current node.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @param current_node Reference to current node.
 * @return t_cmd* Reference to the located node.
 */
t_cmd	*previous_cmd_node(t_cmd *head, t_cmd *current_node);
/**
 * @brief Add a node to the final element of the t_cmd tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @param new_command Reference to the node you intend to add.
 * @return t_cmd* The reference to the root node of the tree.
 */
t_cmd	*append_cmd_to_tree(t_cmd *head, t_cmd *new_command);
/**
 * @brief Delete and destroy a node from the t_cmd tree,
 * regardless of whether or not it exists in the tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @param todelete eference to the node you intend to delete.
 * @return t_cmd* The reference to the root node of the tree.
 */
t_cmd	*remove_cmd_from_tree(t_cmd *head, t_cmd *todelete);
/**
 * @brief Destroy a t_cmd node.
 * 
 * @param cmd_pointer Reference to the node you intend to destroy.
 */
void	erase_cmd_node(t_cmd *cmd_pointer);
/**
 * @brief Remove all nodes within a t_cmd tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 */
void	free_cmd_tree(t_cmd *head);
/**
 * @brief Divide the user input into multiple t_cmd nodes.
 * 
 * @param input input User input.
 * @param err Reference to a variable for storing the last error code.
 * @return t_cmd* Reference to the t_cmd tree.
 */
t_cmd	*input_split(char *input, int *err);
/**
 * @brief Check the separator between each command node.
 * 
 * @param cmd Reference to the beginning of the t_cmd tree.
 * @return int (1) for incorrect separator and (0) for success.
 */
int		check_separator(t_cmd *cmd);
/**
 * @brief Extract the arguments from the command.
 * 
 * @param cmd Pointer to the command.
 * @return char** Pointer to a 2D array containing the arguments.
 */
char	**parse_args(char *cmd);
/**
 * @brief Extracts both redirection symbols and files from the given command.
 * 
 * @param cmd Pointer to the command.
 * @return char** Pointer to a 2D array containing the extracted redirections.
 */
char	**extract_redir(char *cmd);
/**
 * @brief Checks if an executable is built-in.
 * 
 * @param exec String containing the executable.
 * @return int (1) if the executable is built-in, and (0) otherwise.
 */
int		is_builtin(char *exec);
/**
 * @brief Retrieves the relative path of the executable.
 * 
 * @param exec String containing the executable.
 * @return char* String containing the relative path.
 */
char	*get_relative_path(char *exec);
/**
 * @brief Retrieves the absolute path of the executable.
 * 
 * @param exec String containing the executable.
 * @return char* String containing the absolute path.
 */
char	*get_absolute_path(char *exec);
/**
 * @brief Retrieves the executable from the command.
 * 
 * @param cmd Pointer to the command.
 * @param err Reference to a variable for storing the error code.
 * @return char* String containing the executable.
 */
char	*parse_exec(char *cmd, int *err);
/**
 * @brief Removes the outer layer of quotes from a string.
 * 
 * @param str Pointer to the string.
 * @return char* Pointer to the new string.
 */
char	*clean_quotes(char *str);
/**
 * @brief Populates the redirection data in the t_cmd node.
 * 
 * @param cmd Reference to the t_cmd node.
 */
int		parse_redir(t_cmd *cmd);
/**
 * @brief Populates all elements in the t_cmd node.
 * 
 * @param cmd Reference to the t_cmd node.
 */
void	parsing(t_cmd *cmd);
/**
 * @brief Replace all environment variables in a string
 * with their respective values.
 * 
 * @param str Pointer to the string.
 * @param err The error code of the last command,
 * which will be used to replace the variable "$?".
 * @return char* Pointer to a new string with the environment variables
 * replaced by their corresponding values.
 */
char	*replace_variables(char *str, int err);
/**
 * @brief Delete the current node and obtain the next
 * command node with all data fields populated.
 * 
 * @param head Reference to the t_cmd node.
 * @param err Storage location for the error code
 * of the last command node in the t_cmd.
 * @return t_cmd* The subsequent command node.
 */
t_cmd	*get_next_cmd(t_cmd *head, int *err);
void	manage_heredoc(t_cmd *cmds);

#endif