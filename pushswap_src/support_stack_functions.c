/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   support_stack_functions.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:46:34 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 11:51:47 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_biggest_position(t_stack *stack)
{
	t_stack *temp;
	int		stack_i;

	temp = stack;
	stack_i = 1;
	while (temp->index != get_biggest_in_stack(stack))
	{
		stack_i++;
		temp = temp->next;
	}
	return (stack_i);
}

int		get_biggest_in_stack(t_stack *stack)
{
	t_stack *temp;
	int		biggest;

	biggest = 1;
	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index > biggest)
			biggest = temp->index;
		temp = temp->next;
	}
	if (temp->index > biggest)
		biggest = temp->index;
	return (biggest);
}

int		check_index_in_stack(t_stack *stack, int index)
{
	t_stack *temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index == index)
			return (1);
		temp = temp->next;
	}
	if (temp->index == index)
		return (1);
	return (0);
}

int		is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_smallest(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	*stack_a = set_smallest_stacka(*stack_a, *stack_b, flags);
	ps_commands_push(stack_a, stack_b, 5, flags);
}
