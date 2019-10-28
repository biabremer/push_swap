/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 17:12:26 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 13:10:16 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../checker_src/checker.h"

int		stack_len(t_stack *stack);
t_stack	*set_index(t_stack *stack);
void	print_ps_commands(int command);
int		get_biggest_position(t_stack *stack);
void	ps_commands_rotate(t_stack **stack_a, t_stack **stack_b, int command,
		t_flags *flags);
void	ps_commands_rev_rotate(t_stack **stack_a, t_stack **stack_b,
		int command, t_flags *flags);
void	ps_commands_swap(t_stack **stack_a, t_stack **stack_b, int command,
		t_flags *flags);
void	ps_commands_push(t_stack **stack_a, t_stack **stack_b, int command,
		t_flags *flags);
int		get_smallest_in_stack(t_stack *stack);
int		get_biggest_in_stack(t_stack *stack);
t_stack	*set_smallest(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
t_stack	*set_biggest_stacka(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
t_stack	*set_biggest_stackb(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
int		find_index_position(t_stack *stack, int next);
void	calc_commands_rotate(t_stack **stack_a, t_stack **stack_b, int command);
void	calc_commands_rev_rotate(t_stack **stack_a, t_stack **stack_b,
		int command);
t_stack *set_next(t_stack *stack_a, t_stack *stack_b, int number,
		t_flags *flags);
t_stack *copy_stack(t_stack *stack);
int		push_stack_b(t_stack **stack_a, t_stack **stack_b, int index,
		t_flags *flags);
int		is_sorted(t_stack *stack);
int		calculate_set_number(t_stack *stack, int number);
void	set_three_biggest(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
int		analyse_three_biggest(t_stack *stack, int biggest);
int		analyse_two_biggest(t_stack *stack, int biggest);
int		find_best_move(int first, int second, int third);
void	sort_three_first(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
int		first_three_order(t_stack *stack_a);
void	sort_case_two(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	sort_case_three(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	sort_case_four(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	sort_case_five(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	sort_case_six(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
int		check_index_in_stack(t_stack *stack, int index);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	push_unsorted_numbers(t_stack **stack_a, t_stack **stack_b, int index,
		t_flags *flags);
void	sort_rest(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	sort_advanced_stack(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags, int *partitions);
void	sort_middle_stack(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	sort_simple_stack(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	sort_three(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	apply_rev_rotate_test(t_stack **stack);
void	initialise_flags(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
void	push_swap(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
t_stack	*set_smallest_stacka(t_stack *stack_a, t_stack *stack_b,
		t_flags *flags);
void	push_smallest(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
int		get_smallest_position(t_stack *stack);
int		check_stack_division(t_stack *stack, int medium);
int		check_stacka_division(t_stack *stack, int medium);
int		get_sorted_index(t_stack *stack);
void	push_partition_stacka(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags, int min);
void	push_three_stacka(t_stack **stack_a, t_stack **stack_b, t_flags *flags);
int		find_partitions_index(int *partitions);
int		get_sorted_index(t_stack *stack);
void	sort_stack_middle(t_stack **stack_a, t_stack **stack_b, t_flags *flags,
		int *partitions);
int		push_medium_stacka(t_stack **stack_a, t_stack **stack_b, t_flags *flags,
		int *partitions);
int		push_medium_stackb(t_stack **stack_a, t_stack **stack_b, t_flags *flags,
		int sorted_index);
int		push_medium_stacka_to_stackb(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags, int *partitions);

#endif
