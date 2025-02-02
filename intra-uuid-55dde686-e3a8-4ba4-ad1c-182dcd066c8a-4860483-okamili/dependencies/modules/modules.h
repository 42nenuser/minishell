/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:49:02 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 20:59:10 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULES_H
# define MODULES_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct env_vars
{
	char			*name;
	char			*value;
	int				hide;
	struct env_vars	*next;
}	t_env;

/**
 * @brief A global variable that stores the reference to
 * the linked list encompassing all environment variables.
 */
extern t_env	*g_env;
/**
 * @brief Modify the size of a previously allocated memory.
 * 
 * @param ptr Pointer to the memory block that you wish to resize.
 * @param size The new memory size.
 * @return void* Pointer to a newly allocated memory block with the updated size.
 */
void	*ft_realloc(void *ptr, size_t size);
/**
 * @brief Retrieve the value of an environment variable by its name.
 * 
 * @param var_name The identifier/name of the environment variable.
 * @return char* The corresponding value of that environment variable.
 */
char	*fetch(char *var_name);
/**
 * @brief Obtain the path of the current working directory,
 * replacing the home path with the tilde character ('~').
 * 
 * @return char* string that holds the working directory path.
 */
char	*get_work_dir(void);
/**
 * @brief Retrieve the host name.
 * 
 * @return char* string that holds the host name.
 */
char	*get_host_name(void);
/**
 * @brief Retrieve the git branch name.
 * 
 * @return char* string that holds the branch name.
 */
char	*get_branch_name(void);
/**
 * @brief Create the prompt message.
 * 
 * @return char* string that stores the prompt message.
 */
char	*prompt_msg(void);
/**
 * @brief Display the prompt message, followed by an input field.
 * 
 * @return char* The input provided by the user.
 */
char	*prompt(void);
/**
 * @brief Replace the first occurrence of a matching word in a string.
 * 
 * @param str Pointer to the string.
 * @param w0 The word that is to be replaced.
 * @param w1 The word that is to be used as the replacement.
 * @param usefree Deallocate the memory for the original string.
 * Set it to 1 for true or 0 for false.
 * @return char* Pointer to a new string with the replaced word.
 */
char	*replace_word(char *str, char *w0, char *w1, int usefree);
/**
 * @brief Replace all occurrence of a matching word in a string.
 * 
 * @param str Pointer to the string.
 * @param w0 The word that is to be replaced.
 * @param w1 The word that is to be used as the replacement.
 * @param usefree Deallocate the memory for the original string.
 * Set it to 1 for true or 0 for false.
 * @return char* Pointer to a new string with the replaced words.
 */
char	*replace_all_words(char *str, char *w0, char *w1, int usefree);
/**
 * @brief Add or modify an environment variable in the t_env linked list.
 * 
 * @param head Reference to the head node of the linked list.
 * @param name Variable name.
 * @param value Variable value.
 * @return t_env* Reference to the head node of the linked list.
 */
t_env	*add_env(t_env *head, char *name, char *value);
/**
 * @brief Locate the final node in the t_env linked list.
 * 
 * @param head Reference to the head node of the linked list.
 * @return t_env* Reference to the last node of the linked list.
 */
t_env	*last_env(t_env *head);
/**
 * @brief Find a t_env node based on its name.
 * 
 * @param head Reference to the head node of the linked list.
 * @param name Variable name.
 * @return t_env* Reference to the desired node in the linked list.
 */
t_env	*find_env(t_env *head, char *name);
/**
 * @brief Destroy the t_env linked list along with its associated memory.
 * 
 * @param head Reference to the head node of the linked list.
 */
void	destory_all_env(t_env *head);
/**
 * @brief Deallocate a two-dimensional array.
 * 
 * @param ptr Pointer to the array.
 */
void	free2d(void **ptr);
/**
 * @brief Initialize the linked list for environment variables.
 * 
 * @param argc Arguments counts.
 * @param argv Arguments values.
 * @param env Environment variables.
 */
void	env_init(int argc, char **argv, char **env);
/**
 * @brief Export the linked list of environment variables
 * into a two-dimensional array of strings.
 * 
 * @return char** Two-dimensional array that contains the variables.
 */
char	**export_env(void);

#endif