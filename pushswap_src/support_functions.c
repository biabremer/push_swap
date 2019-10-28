/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   support_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/05 11:54:27 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 12:08:11 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_unsorted_numbers(t_stack **stack_a, t_stack **stack_b, int index,
t_flags *flags)
{
	if (check_index_in_stack(*stack_a, index))
	{
		while ((*stack_a)->index != index)
			ps_commands_rotate(stack_a, stack_b, 6, flags);
	}
	else
	{
		while ((*stack_a)->index != index + 1)
			ps_commands_rotate(stack_a, stack_b, 6, flags);
	}
}

int		find_index_position(t_stack *stack, int next)
{
	int		index;
	t_stack *temp;

	temp = stack;
	index = 1;
	while (temp->index != next)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

void	push_partition_stacka(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags, int min)
{
	while (!check_stacka_division(*stack_b, min))
		ps_commands_push(stack_a, stack_b, 4, flags);
}

void	push_three_stacka(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	ps_commands_push(stack_a, stack_b, 4, flags);
	ps_commands_push(stack_a, stack_b, 4, flags);
	ps_commands_push(stack_a, stack_b, 4, flags);
}

int		find_partitions_index(int *partitions)
{
	int i;

	i = 1;
	while (partitions[i] > 0)
	{
		i++;
	}
	i--;
	return (i);
}
