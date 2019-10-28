/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 17:17:17 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 13:56:38 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple_stack(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	while (stack_len(*stack_a) > 3)
	{
		*stack_a = set_biggest_stacka(*stack_a, *stack_b, flags);
		ps_commands_push(stack_a, stack_b, 5, flags);
	}
	sort_three(stack_a, stack_b, flags);
	while (*stack_b)
	{
		*stack_b = set_smallest(*stack_a, *stack_b, flags);
		ps_commands_push(stack_a, stack_b, 4, flags);
		ps_commands_rotate(stack_a, stack_b, 6, flags);
	}
}

void	new_push_swap_advanced(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags)
{
	int *partitions;
	int i;

	partitions = malloc(1000 * sizeof(*partitions));
	partitions[1] = push_stack_b(stack_a, stack_b, 0, flags);
	i = 2;
	while (stack_len(*stack_a) > 3)
	{
		partitions[i] = push_stack_b(stack_a, stack_b, partitions[i - 1],
		flags);
		i++;
	}
	sort_three(stack_a, stack_b, flags);
	sort_advanced_stack(stack_a, stack_b, flags, partitions);
	free(partitions);
}

void	new_push_swap_middle(t_stack **stack_a, t_stack **stack_b,
		t_flags *flags)
{
	int *partitions;
	int i;

	partitions = malloc(10 * sizeof(*partitions));
	partitions[1] = push_stack_b(stack_a, stack_b, 0, flags);
	i = 1;
	while (stack_len(*stack_a) > 3)
	{
		partitions[i] = push_stack_b(stack_a, stack_b, partitions[i - 1],
		flags);
		i++;
	}
	sort_three(stack_a, stack_b, flags);
	sort_stack_middle(stack_a, stack_b, flags, partitions);
	sort_three_first(stack_a, stack_b, flags);
	while (*stack_b)
	{
		*stack_b = set_biggest_stackb(*stack_a, *stack_b, flags);
		ps_commands_push(stack_a, stack_b, 4, flags);
	}
	free(partitions);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	if (stack_len(*stack_a) == 2)
		ps_commands_swap(stack_a, stack_b, 1, flags);
	else if (stack_len(*stack_a) == 3)
		sort_three(stack_a, stack_b, flags);
	else if (stack_len(*stack_a) > 3 && stack_len(*stack_a) <= 10)
		sort_simple_stack(stack_a, stack_b, flags);
	else if (stack_len(*stack_a) > 10 && stack_len(*stack_a) <= 399)
		new_push_swap_middle(stack_a, stack_b, flags);
	else if (stack_len(*stack_a) >= 400)
		new_push_swap_advanced(stack_a, stack_b, flags);
}

int		main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_flags *flags;

	error_input_management(argc, argv);
	stack_a = stack_maker(argv);
	if (is_sorted(stack_a) || argc == 2 || stack_len(stack_a) < 2)
		return (0);
	flags = get_flags(argv);
	initialise_flags(&stack_a, &stack_b, flags);
	stack_b = NULL;
	set_index(stack_a);
	push_swap(&stack_a, &stack_b, flags);
	execute_flags(stack_a, flags);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(flags);
	flags = NULL;
	return (0);
}
