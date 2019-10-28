/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_cases.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 14:07:06 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 11:57:48 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_two(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	ps_commands_rotate(stack_a, stack_b, 6, flags);
	ps_commands_swap(stack_a, stack_b, 1, flags);
	ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
}

void	sort_case_three(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	ps_commands_rotate(stack_a, stack_b, 6, flags);
	ps_commands_swap(stack_a, stack_b, 1, flags);
	ps_commands_rotate(stack_a, stack_b, 6, flags);
	ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
	ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
	ps_commands_swap(stack_a, stack_b, 1, flags);
}

void	sort_case_four(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	ps_commands_swap(stack_a, stack_b, 1, flags);
}

void	sort_case_five(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	ps_commands_swap(stack_a, stack_b, 1, flags);
	ps_commands_rotate(stack_a, stack_b, 6, flags);
	ps_commands_swap(stack_a, stack_b, 1, flags);
	ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
}

void	sort_case_six(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	ps_commands_swap(stack_a, stack_b, 1, flags);
	ps_commands_rotate(stack_a, stack_b, 6, flags);
	ps_commands_swap(stack_a, stack_b, 1, flags);
	ps_commands_rotate(stack_a, stack_b, 6, flags);
	ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
	ps_commands_rev_rotate(stack_a, stack_b, 9, flags);
	ps_commands_swap(stack_a, stack_b, 1, flags);
}
