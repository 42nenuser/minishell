/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:43:05 by okamili           #+#    #+#             */
/*   Updated: 2023/06/15 21:02:49 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

static void	export_list_env(void)
{
	t_env	*tmp;

	tmp = g_env;
	while (tmp)
	{
		if (!tmp->hide && tmp->value)
			printf("declare -x %s=\"%s\"\n", tmp->name, tmp->value);
		else if (!tmp->hide)
			printf("declare -x %s\n", tmp->name);
		tmp = tmp->next;
	}
}

static int	check_arg_name(char *arg)
{
	int		i;
	char	*tmp;

	i = -1;
	while (arg && arg[++i])
	{
		if (!((arg[i] >= 'a' && arg[i] <= 'z')
				|| (arg[i] >= 'A' && arg[i] <= 'Z')
				|| ((arg[i] >= '0' && arg[i] <= '9') && i)
				|| arg[i] == '_'))
		{
			tmp = replace_word("Minishell: export: `X': "
					"not a valid identifier\n", "X", arg, 0);
			ft_putstr_fd(tmp, 2);
			free(tmp);
			return (1);
		}
	}
	return (0);
}

static char	*env_name(char *str, int *err, int *code)
{
	int		i;
	char	*tmp;

	i = -1;
	while (str && str[++i])
		if (str[i] == '=')
			break ;
	if (str)
	{
		if (!i)
			i++;
		tmp = ft_substr(str, 0, i);
		*code = check_arg_name(tmp);
		if (*code && !*err)
			*err = 1;
		if (!*code)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

static char	*env_val(char *str, int code)
{
	int	i;
	int	start;
	int	len;

	i = -1;
	len = 0;
	if (code)
		return (NULL);
	while (str && str[++i])
		if (str[i] == '=')
			break ;
	start = i + 1;
	while (str && str[++i])
		len++;
	if (!len && !ft_strchr(str, '='))
		return (NULL);
	return (ft_substr(str, start, len));
}

void	run_export(t_cmd *cmd)
{
	int		i;
	int		code;
	char	*name;
	char	*value;

	if (!cmd->args[1])
		export_list_env();
	i = 0;
	while (cmd->args[++i])
	{
		name = env_name(cmd->args[i], &cmd->error, &code);
		value = env_val(cmd->args[i], code);
		if (name)
			g_env = add_env(g_env, name, value);
		free(name);
		free(value);
	}
}
