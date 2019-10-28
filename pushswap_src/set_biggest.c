/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_biggest.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 10:51:13 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/24 10:54:04 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_first_last_index(t_stack *stack)
{
	int		first;
	int		last;
	t_stack *temp;

	temp = stack;
	first = temp->index;
	while (temp->next != NULL)
		temp = temp->next;
	last = temp->index;
	if (last < first)
		return (1);
	return (0);
}

t_stack		*set_biggest_stackb(t_stack *stack_a, t_stack *stack_b,
t_flags *flags)
{
	int stack_i;
	int len;

	stack_i = get_biggest_position(stack_b);
	len = stack_len(stack_b);
	if (stack_i > (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rev_rotate(&stack_a, &stack_b, 10, flags);
			stack_i = get_biggest_position(stack_b);
		}
	}
	else if (stack_i <= (len / 2))
	{
		while (stack_i > 1)
		{
			if (stack_i == 2 && !check_first_last_index(stack_b))
				ps_commands_swap(&stack_a, &stack_b, 2, flags);
			else
				ps_commands_rotate(&stack_a, &stack_b, 7, flags);
			stack_i = get_biggest_position(stack_b);
		}
	}
	return (stack_b);
}

t_stack		*set_biggest_stacka(t_stack *stack_a, t_stack *stack_b,
t_flags *flags)
{
	int stack_i;
	int len;

	stack_i = get_biggest_position(stack_a);
	len = stack_len(stack_a);
	if (stack_i > (len / 2))
	{
		while (stack_i > 1)
		{
			ps_commands_rev_rotate(&stack_a, &stack_b, 9, flags);
			stack_i = get_biggest_position(stack_a);
		}
	}
	if (stack_i <= (len / 2))
	{
		while (stack_i > 1)
		{
			if (stack_i == 2 && !check_first_last_index(stack_a))
				ps_commands_swap(&stack_a, &stack_b, 1, flags);
			else
				ps_commands_rotate(&stack_a, &stack_b, 6, flags);
			stack_i = get_biggest_position(stack_a);
		}
	}
	return (stack_a);
}
