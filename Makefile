
CC = clang
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
NAME = minishell

CFILES = \
	src/main.c \
	src/builtins/builtins.c \
	src/builtins/cd.c \
	src/builtins/pwd.c \
	src/cosmetic/colours.c \
	src/cosmetic/cosmetic.c \
	src/dealloc/dealloc_exec_list.c \
	src/dealloc/dealloc_lambda.c \
	src/dealloc/dealloc_ptr_array.c \
	src/debug/debug_env.c \
	src/debug/debug_print.c \
	src/env/env_utils.c \
	src/env/env.c \
	src/env/expand_env_variables.c \
	src/error/error.c \
	src/exec/cmd.c \
	src/exec/exec_list.c \
	src/exec/exec.c \
	src/exec/path.c \
	src/redirections/is_ambiguous_redirect.c \
	src/redirections/mark_ambiguous_redirects.c \
	src/tokenizer/get_token.c \
	src/tokenizer/subtokenizers.c \
	src/tokenizer/tokenize.c

HEADERS = \
	include/minishell.h \
	include/prototypes.h \
	include/splash.h \
	include/structs.h

OFILES = $(CFILES:.c=.o)

LIBFT_PATH = libft/libft.a

LIB = -L libft -l ft
ifeq ($(shell uname), Linux)
LIB += -l readline
else
LIB += -L $(shell brew --prefix readline)/lib -lreadline
INCLUDES += -I $(shell brew --prefix readline)/include
endif

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OFILES) $(LIB) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_PATH):
	$(MAKE) -C libft/

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@echo "DEEP CLEANING"

clean:
	$(MAKE) -C libft/ fclean
	@rm -f $(OFILES)
	@echo "CLEANED UP"

.PHONY: all re fclean clean
