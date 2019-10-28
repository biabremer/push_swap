/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 12:33:07 by bbremer        #+#    #+#                */
/*   Updated: 2019/08/05 13:25:44 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_commands	*commands;

	stack_b = NULL;
	error_input_management(argc, argv);
	stack_a = stack_maker(argv);
	get_commands(&commands);
	apply_commands(commands, &stack_a, &stack_b);
	if (check_sorting(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
