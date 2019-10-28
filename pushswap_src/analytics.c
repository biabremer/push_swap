/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   analytics.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 15:44:46 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/22 16:02:52 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	analyse_three_biggest(t_stack *stack, int biggest)
{
	int	first_biggest;
	int	second_biggest;
	int	third_biggest;
	int	best_number;

	first_biggest = calculate_set_number(stack, biggest);
	second_biggest = calculate_set_number(stack, biggest - 1);
	third_biggest = calculate_set_number(stack, biggest - 2);
	best_number = biggest - find_best_move(first_biggest, second_biggest,
	third_biggest);
	return (best_number);
}

int	analyse_two_biggest(t_stack *stack, int biggest)
{
	int	first_biggest;
	int	second_biggest;
	int	best_number;

	first_biggest = calculate_set_number(stack, biggest);
	if (check_index_in_stack(stack, (biggest - 1)))
		second_biggest = calculate_set_number(stack, biggest - 1);
	else
		second_biggest = calculate_set_number(stack, biggest - 2);
	best_number = find_best_move(first_biggest, second_biggest, 0);
	if (best_number == 0)
		return (biggest);
	else if (best_number == 1 && check_index_in_stack(stack, (biggest - 1)))
		return (biggest - 1);
	else
		return (biggest - 2);
}

int	find_best_move(int first, int second, int third)
{
	int best;

	best = 0;
	if (second < first)
		best = 1;
	if (third < second && third < first && third != 0)
		best = 2;
	return (best);
}

int	get_moves(int stack_i, int number, t_stack **temp)
{
	int moves;
	int len;

	len = stack_len(*temp);
	moves = 0;
	if (stack_i > (len / 2))
	{
		while (stack_i > 1)
		{
			calc_commands_rev_rotate(NULL, temp, 10);
			stack_i = find_index_position(*temp, number);
			moves++;
		}
	}
	if (stack_i <= (len / 2))
	{
		while (stack_i > 1)
		{
			calc_commands_rotate(NULL, temp, 7);
			stack_i = find_index_position(*temp, number);
			moves++;
		}
	}
	return (moves);
}

int	calculate_set_number(t_stack *stack, int number)
{
	int		stack_i;
	int		moves;
	int		len;
	t_stack	*temp;

	temp = copy_stack(stack);
	len = stack_len(temp);
	moves = 0;
	stack_i = find_index_position(temp, number);
	if (stack_i == 1)
	{
		free_stack(&temp);
		return (1);
	}
	moves = get_moves(stack_i, number, &temp);
	free_stack(&temp);
	return (moves);
}
