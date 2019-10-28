/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_commands.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 14:52:39 by bbremer        #+#    #+#                */
/*   Updated: 2019/07/24 11:21:04 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

void		print_commands(t_commands *commands)
{
	while (commands->next != NULL)
	{
		ft_printf("command is %i\n", commands->command);
		commands = commands->next;
	}
	ft_printf("command is %i\n", commands->command);
}

void		add_commands(t_commands **commands, char *str)
{
	t_commands *new;
	t_commands *temp;

	new = new_command(str);
	temp = *commands;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

int			get_command_id(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	else if (ft_strcmp(str, "sb") == 0)
		return (2);
	else if (ft_strcmp(str, "ss") == 0)
		return (3);
	else if (ft_strcmp(str, "pa") == 0)
		return (4);
	else if (ft_strcmp(str, "pb") == 0)
		return (5);
	else if (ft_strcmp(str, "ra") == 0)
		return (6);
	else if (ft_strcmp(str, "rb") == 0)
		return (7);
	else if (ft_strcmp(str, "rr") == 0)
		return (8);
	else if (ft_strcmp(str, "rra") == 0)
		return (9);
	else if (ft_strcmp(str, "rrb") == 0)
		return (10);
	else if (ft_strcmp(str, "rrr") == 0)
		return (11);
	else
		return (0);
}

t_commands	*new_command(char *str)
{
	t_commands *new;

	new = (t_commands*)malloc(sizeof(t_commands));
	new->command = get_command_id(str);
	new->next = NULL;
	if (new->command == 0)
	{
		ft_printf("Error: command %s not valid\n", str);
		free(new);
		new = NULL;
		exit(1);
	}
	return (new);
}

void		get_commands(t_commands **commands)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (!line || ft_strcmp(line, "\n") == 0)
			break ;
		if (!*commands)
			*commands = new_command(line);
		else
			add_commands(commands, line);
		free(line);
		ret = get_next_line(0, &line);
	}
}
