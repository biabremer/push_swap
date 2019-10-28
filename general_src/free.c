/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 16:34:15 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 13:22:43 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

void	free_stack(t_stack **stack)
{
	t_stack *next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = next;
	}
}

void	free_commands(t_commands **commands)
{
	t_commands *next;

	while (*commands)
	{
		next = (*commands)->next;
		free(*commands);
		*commands = NULL;
		*commands = next;
	}
}

void	execute_flags(t_stack *stack_a, t_flags *flags)
{
	int movements;

	movements = count_movements() - 1;
	if (flags->movements)
		ft_printf("The number of movements made is %i\n", movements);
	if (flags->nonsort)
	{
		while (stack_a->next != NULL)
		{
			if (stack_a->number > stack_a->next->number)
			{
				ft_printf("Non sorted numbers are %i and %i\n", stack_a->number,
				stack_a->next->number);
				return ;
			}
			stack_a = stack_a->next;
		}
		ft_printf("It's sorted\n");
	}
}

int		stack_len(t_stack *stack)
{
	int		len;
	t_stack *temp;

	temp = stack;
	len = 1;
	if (!stack)
		return (0);
	while (temp->next != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("STACK A:\n");
	if (stack_a)
		print_stack(stack_a);
	ft_printf("STACK B:\n");
	if (stack_b)
		print_stack(stack_b);
	ft_printf("\n");
}
