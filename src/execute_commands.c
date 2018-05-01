/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:17:48 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/01 15:21:51 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			execute_commands(t_queue *commands, t_stack *a)
{
	t_stack	*b;

	b = create_stack();
	if (!(commands && commands->front))
		return (0);
	while (commands->front)
	{
		get_command_func(commands->front->str, a, b);
		dequeue(commands);
	}
	free(commands);
	if (stack_size(b) != 0)
	{
		free_stack(b);
		free_stack(a);
		return (-1);
	}
	free(b);
	return (1);
}

static void	get_command_func_2(char *command, t_stack *a, t_stack *b)
{
	if (ft_strcmp(command, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(command, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(command, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(command, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(command, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(command, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void		get_command_func(char *command, t_stack *a, t_stack *b)
{
	if (ft_strcmp(command, "sa") == 0)
		swap(a);
	else if (ft_strcmp(command, "sb") == 0)
		swap(b);
	else if (ft_strcmp(command, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(command, "pa") == 0)
		push_to(b, a);
	else if (ft_strcmp(command, "pb") == 0)
		push_to(a, b);
	else
		get_command_func_2(command, a, b);
}

int			get_commands(t_queue *command_queue)
{
	char	*command;

	while (get_next_line(0, &command) > 0)
	{
		if (!(*command) || *command == '\n')
		{
			free(command);
			break ;
		}
		if (command && check_command(command))
			enqueue(command_queue, 0, command);
		else
		{
			free_queue(command_queue);
			free(command);
			return (0);
		}
		free(command);
	}
	return (1);
}
