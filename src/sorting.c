/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:38:56 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/01 15:25:11 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#define R 1
#define O 0

int		sort_stack(t_stack *a, t_queue *commands)
{
	t_stack	*b;
	int		curr_size;
	int		size;

	if ((size = stack_size(a)) <= 1 || stack_sorted(a))
		return (1);
	divide_medium(a, b = create_stack(), commands);
	curr_size = stack_size(a);
	while (1)
	{
		while (curr_size > 3 && a)
		{
			push_smart(a, b, R, commands);
			curr_size--;
		}
		if (stack_size(a) <= 3)
			solve_stack_two_three(a, commands);
		while (b && b->top)
			push_smart(b, a, O, commands);
		if ((curr_size = size) && stack_sorted(a))
			break ;
	}
	free(b);
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

void	divide_medium(t_stack *a, t_stack *b, t_queue *commands)
{
	int		medium;
	int		curr_size;

	curr_size = stack_size(a);
	medium = curr_size / 2;
	while (curr_size > 15 && curr_size > medium + 1)
	{
		if (a->top->num <= medium)
		{
			curr_size--;
			push_q(a, b, R, commands);
		}
		else
			rotate_q(a, R, commands);
	}
}

void	push_smart(t_stack *from, t_stack *to, char order, t_queue *commands)
{
	t_elem	*tmp;

	send_smart(from, to, order, commands);
	tmp = to->top->next;
	if (!(tmp && !compare(to->top->num, tmp->num, order)))
		return ;
	else if (tmp->next && compare(to->top->num, tmp->next->num, order))
		swap_q(to, !order, commands);
	else
		rotate_q(to, !order, commands);
}

void	send_smart(t_stack *from, t_stack *to, char order, t_queue *commands)
{
	t_elem	*tmp;

	if (!from || !to || !(from->top))
		return ;
	tmp = order == O ? get_max_elem(from) : get_min_elem(from);
	if (from->top->next && tmp == from->top->next)
		swap_q(from, order, commands);
	else if (from->top->next && from->top->next->next &&
			tmp == from->top->next->next)
	{
		rotate_q(from, order, commands);
		swap_q(from, order, commands);
	}
	else if (tmp == from->bot && from->bot != from->top)
		reverse_rotate_q(from, order, commands);
	else if (from->bot->prev && tmp == from->bot->prev)
	{
		reverse_rotate_q(from, order, commands);
		reverse_rotate_q(from, order, commands);
	}
	if (order && stack_sorted(from))
		return ;
	tmp = to->top;
	push_q(from, to, order, commands);
}

/*
**sorts a stack with 2 or three numbers in 1 or 2 steps
*/

int		solve_stack_two_three(t_stack *a, t_queue *commands)
{
	if (stack_sorted(a))
		return (1);
	if (a->top->num > a->top->next->num && a->top->num > a->bot->num)
		rotate_q(a, 1, commands);
	else if (a->top->num > a->top->next->num)
		swap_q(a, 1, commands);
	else
		reverse_rotate_q(a, 1, commands);
	return (solve_stack_two_three(a, commands));
}
