HIDE	=	@
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g -I. -I./$(INCDIR)
RFLAGS	=	-lreadline -lhistory

RM		=	rm -rf

NAME	=	minishell
LIBFT	=	libft/libft.a

SRCDIR	=	src/
LEXER	=	lexer/
PARSER	=	parser/
CLEAR	=	clear/
INIT	=	init/
BUILTINS=	builtins/
PROMPT	=	prompt/
SIGNALS	=	signals/
OPERATORS=	operators/
EXEC	=	exec/

SRCS	=	$(SRCDIR)main.c \
			$(SRCDIR)$(LEXER)tokenizer.c \
			$(SRCDIR)$(LEXER)tokenizer_checker.c \
			$(SRCDIR)$(LEXER)syntax_error.c \
			$(SRCDIR)$(CLEAR)clear.c \
			$(SRCDIR)$(CLEAR)error.c \
			$(SRCDIR)$(CLEAR)clear_redir.c \
			$(SRCDIR)$(CLEAR)clear_aux.c \
			$(SRCDIR)$(INIT)init_env.c \
			$(SRCDIR)$(LEXER)expansion.c \
			$(SRCDIR)$(LEXER)expansion_utils.c \
			$(SRCDIR)$(LEXER)quotes.c \
			$(SRCDIR)$(BUILTINS)env.c \
			$(SRCDIR)$(BUILTINS)unset.c \
			$(SRCDIR)$(BUILTINS)pwd.c \
			$(SRCDIR)$(BUILTINS)echo.c \
			$(SRCDIR)$(BUILTINS)cd.c \
			$(SRCDIR)$(BUILTINS)export.c \
			$(SRCDIR)$(BUILTINS)export_utils.c \
			$(SRCDIR)$(BUILTINS)exit.c \
			$(SRCDIR)$(PROMPT)prompt_loop.c \
			$(SRCDIR)$(PROMPT)process.c \
			$(SRCDIR)$(SIGNALS)signals.c \
			$(SRCDIR)$(SIGNALS)signal_handler.c \
			$(SRCDIR)$(SIGNALS)signals_heredoc.c \
			$(SRCDIR)$(OPERATORS)validate_files.c \
			$(SRCDIR)$(EXEC)executions.c \
			$(SRCDIR)$(EXEC)executions_utils.c \
			$(SRCDIR)$(EXEC)exit_status_executions.c \
			$(SRCDIR)$(EXEC)exec_builtins.c \
			$(SRCDIR)$(EXEC)check_redirects.c \
			$(SRCDIR)$(PARSER)cmd_parse.c \
			$(SRCDIR)$(PARSER)cmd_parse_utils.c \
			$(SRCDIR)$(PARSER)cmd_parse_redir.c \
			$(SRCDIR)$(PARSER)build_path.c \
			$(SRCDIR)$(OPERATORS)redirect.c \
			$(SRCDIR)$(OPERATORS)heredoc.c \
			$(SRCDIR)$(OPERATORS)heredoc_expansion.c \
			$(SRCDIR)$(OPERATORS)redirect_utils.c \
			$(SRCDIR)$(OPERATORS)validate_files_utils.c 


OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

INCDIR	=	includes/
INC		=	$(INCDIR)minishell.h


all: $(OBJDIR) $(OBJS) $(LIBFT) $(NAME)

$(LIBFT):
	$(HIDE)make -C ./libft --no-print-directory

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)mkdir -p $(dir $@)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(HIDE)$(CC) $(OBJS) $(LIBFT) -I libft $(CFLAGS) $(RFLAGS) -o $@


$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)make -C libft clean
	$(HIDE)$(RM) $(OBJDIR)

fclean: clean
	$(HIDE)make -C libft fclean
	$(HIDE)$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
