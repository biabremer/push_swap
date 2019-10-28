/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_commands.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:33:53 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/24 10:33:18 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

t_stack	*apply_swap(t_stack *stack)
{
	int temp_number;
	int	temp_index;

	if (stack && stack->next != NULL)
	{
		temp_number = stack->number;
		temp_index = stack->index;
		stack->number = stack->next->number;
		stack->index = stack->next->index;
		stack->next->number = temp_number;
		stack->next->index = temp_index;
	}
	return (stack);
}

t_stack	*apply_rotate(t_stack *stack)
{
	t_stack	*new_stack;
	t_stack *temp;

	if (stack && stack->next != NULL)
	{
		new_stack = stack->next;
		temp = stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = stack;
		stack->next = NULL;
		return (new_stack);
	}
	return (stack);
}

void	apply_rev_rotate_test(t_stack **stack)
{
	t_stack	*new_stack;
	t_stack *temp;

	if (stack && (*stack)->next != NULL)
	{
		new_stack = *stack;
		while (new_stack->next != NULL)
			new_stack = new_stack->next;
		temp = *stack;
		while (temp->next->next != NULL)
			temp = temp->next;
		new_stack->next = *stack;
		temp->next = NULL;
		*stack = new_stack;
	}
}

t_stack	*push_stack(t_stack *stack, t_stack *new)
{
	t_stack *temp;

	temp = new_int(new->number, new->index);
	if (stack)
	{
		temp->next = stack;
		return (temp);
	}
	else
		stack = temp;
	return (stack);
}

void	apply_push(t_stack ***stack_1, t_stack ***stack_2)
{
	**stack_1 = push_stack(**stack_1, **stack_2);
	**stack_2 = delete_first_stack(**stack_2);
}
