/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:46:15 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/17 10:00:04 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	if (argc < 2 || !argv)
		return (0);
	checker(argc, argv);
	while (1);
}

int		checker(int argc, char **argv)
{
	t_stack	*a;
	t_queue *command_queue;

	a = create_stack();
	if (!create_number_stack(a, argc, argv))
		return (0);
	command_queue = create_queue();
	if (!get_commands(command_queue))
		return (ret_err_free_s(0, 0, a));
	if (execute_commands(command_queue, a) == -1)
		return (ft_printf("KO\n"));
	if (check_sorted(a) == 0)
		return (ft_printf("KO\n"));
	else
		ft_printf("OK\n");
	return (1);
}

int		check_sorted(t_stack *stack)
{
	t_elem	*buf;

	if (!stack || !(stack->top))
		return (0);
	buf = stack->top;
	while (buf->next)
	{
		ft_printf("%d < %d\n", buf->num, buf->next->num);
		if (buf->num == buf->next->num)
		{
			free_stack(stack);
			return (ret_err(2, 0));
		}
		if (buf->num > buf->next->num)
		{
			free_stack(stack);
			return (0);
		}
		buf = buf->next;
	}
	free_stack(stack);
	return (1);
}
