/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 14:29:31 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/22 14:33:29 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_stack *copy;
	t_stack *temp;
	t_stack *temp_stack;

	if (!stack)
		return (NULL);
	copy = new_int(stack->number, stack->index);
	temp_stack = stack;
	temp_stack = temp_stack->next;
	while (temp_stack->next != NULL)
	{
		temp = new_int(temp_stack->number, temp_stack->index);
		add_stack(&copy, temp);
		temp_stack = temp_stack->next;
	}
	temp = new_int(temp_stack->number, temp_stack->index);
	add_stack(&copy, temp);
	return (copy);
}
