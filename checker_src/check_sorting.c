/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 13:05:13 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/23 21:23:20 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next != NULL)
	{
		if (stack_a->number > stack_a->next->number)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
