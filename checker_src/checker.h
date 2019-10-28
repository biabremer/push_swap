/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 18:32:24 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/28 14:35:23 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/includes/ft_printf.h"

typedef struct			s_commands
{
	int					command;
	struct s_commands	*next;
}						t_commands;

typedef struct			s_stack
{
	int					number;
	int					index;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_flags
{
	int					debug;
	int					movements;
	int					nonsort;
}						t_flags;

int						check_integers(char *str);
int						check_double_value(int *stack, int number, int index);
int						error_checks(char *str, int argc);
int						error_input_management(int argc, char **argv);
t_stack					*apply_swap(t_stack *stack);
void					commands_swap(t_stack **stack_a, t_stack **stack_b,
						int command);
void					apply_push(t_stack ***stack_1, t_stack ***stack_2);
t_stack					*delete_first_stack(t_stack *stack);
t_stack					*push_stack(t_stack *stack, t_stack *new);
void					print_stack(t_stack *stack);
t_stack					*new_int(int number, int index);
void					commands_rotate(t_stack **stack_a, t_stack **stack_b,
						int command);
void					commands_rev_rotate(t_stack **stack_a,
						t_stack **stack_b, int command);
t_stack					*apply_rotate(t_stack *stack);
void					apply_rev_rotate(t_stack **stack);
void					*add_stack(t_stack **begin, t_stack *new);
t_stack					*stack_maker(char **argv);
void					add_commands(t_commands **commands, char *str);
void					get_commands(t_commands **commands);
t_commands				*new_command(char *str);
int						get_command_id(char *str);
void					print_commands(t_commands *commands);
void					apply_commands(t_commands *com, t_stack **stack_a,
						t_stack **stack_b);
t_flags					*get_flags(char **argv);
int						check_flags(char *str);
void					apply_flagv(t_stack *stack_a, t_stack *stack_b);
void					apply_flagc(t_stack *stack_a, t_stack *stack_b,
						t_commands *commands);
int						check_sorting(t_stack *stack_a, t_stack *stack_b);
void					free_stack(t_stack **stack);
void					free_commands(t_commands **commands);
void					print_stacks(t_stack *stack_a, t_stack *stack_b);
int						count_movements(void);
void					execute_flags(t_stack *stack_a, t_flags *flags);
void					print_flags(t_flags *flags);
int						stack_len(t_stack *stack);

#endif
