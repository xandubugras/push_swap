/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:56:13 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/01 15:12:24 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem	*remove_list(t_elem *elem)
{
	t_elem *ret;

	if (!elem)
		return (0);
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	ret = elem->prev ? elem->prev : elem->next;
	if (elem->str)
		free(elem->str);
	free(elem);
	return (ret);
}

void	clean_queue(t_queue *commands)
{
	t_elem *buf;

	buf = commands->rear;
	while (buf)
	{
		if (buf->next && !ft_strcmp(buf->next->str, "pa") &&
				!ft_strcmp(buf->str, "pb"))
		{
			remove_list(buf->next);
			buf = remove_list(buf);
		}
		else if (buf->next && !ft_strcmp(buf->next->str, "pb") &&
				!ft_strcmp(buf->str, "pa"))
		{
			remove_list(buf->next);
			buf = remove_list(buf);
		}
		else
			buf = buf->next;
	}
}

int		stack_sorted(t_stack *stack)
{
	t_elem *buf;

	buf = stack->top;
	if (!buf)
		return (0);
	while (buf->next)
	{
		if (buf->num > buf->next->num)
			return (0);
		buf = buf->next;
	}
	return (1);
}
