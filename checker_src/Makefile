# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bbremer <bbremer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/28 14:51:26 by bbremer        #+#    #+#                 #
#    Updated: 2019/07/22 19:20:15 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = checker
CHECKER = checker.c error_management.c check_sorting.c flag_management.c
GENERAL = apply_commands.c call_commands.c get_commands.c stack_functions.c\
free.c
LIBFTOBJ = ft_strdup.o ft_strjoin.o ft_itoa.o ft_atoi.o ft_printf.o ft_strcat.o\
ft_strcpy.o ft_strdel.o ft_strlen.o ft_strnew.o get_next_line.o ctostr.o\
ft_lstadd.o ft_lstnew.o ft_memset.o ft_putstr_int.o ft_strchr.o ft_strclr.o\
ft_strcmp.o ft_strsub.o ft_whitespace.o getting_fmt.o ft_ftoa.o ft_itoa_base.o\
handling_c.o handling_di.o handling_f.o handling_o.o ft_memdup.o ft_strstr.o\
handling_p.o handling_u.o handling_x.o ft_put_pointer.o ft_putchar_int.o\
ft_memcpy.o ft_numlen_base.o ft_putchar.o print_null.o print_parsed_values.o\
support_functions.o initialise_varargs.o handling_precision_width.o ft_atof.o\
ft_strndup.o handling_flags.o getting_flags.o ft_numlen.o ft_strncmp.o\
ft_memmove.o ft_strlchr.o ft_putstr_fd.o ft_putchar_fd.o ft_atol.o
OBJ = $(CHECKER:.c=.o)
LIBSRC = $(addprefix ../ft_printf/, $(LIBFTOBJ))
CHECKERSRC = $(addprefix checker_src/, $(CHECKER))
GENERALSRC = $(addprefix ../general_src/, $(GENERAL))
HEADER = checker.h
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		make re -C ../ft_printf
		gcc -o $(NAME) $(CHECKER) $(GENERALSRC) $(LIBSRC) -I$(HEADER) \
		-Wall -Wextra -Werror

clean:
		@rm -f $(OBJ)
		@make -C ../ft_printf/ clean

fclean: clean
		@rm -f $(NAME)
		@make -C ../ft_printf/ fclean

re: fclean all