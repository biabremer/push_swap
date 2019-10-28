/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   support_functions_2.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/05 12:02:22 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 13:08:47 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_sorted_index(t_stack *stack)
{
	t_stack *temp;
	int		sorted_index;

	temp = stack;
	sorted_index = 0;
	while (temp->next != NULL)
	{
		if (temp->next->index - temp->index != 1)
			sorted_index = 0;
		else
			sorted_index++;
		temp = temp->next;
	}
	temp = temp->next;
	if (get_biggest_position(stack) == stack_len(stack))
		sorted_index++;
	return (sorted_index);
}

int		push_medium_stacka(t_stack **stack_a, t_stack **stack_b, t_flags *flags,
		int *partitions)
{
	int	big;
	int	medium;
	int	rotate_index;
	int	i;

	big = get_biggest_in_stack(*stack_b);
	rotate_index = 0;
	i = find_partitions_index(partitions);
	medium = (big + partitions[i - 1]) / 2;
	while (!check_stacka_division(*stack_b, medium))
	{
		if ((*stack_b)->index > medium)
			ps_commands_push(stack_a, stack_b, 4, flags);
		else
		{
			ps_commands_rotate(stack_a, stack_b, 7, flags);
			rotate_index++;
		}
	}
	while (rotate_index > 0)
	{
		ps_commands_rev_rotate(stack_a, stack_b, 10, flags);
		rotate_index--;
	}
	return (medium);
}

int		push_medium_stackb(t_stack **stack_a, t_stack **stack_b, t_flags *flags,
		int i)
{
	int	big;
	int	med;
	int	min;
	int	rotate_index;

	big = get_biggest_in_stack(*stack_a) - i;
	min = get_smallest_in_stack(*stack_a);
	rotate_index = 0;
	med = (big + min) / 2;
	while (!check_stack_division(*stack_a, med) && stack_len(*stack_a) - i != 3)
	{
		if ((*stack_a)->index <= med)
			ps_commands_push(stack_a, stack_b, 5, flags);
		else
		{
			ps_commands_rotate(stack_a, stack_b, 6, flags);
			rotate_index++;
		}
	}
	while (rotate_index > 0)
	{
		ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
		rotate_index--;
	}
	return (med);
}

int		push_medium_stacka_to_stackb(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags, int *partitions)
{
	int	sorted_i;
	int	i;

	i = find_partitions_index(partitions);
	sorted_i = get_sorted_index(*stack_a);
	while (stack_len(*stack_a) - sorted_i > 3)
	{
		i++;
		partitions[i] = push_medium_stackb(stack_a, stack_b, flags,
		sorted_i);
	}
	sort_three_first(stack_a, stack_b, flags);
	return (i);
}

void	sort_advanced_stack(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags, int *partitions)
{
	int	sorted_i;
	int	i;

	i = find_partitions_index(partitions);
	while (stack_len(*stack_b) > 3 || sorted_i != stack_len(*stack_a))
	{
		sorted_i = get_sorted_index(*stack_a);
		if (stack_len(*stack_a) - sorted_i > 3)
			i = push_medium_stacka_to_stackb(stack_a, stack_b, flags,
			partitions);
		else if (stack_len(*stack_a) - sorted_i <= 3)
			sort_three_first(stack_a, stack_b, flags);
		if (partitions[i] - partitions[i - 1] <= 3)
		{
			push_partition_stacka(stack_a, stack_b, flags, partitions[i - 1]);
			partitions[i] = 0;
			i--;
		}
		else if (partitions[i] - partitions[i - 1] > 3 &&
		partitions[i] > partitions[i - 1])
			partitions[i] = push_medium_stacka(stack_a, stack_b, flags,
			partitions);
	}
}
