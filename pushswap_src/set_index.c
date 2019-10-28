/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 17:18:12 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 13:56:47 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smaller_int(t_stack *stack)
{
	int		smaller;
	t_stack *temp;

	temp = stack;
	smaller = temp->number;
	while (temp->next != NULL)
	{
		if (temp->number < smaller)
			smaller = temp->number;
		temp = temp->next;
	}
	if (temp->number < smaller)
		smaller = temp->number;
	return (smaller);
}

int			find_biggest_int(t_stack *stack)
{
	int		biggest;
	t_stack *temp;

	temp = stack;
	biggest = temp->number;
	while (temp->next != NULL)
	{
		if (temp->number > biggest)
			biggest = temp->number;
		temp = temp->next;
	}
	if (temp->number > biggest)
		biggest = temp->number;
	return (biggest);
}

static int	find_next_biggest_int(t_stack *stack, int big)
{
	int		biggest;
	t_stack *temp;

	temp = stack;
	biggest = find_smaller_int(stack);
	while (temp->next != NULL)
	{
		if (temp->number > biggest && temp->number < big)
			biggest = temp->number;
		temp = temp->next;
	}
	if (temp->number > biggest && temp->number < big)
		biggest = temp->number;
	return (biggest);
}

t_stack		*set_index(t_stack *stack)
{
	int		index;
	t_stack *temp;
	int		biggest;

	index = stack_len(stack);
	biggest = find_biggest_int(stack);
	while (index > 0)
	{
		temp = stack;
		while (temp->number != biggest)
			temp = temp->next;
		temp->index = index;
		biggest = find_next_biggest_int(stack, biggest);
		index--;
	}
	return (stack);
}

void		sort_stack_middle(t_stack **stack_a, t_stack **stack_b,
			t_flags *flags, int *partitions)
{
	int sorted_index;
	int	i;

	sorted_index = 3;
	i = 0;
	while (stack_len(*stack_b) > 3)
	{
		if (partitions[i] - partitions[i - 1] == 3)
		{
			push_three_stacka(stack_a, stack_b, flags);
			partitions[i] = 0;
			i--;
		}
		if (stack_len(*stack_a) - sorted_index == 3)
		{
			sort_three_first(stack_a, stack_b, flags);
			sorted_index = sorted_index + 3;
		}
		else
		{
			set_three_biggest(stack_a, stack_b, flags);
			partitions[i] = partitions[i] - 3;
		}
	}
}
