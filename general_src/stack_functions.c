/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 15:45:04 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/02 20:25:20 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

void	*add_stack(t_stack **begin, t_stack *new)
{
	t_stack *temp;

	temp = *begin;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (0);
}

t_stack	*new_int(int number, int index)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new)
	{
		new->number = number;
		new->index = index;
		new->next = NULL;
	}
	return (new);
}

t_stack	*delete_first_stack(t_stack *stack)
{
	t_stack *temp;

	temp = stack->next;
	free(stack);
	stack = NULL;
	return (temp);
}

void	print_stack(t_stack *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
		{
			ft_printf("%i ", stack->number);
			stack = stack->next;
		}
		ft_printf("%i ", stack->number);
		ft_printf("\n");
	}
	else
		ft_printf("Empty stack\n");
}

t_stack	*stack_maker(char **argv)
{
	int		j;
	t_stack	*stack;
	t_stack *temp;

	j = 2;
	if (check_flags(argv[j]))
		j++;
	stack = new_int(ft_atoi(argv[1]), 1);
	while (argv[j])
	{
		if (check_flags(argv[j]) && argv[j + 1])
			j++;
		temp = new_int(ft_atoi(argv[j]), j);
		add_stack(&stack, temp);
		j++;
	}
	return (stack);
}
