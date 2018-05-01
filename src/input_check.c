/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:08:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/01 15:20:25 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_limit_int(char *arg, int neg)
{
	int	ret;

	if (arg[0] != '2' && (ret = arg[0] > '2' ? 1 : 0) == 1)
		return (ret);
	else if (arg[1] != '1' && (ret = arg[1] > '1' ? 1 : 0) == 1)
		return (ret);
	else if (arg[2] != '4' && (ret = arg[2] > '4' ? 1 : 0) == 1)
		return (ret);
	else if (arg[3] != '7' && (ret = arg[3] > '7' ? 1 : 0) == 1)
		return (ret);
	else if (arg[4] != '4' && (ret = arg[4] > '4' ? 1 : 0) == 1)
		return (ret);
	else if (arg[5] != '8' && (ret = arg[5] > '8' ? 1 : 0) == 1)
		return (ret);
	else if (arg[6] != '3' && (ret = arg[6] > '3' ? 1 : 0) == 1)
		return (ret);
	else if (arg[7] != '6' && (ret = arg[7] > '6' ? 1 : 0) == 1)
		return (ret);
	else if (arg[8] != '4' && (ret = arg[8] > '4' ? 1 : 0) == 1)
		return (ret);
	else if ((!neg && arg[9] != '7' && (ret = arg[9] > '7' ? 1 : 0) == 1) ||
			(neg && arg[9] != '8' && (ret = arg[9] > '8' ? 1 : 0) == 1))
		return (ret);
	return (ret);
}

int			check_arg(char *arg)
{
	int		i;
	int		neg;

	i = 0;
	while (WHITESPACE(*arg) && *arg)
		arg++;
	neg = arg[0] == '-' ? 1 : 0;
	if (arg[0] == '-' || arg[1] == '+')
		arg++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (i > 11 || (i == 10 && check_limit_int(arg, neg)))
		return (0);
	return (1);
}

int			check_duplicate(t_stack *stack, int new_num)
{
	t_elem *buf;

	if (!stack)
		return (0);
	if (!stack->top)
		return (1);
	buf = stack->top;
	while (buf)
	{
		if (buf->num == new_num)
			return (0);
		buf = buf->next;
	}
	return (1);
}

int			check_command(char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		return (1);
	if (ft_strcmp(command, "sb") == 0)
		return (1);
	if (ft_strcmp(command, "ss") == 0)
		return (1);
	if (ft_strcmp(command, "pa") == 0)
		return (1);
	if (ft_strcmp(command, "pb") == 0)
		return (1);
	if (ft_strcmp(command, "ra") == 0)
		return (1);
	if (ft_strcmp(command, "rb") == 0)
		return (1);
	if (ft_strcmp(command, "rr") == 0)
		return (1);
	if (ft_strcmp(command, "rra") == 0)
		return (1);
	if (ft_strcmp(command, "rrb") == 0)
		return (1);
	if (ft_strcmp(command, "rrr") == 0)
		return (1);
	return (0);
}
