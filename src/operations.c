/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:00:23 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/17 18:39:29 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *a)
{
	if (!(a && (a->top) && (a->top->next)))
		return ;
	ft_swap(&(a->top->num), &(a->top->next->num));
}

void	push_to(t_stack *from, t_stack* to)
{
	if (!(from && to && from->top))
		return ;
	push(to, from->top->num, 0);
	pop(from);
}

void	rotate(t_stack *a)
{
	t_elem	*buf;
	t_elem	*tmp;

	if (!(a && a->top && a->bot))
		return ;
	if (a->top == a->bot)
		return ;
	buf = a->bot;
	if (buf)
	{
		tmp = a->top;
		buf->next = tmp;
		tmp->prev = buf;
		a->top = tmp->next;
		tmp->next = 0;
		a->bot = tmp;
	}
}

void	reverse_rotate(t_stack *a)
{
	t_elem	*buf;
	t_elem	*tmp;

	if (!(a && a->top))
		return ;
	if (a->top == a->bot)
		return ;
	buf = a->bot;
	if (buf)
	{
		tmp = a->top;
		if (buf->prev)
		{
			a->bot = buf->prev;
			buf->prev->next = 0;
		}
		if (buf != tmp)
			buf->next = tmp; 
		else 
			buf->next = 0;
		buf->prev = 0;	//
		tmp->prev = buf;
		a->top = buf;
	}
}

void	test_operations(t_stack *a)
{
	ft_printf("stack before swap: \n");
	print_stack(a);
	ft_putchar('\n');
	swap(a);
	ft_printf("stack after swap: \n");
	print_stack(a);
	ft_putchar('\n');
	rotate(a);
	ft_printf("stack after rotate: \n");
	print_stack(a);
	ft_putchar('\n');
	reverse_rotate(a);
	ft_printf("stack after rev rotate: \n");
	print_stack(a);
	ft_putchar('\n');
}
