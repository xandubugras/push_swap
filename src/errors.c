/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:23:30 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/16 21:25:25 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ret_err(int ret_val, char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd("Error\n", 2);
	return (ret_val);
}

int		ret_err_free_q_s(int ret_val, char *str, t_queue *q, t_stack *s)
{
	free_queue(q);
	free_stack(s);
	return (ret_err(ret_val, str));
}

int		ret_err_free_s(int ret_val, char *str, t_stack *s)
{
	free_stack(s);
	return (ret_err(ret_val, str));
}
