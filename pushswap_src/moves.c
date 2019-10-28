/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 17:39:35 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 12:00:16 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_next(t_stack *stack_a, t_stack *stack_b, int number,
t_flags *flags)
{
	int stack_i;
	int len;

	len = stack_len(stack_b);
	stack_i = find_index_position(stack_b, number);
	if (stack_i > (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rev_rotate(&stack_a, &stack_b, 10, flags);
			stack_i = find_index_position(stack_b, number);
		}
	}
	else if (stack_i <= (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rotate(&stack_a, &stack_b, 7, flags);
			stack_i = find_index_position(stack_b, number);
		}
	}
	return (stack_b);
}

int		get_smallest_in_stack(t_stack *stack)
{
	t_stack *temp;
	int		smallest;

	smallest = get_biggest_in_stack(stack);
	temp = stack;
	while (temp)
	{
		if (temp->index < smallest)
			smallest = temp->index;
		temp = temp->next;
	}
	return (smallest);
}

int		get_smallest_position(t_stack *stack)
{
	t_stack *temp;
	int		stack_i;

	temp = stack;
	stack_i = 1;
	while (temp->index != get_smallest_in_stack(stack))
	{
		stack_i++;
		temp = temp->next;
	}
	return (stack_i);
}

t_stack	*set_smallest(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	int stack_i;
	int len;

	stack_i = get_smallest_position(stack_b);
	len = stack_len(stack_b);
	if (stack_i > (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rev_rotate(&stack_a, &stack_b, 9, flags);
			stack_i = get_smallest_position(stack_b);
		}
	}
	else if (stack_i <= (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rotate(&stack_a, &stack_b, 6, flags);
			stack_i = get_smallest_position(stack_b);
		}
	}
	return (stack_b);
}

t_stack	*set_smallest_stacka(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	int stack_i;
	int len;

	stack_i = get_smallest_position(stack_a);
	len = stack_len(stack_a);
	if (stack_i > (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rev_rotate(&stack_a, &stack_b, 9, flags);
			stack_i = get_smallest_position(stack_a);
		}
	}
	else if (stack_i <= (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rotate(&stack_a, &stack_b, 6, flags);
			stack_i = get_smallest_position(stack_a);
		}
	}
	return (stack_a);
}
