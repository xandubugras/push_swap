/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:51:57 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/17 09:56:13 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		create_number_stack(t_stack *a, int size, char **numbers)
{
	int	tmp;

	size--;
	while (size > 0)
	{
		if (!check_arg(numbers[size]))
		{
			free_stack(a);
			return (ret_err(0, "wrong arg\n"));
		}
		tmp = ft_atoi(numbers[size]);
		if (!check_duplicate(a, tmp))
		{
			free_stack(a);
			return (ret_err(0, "duplicated\n"));
		}
		push(a, tmp, 0);
		size--;
	}
	return (1);
}
