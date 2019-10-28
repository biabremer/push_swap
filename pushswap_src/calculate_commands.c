/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_commands.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:33:53 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/24 10:50:52 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_commands_rotate(t_stack **stack_a, t_stack **stack_b, int command)
{
	if (command == 6 || command == 8)
		*stack_a = apply_rotate(*stack_a);
	if (command == 7 || command == 8)
		*stack_b = apply_rotate(*stack_b);
}

void	calc_commands_rev_rotate(t_stack **stack_a, t_stack **stack_b,
		int command)
{
	if ((command == 9 || command == 11) && *stack_a)
		apply_rev_rotate_test(stack_a);
	if ((command == 10 || command == 11) && *stack_b)
		apply_rev_rotate_test(stack_b);
}
