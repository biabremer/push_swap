/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_management.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 14:22:59 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/24 10:44:08 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../pushswap_src/push_swap.h"

int		check_flags(char *str)
{
	if (ft_strcmp(str, "-v") == 0)
		return (1);
	if (ft_strcmp(str, "-s") == 0)
		return (1);
	if (ft_strcmp(str, "-m") == 0)
		return (1);
	return (0);
}

void	initialise_flags(t_stack **stack_a, t_stack **stack_b, t_flags *flags)
{
	if (flags->debug || flags->movements || flags->nonsort)
		*stack_a = delete_first_stack(*stack_a);
	if (flags->debug)
	{
		ft_printf("\nInitial stacks are:\n");
		print_stacks(*stack_a, *stack_b);
	}
}

int		count_movements(void)
{
	static int	movements;

	if (!movements)
		movements = 0;
	movements++;
	return (movements);
}

void	print_flags(t_flags *flags)
{
	ft_printf("flag -v is %i, flags -m is %i, flags -s %i\n",
	flags->debug, flags->movements, flags->nonsort);
}

t_flags	*get_flags(char **argv)
{
	t_flags *flags;
	int		j;

	j = 1;
	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->nonsort = 0;
	flags->movements = 0;
	flags->debug = 0;
	while (argv[j] && j < 4)
	{
		if (ft_strcmp(argv[j], "-v") == 0)
			flags->debug = 1;
		if (ft_strcmp(argv[j], "-m") == 0)
			flags->movements = 1;
		if (ft_strcmp(argv[j], "-s") == 0)
			flags->nonsort = 1;
		j++;
	}
	return (flags);
}
