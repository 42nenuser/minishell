CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3 -I /Users/yait-oul/.brew/opt/readline/include
RM			=	rm -rf

EXEC		=	dependencies/executions/builtin_export.c dependencies/executions/close_prgm.c\
				dependencies/executions/execute_cmd.c dependencies/executions/execute_pipes.c\
				dependencies/executions/handle_fds.c dependencies/executions/list_env.c\
				dependencies/executions/run_builtins.c

MOD 		=	dependencies/modules/ft_realloc.c dependencies/modules/prompt.c\
				dependencies/modules/free2d.c dependencies/modules/replace_word.c\
				dependencies/modules/replace_all_words.c dependencies/modules/env_controls.c\
				dependencies/modules/env_init.c

PARSING 	=	dependencies/parsing/cmd_tree_ops.c dependencies/parsing/cmd_tree_ops1.c\
				dependencies/parsing/parsing.c dependencies/parsing/input_split.c\
				dependencies/parsing/check_separator.c dependencies/parsing/parse_args.c\
				dependencies/parsing/extract_redirections.c dependencies/parsing/parse_redirections.c\
				dependencies/parsing/replace_variables.c dependencies/parsing/parse_exec.c\
				dependencies/parsing/is_builtin.c dependencies/parsing/heredoc.c

CFILES		=	core.c
PARSINGOBJ	=	$(PARSING:.c=.o)
COBJS		=	$(CFILES:.c=.o)
MODOBJ		=	$(MOD:.c=.o)
EXECOBJ		=	$(EXEC:.c=.o)
LIBFT		=	dependencies/libft/libft.a
NAME		=	minishell

all			:	$(NAME)

$(NAME)		:	$(COBJS) $(PARSINGOBJ) $(MODOBJ) $(EXECOBJ) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(COBJS) $(MODOBJ) $(PARSINGOBJ) $(EXECOBJ) $(LIBFT) -lreadline -L /Users/yait-oul/.brew/opt/readline/lib
$(LIBFT)	:
				cd dependencies/libft && $(MAKE)
clean		:
				$(RM) $(COBJS) $(PARSINGOBJ) $(MODOBJ) $(EXECOBJ)
				cd dependencies/libft && $(MAKE) clean
fclean		:	clean
				$(RM) $(NAME) $(LIBFT)
re			:	fclean all