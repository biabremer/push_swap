/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   call_commands.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:33:53 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 11:50:45 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_commands_rotate(t_stack **stack_a, t_stack **stack_b, int command,
t_flags *flags)
{
	if (command == 6 || command == 8)
		*stack_a = apply_rotate(*stack_a);
	if (command == 7 || command == 8)
		*stack_b = apply_rotate(*stack_b);
	print_ps_commands(command);
	if (flags->debug)
		print_stacks(*stack_a, *stack_b);
	if (flags->movements)
		count_movements();
}

void	ps_commands_rev_rotate(t_stack **stack_a, t_stack **stack_b,
int command, t_flags *flags)
{
	if (command == 9 || command == 11)
		apply_rev_rotate_test(stack_a);
	if (command == 10 || command == 11)
		apply_rev_rotate_test(stack_b);
	print_ps_commands(command);
	if (flags->debug)
		print_stacks(*stack_a, *stack_b);
	if (flags->movements)
		count_movements();
}

void	ps_commands_swap(t_stack **stack_a, t_stack **stack_b, int command,
t_flags *flags)
{
	if (command == 1 || command == 3)
		*stack_a = apply_swap(*stack_a);
	else if (command == 2 || command == 3)
		*stack_b = apply_swap(*stack_b);
	print_ps_commands(command);
	if (flags->debug)
		print_stacks(*stack_a, *stack_b);
	if (flags->movements)
		count_movements();
}

void	ps_commands_push(t_stack **stack_a, t_stack **stack_b, int command,
t_flags *flags)
{
	if (*stack_b && command == 4)
	{
		*stack_a = push_stack(*stack_a, *stack_b);
		*stack_b = delete_first_stack(*stack_b);
	}
	else if (*stack_a && command == 5)
	{
		*stack_b = push_stack(*stack_b, *stack_a);
		*stack_a = delete_first_stack(*stack_a);
	}
	print_ps_commands(command);
	if (flags->debug)
		print_stacks(*stack_a, *stack_b);
	if (flags->movements)
		count_movements();
}

void	print_ps_commands(int command)
{
	if (command == 1)
		ft_printf("sa\n");
	else if (command == 2)
		ft_printf("sb\n");
	else if (command == 3)
		ft_printf("ss\n");
	else if (command == 4)
		ft_printf("pa\n");
	else if (command == 5)
		ft_printf("pb\n");
	else if (command == 6)
		ft_printf("ra\n");
	else if (command == 7)
		ft_printf("rb\n");
	else if (command == 8)
		ft_printf("rr\n");
	else if (command == 9)
		ft_printf("rra\n");
	else if (command == 10)
		ft_printf("rrb\n");
	else if (command == 11)
		ft_printf("rrr\n");
}
