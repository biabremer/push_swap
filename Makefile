# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bbremer <bbremer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/22 16:48:36 by bbremer        #+#    #+#                 #
#    Updated: 2019/10/28 15:34:57 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

CHECKER = checker.c error_management.c check_sorting.c flag_management.c

CHECKER_PS = error_management.c check_sorting.c flag_management.c

GENERAL_PS = get_commands.c stack_functions.c free.c

GENERAL = apply_commands.c call_commands.c get_commands.c stack_functions.c\
free.c

PUSHSWAP = push_swap.c set_index.c support_stack_functions.c apply_commands.c\
call_commands.c divide_stack.c analytics.c moves.c set_biggest.c\
calculate_commands.c agora_vai.c sort_cases.c copy_stack.c support_functions.c\
support_functions_2.c

LIBFTOBJ = ft_strdup.o ft_strjoin.o ft_itoa.o ft_atoi.o ft_strcat.o\
ft_strcpy.o ft_strdel.o ft_strlen.o ft_strnew.o ft_memdup.o ft_strstr.o\
ft_lstadd.o ft_lstnew.o ft_memset.o ft_putstr_int.o ft_strchr.o ft_strclr.o\
ft_strcmp.o ft_strsub.o ft_whitespace.o ft_ftoa.o ft_itoa_base.o ft_put_pointer.o\
ft_putchar_int.o ft_memcpy.o ft_numlen_base.o ft_putchar.o ft_atof.o ft_strndup.o\
ft_numlen.o ft_strncmp.o ft_memmove.o ft_putstr_fd.o ft_putchar_fd.o ft_atol.o\
get_next_line.o


PRINTFOBJ = handling_c.o handling_di.o handling_f.o handling_o.o\
handling_p.o handling_u.o handling_x.o handling_flags.o\
print_null.o ctostr.o getting_flags.o ft_printf.o getting_fmt.o\
print_parsed_values.o support_functions.o initialise_varargs.o \
handling_precision_width.o\
 

LIBSRC = $(addprefix ./ft_printf/libft/, $(LIBFTOBJ))

PRINTFSRC = $(addprefix ./ft_printf/obj/, $(PRINTFOBJ))

PUSHSWAPSRC = $(addprefix ./pushswap_src/, $(PUSHSWAP))

PSCHECKERSRC = $(addprefix ./checker_src/, $(CHECKER_PS))

PSGENERALSRC = $(addprefix ./general_src/, $(GENERAL_PS))

CHECKERSRC = $(addprefix ./checker_src/, $(CHECKER))

GENERALSRC = $(addprefix ./general_src/, $(GENERAL))

HEADER = checker.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"

all: $(NAME1) $(NAME2)

libraries:
	@echo $(CYAN) "- Compiling Libraries" $(END)
	@make -C ./ft_printf
	@echo $(GREEN) "- Done" $(END)

$(NAME1): libraries
	@echo $(CYAN) "- Compiling $@" $(END)
	@gcc -o $(NAME1) $(PUSHSWAPSRC) $(PSCHECKERSRC) $(PSGENERALSRC) \
	$(LIBSRC) $(PRINTFSRC) -I$(HEADER) -Wall -Wextra -Werror
	@echo $(GREEN) "- Done" $(END)

$(NAME2):
	@echo $(CYAN) "- Compiling $@" $(END)
	@gcc -o $(NAME2) $(CHECKERSRC) $(GENERALSRC) $(LIBSRC) $(PRINTFSRC)\
	 -I $(HEADER) -Wall -Wextra -Werror
	@echo $(GREEN)" - Done" $(END)

clean:
	@echo $(CYAN) "- Deleting objects" $(END)
	@make -C ./ft_printf clean
	@make -C ./pushswap_src clean
	@make -C ./checker_src clean
	@echo $(GREEN)" - Done" $(END)

fclean: clean
	@echo $(CYAN)" - Deleting executables" $(END)
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@make -C ./ft_printf fclean
	@echo $(GREEN)" - Done" $(END)
		
re: fclean all