/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   agora_vai.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 12:52:54 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 11:50:06 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	int		b_position;

	b_position = get_biggest_position(*stack_a);
	if (b_position == 1)
		ps_commands_rotate(stack_a, stack_b, 6, flags);
	else if (b_position == 2)
	{
		ps_commands_rotate(stack_a, stack_b, 6, flags);
		ps_commands_rotate(stack_a, stack_b, 6, flags);
	}
	if (!is_sorted(*stack_a))
		ps_commands_swap(stack_a, stack_b, 1, flags);
}

int		first_three_order(t_stack *stack)
{
	int first;
	int second;
	int third;

	first = stack->index;
	second = stack->next->index;
	third = stack->next->next->index;
	if (first < second && second < third)
		return (1);
	else if (first < second && second > third && second == (first + 2))
		return (2);
	else if (first < second && second > third && second != (first + 2))
		return (3);
	else if (first > second && second < third && second == (first - 1))
		return (4);
	else if (first > second && second < third && second != (first - 1))
		return (5);
	else if (first > second && second > third)
		return (6);
	return (0);
}

void	sort_three_first(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	int order;

	order = first_three_order(*stack_a);
	if (order == 1)
		return ;
	else if (order == 2)
		sort_case_two(stack_a, stack_b, flags);
	else if (order == 3)
		sort_case_three(stack_a, stack_b, flags);
	else if (order == 4)
		sort_case_four(stack_a, stack_b, flags);
	else if (order == 5)
		sort_case_five(stack_a, stack_b, flags);
	else if (order == 6)
		sort_case_six(stack_a, stack_b, flags);
}

void	set_three_biggest(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	int		best_number;

	best_number = analyse_three_biggest(*stack_b,
	get_biggest_in_stack(*stack_b));
	*stack_b = set_next(*stack_a, *stack_b, best_number, flags);
	ps_commands_push(stack_a, stack_b, 4, flags);
	best_number = analyse_two_biggest(*stack_b,
	get_biggest_in_stack(*stack_b));
	*stack_b = set_next(*stack_a, *stack_b, best_number, flags);
	ps_commands_push(stack_a, stack_b, 4, flags);
	*stack_b = set_next(*stack_a, *stack_b, get_biggest_in_stack(*stack_b),
	flags);
	ps_commands_push(stack_a, stack_b, 4, flags);
}

void	sort_rest(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	int biggest;
	int save_first;

	biggest = get_biggest_in_stack(*stack_a);
	save_first = (*stack_a)->index;
	while ((*stack_a)->index != biggest)
		ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
	ps_commands_rotate(stack_a, stack_b, 6, flags);
	while ((*stack_a)->index != save_first)
		ps_commands_push(stack_a, stack_b, 5, flags);
	while (*stack_b)
	{
		*stack_b = set_biggest_stackb(*stack_a, *stack_b, flags);
		ps_commands_push(stack_a, stack_b, 4, flags);
	}
}
