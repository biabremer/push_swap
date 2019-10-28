/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   call_commands.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:33:53 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/24 14:02:46 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

void	commands_rotate(t_stack **stack_a, t_stack **stack_b, int command)
{
	if (command == 6 || command == 8)
		*stack_a = apply_rotate(*stack_a);
	if (command == 7 || command == 8)
		*stack_b = apply_rotate(*stack_b);
}

void	commands_rev_rotate(t_stack **stack_a, t_stack **stack_b, int command)
{
	if ((command == 9 || command == 11) && stack_a)
		apply_rev_rotate(stack_a);
	if ((command == 10 || command == 11) && stack_b)
		apply_rev_rotate(stack_b);
}

void	commands_swap(t_stack **stack_a, t_stack **stack_b, int command)
{
	if (command == 1 || command == 3)
		*stack_a = apply_swap(*stack_a);
	else if (command == 2 || command == 3)
		*stack_b = apply_swap(*stack_b);
}

void	commands_push(t_stack **stack_a, t_stack **stack_b, int command)
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
}

void	apply_commands(t_commands *com, t_stack **stack_a,
t_stack **stack_b)
{
	t_commands *commands;

	commands = com;
	while (commands)
	{
		if (commands->command > 0 && commands->command <= 3)
			commands_swap(stack_a, stack_b, commands->command);
		else if (commands->command == 4 || commands->command == 5)
			commands_push(stack_a, stack_b, commands->command);
		else if (commands->command >= 6 && commands->command <= 8)
			commands_rotate(stack_a, stack_b, commands->command);
		else if (commands->command >= 9 && commands->command <= 11)
			commands_rev_rotate(stack_a, stack_b, commands->command);
		else
			break ;
		commands = commands->next;
	}
	free_commands(&com);
}
