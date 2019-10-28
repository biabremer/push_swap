/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 12:55:29 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 12:00:44 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_medium(t_stack *stack)
{
	int medium;
	int	small;
	int	big;

	big = get_biggest_in_stack(stack);
	small = get_smallest_in_stack(stack);
	medium = (big + small) / 2;
	return (medium);
}

int			check_stack_division(t_stack *stack, int medium)
{
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		if (temp->index < medium)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			check_stacka_division(t_stack *stack, int medium)
{
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		if (temp->index > medium)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			push_stack_b(t_stack **stack_a, t_stack **stack_b, int index,
t_flags *flags)
{
	t_stack *temp;
	int		len;
	int		medium;

	temp = *stack_a;
	len = stack_len(*stack_a);
	if (index)
		medium = find_medium(*stack_a);
	else
		medium = len / 2;
	index = len / 2;
	while (!check_stack_division(*stack_a, medium) && stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index <= medium &&
		(*stack_a)->index < get_biggest_in_stack(*stack_a) - 2)
			ps_commands_push(stack_a, stack_b, 5, flags);
		else
			ps_commands_rotate(stack_a, stack_b, 6, flags);
	}
	return (medium);
}

void		push_biggest(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	while (*stack_b)
	{
		*stack_b = set_biggest_stackb(*stack_a, *stack_b, flags);
		ps_commands_push(stack_a, stack_b, 4, flags);
	}
}
