/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:31:47 by csilva-m          #+#    #+#             */
/*   Updated: 2024/05/31 20:42:22 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum
{
	WORD = 1,
	REDIRECT,
	APPEND,
	PIPE,
	HEREDOC,
	SPACES,
	VAR,
	TRUNC,
	END
}					t_type;

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_token
{
	char			*str;
	int				token;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;

}					t_env;

typedef struct s_redir_in
{
	char				*file_name;
	int					fd;
	t_type				tkn_type;
	// struct s_redir_in	next;
}						t_redir_in;

typedef struct s_redir_out
{
	char				*file_name;
	int					fd;
	t_type				tkn_type;
	// struct s_redir_out	next;
}						t_redir_out;

typedef struct s_cmd
{
	int				fork_pid;
	char			*cmd;
	char			**args;
	char			**envp;
	t_bool			is_builtin;
	t_redir_in		*redir_in;
	t_redir_out		*redir_out;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_core
{
	char			*input;
	t_token			*token;
	t_env			*env_list;
	t_cmd			*cmd;
	char			**env;
	t_list			*garbage;
	t_bool			is_heredoc;
	int				exit_status;
	char			invalid;
	t_cmd			*cmd_table;
	int				number_of_cmds_in_cmd_table; // mudar depois
}					t_core;

// core
t_core				*get_core(void);
void				prompt_loop(void);
void				process(void);
void				ft_translate_type(int type, int i);
void				ft_print_stack(void);
void				error(char *msg, int status, int fd);

//tokenizer
t_token				*create_tkn_lst(char *str, int type);
void				lexing(char *input);
void				add_token(t_token **token, t_token *new);
void				save_words(char *input, int start, int end);
void				save_separator(char *input, int pos, int type);
int					check_token(char *str);

// syntax errors
t_bool				syntax_errors(void);
t_bool				only_spaces(void);
t_bool				check_end_op(void);
t_bool				forbiden_token(void);
t_bool				check_close_quotes(void);
t_bool				check_start_pipe(void);
t_bool				check_op_op(void);
void				split_quotes(char *str, int *i);
void				remove_quote(char *str);

// parser
void				parsing_vars(void);
void				ft_print_env(void);
void				get_env_vars(t_core *core);
void				split_quotes(char *str, int *i);
int					ft_quotes_status(char c, int status);
char				*my_get_env(char *key);
char				*find_var(char *str, int j);

// command table
t_cmd				*create_cmd_table(void);
void				fill_cmd_table(void);
void				handle_cmd_number(void);
void				exec_one_cmd(t_cmd *cmd_table);
void				exec_mult_cmd(int cmd_number);
int					cmd_has_path(char *cmd);
char				*build_path(char *cmd);
t_bool				is_builtin(char *cmd);
char				**cmd_to_matrix(t_token **ptr_token);
char				**env_to_matrix(void);
int					cmd_count(void);

// operators
void				capture_heredoc(void);
void				handle_heredoc(t_token *token, t_redir_in **redir_list);
void				handle_redir_in(t_token *token, t_redir_in **redir_list);
void				add_redir_in(t_redir_in **redir, t_redir_in *new);
void				add_redir_out(t_redir_out **redir, t_redir_out *new);
t_redir_in			*create_redir_in_list(char *file_name, t_type token_type);
t_redir_out			*create_redir_out_list(char *file_name, t_type token_type);
t_bool				validate_redir_in_file(char *file);
t_bool				validate_redir_out_file(char *file);

// exec
void				exec_builtins(char **args);

// clenup
void				clear_tkn_lst(t_token **token);
void				clear_env_lst(t_env **env);
void				garbage_collect(void *ptr);
void				clear_garbage(void);
void				ft_free_matrice(char **matrice);
void				remove_token(t_token **list, t_token *target);
void				clear_child(void);
void				clear_child_exec(void);
void				close_fds(void);

// builtins
void				env(char **argv);
void				exit_shell(void);
void				unset(char **argv);
void				pwd(char **argv);
void				unset(char **argv);
void				cd(char **argv);
void				echo(char **argv);

// signals
void				signal_handler(void);

// utils
int					matrice_len(char **matrice);

// colors
# define COLOR_PINK "\001\x1B[1;35m\002"
# define COLOR_GREEN "\001\x1B[1;32m\002"
# define COLOR_RED "\001\x1B[1;31m\002"
# define COLOR_BLUE "\001\x1B[34m\002"
# define COLOR_YELLOW "\001\x1B[1;33m\002"
# define COLOR_CYAN "\001\x1B[36m\002"
# define COLOR_WHITE "\001\x1B[1;37m\002"
# define COLOR_BLACK "\001\x1B[1;30m\002"
# define COLOR_GRAY "\001\x1B[1;90m\002"
# define COLOR_RESET "\001\x1B\033[0m\002"

#endif
