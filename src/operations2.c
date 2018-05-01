/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:19:07 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/01 15:18:16 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define R 1
#define O 0
#include "../include/push_swap.h"

void	swap_q(t_stack *s, char order, t_queue *commands)
{
	swap(s);
	if (order == R)
		enqueue(commands, 0, "sa");
	else
		enqueue(commands, 0, "sb");
}

void	rotate_q(t_stack *s, char order, t_queue *commands)
{
	rotate(s);
	if (order == R)
		enqueue(commands, 0, "ra");
	else
		enqueue(commands, 0, "rb");
}

void	reverse_rotate_q(t_stack *s, char order, t_queue *commands)
{
	reverse_rotate(s);
	if (order == R)
		enqueue(commands, 0, "rra");
	else
		enqueue(commands, 0, "rrb");
}

void	push_q(t_stack *from, t_stack *to, char order, t_queue *commands)
{
	push_to(from, to);
	if (order == R)
		enqueue(commands, 0, "pb");
	else
		enqueue(commands, 0, "pa");
}
