/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:38:56 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/17 21:04:40 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#define R 1
#define O 0

int		sort_stack(t_stack *a, t_queue *commands)
{
	t_stack	*b;
	int		size;

	b = create_stack();
	size = stack_size(a);
	if (size == 1)
		return (1);
	if (size <= 5)
	{
		solve_stack_two_three(a, commands);
		return (0);
	}
	while (1)
	{
		while (a && a->top != a->bot)
		{
			if (stack_sorted(a))
				break;
			push_smart(a, b, R, commands);
		}
		while (b && b->top)
			push_smart(b, a, O, commands);
		if (stack_sorted(a))
			break ;
	}
	return (1);
}
/*
**checks the greatest between first second and last, depending on order
**pops the element in (from)
**pushes the same element in (to)
**places in first second or last in (to) depending on order
**'O' takes the max and places smaller on top
**'R' takes the min and places bigger on top
*/
void	push_smart(t_stack *from, t_stack *to, char order, t_queue *commands)
{
	t_elem	*tmp;

	if (!from || !to || !(from->top)) //check stacks exist
		return ;
	tmp = order == O ? get_max_elem(from) : get_min_elem(from); //sets on order
	if (from->top->next && tmp == from->top->next)
		swap_q(from, order, commands);
	else if (tmp == from->bot)
		reverse_rotate_q(from, order, commands);
	tmp = to->top;
	push_q(from, to, order, commands);
	if (!(tmp && !compare(to->top->num, tmp->num, order)))
		return ;
	else if (tmp->next && compare(to->top->num, tmp->next->num, order))
		swap_q(to, order, commands);
	else
		rotate_q(to, order, commands);
}

int		solve_stack_two_three(t_stack *a, t_queue *commands)
{
	if (stack_sorted(a))
		return (1) ;
	if (a->top->num > a->top->next->num)
		swap_q(a, 0, commands);
	else
		reverse_rotate_q(a, 1, commands);
	return (solve_stack_two_three(a, commands));

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
