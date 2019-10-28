/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:22:49 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/24 11:22:03 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_integers(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	check_double_value(int *stack, int number, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (stack[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	check_range(char *str)
{
	long number;

	number = ft_atol(str);
	if (number >= 2147483647 || number <= -2147483648)
		return (1);
	return (0);
}

int	error_checks(char *str, int argc)
{
	static int	i;
	int			stack[argc - 1];

	if (!i)
		i = 0;
	stack[i] = ft_atoi(str);
	if (check_range(str))
		return (0);
	if (check_double_value(stack, stack[i], i))
		return (0);
	i++;
	return (1);
}

int	error_input_management(int argc, char **argv)
{
	int j;

	j = 1;
	while (j < argc)
	{
		if ((!check_integers(argv[j]) || !error_checks(argv[j], argc)) &&
		!check_flags(argv[j]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		j++;
	}
	if (argc < 3)
		exit(1);
	return (0);
}
