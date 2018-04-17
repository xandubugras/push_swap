/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:27:08 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/17 09:53:35 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_queue(t_queue *queue)
{
	if (!queue)
		return ;
	while (dequeue(queue))
		;
	if (queue)
		free(queue);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->top)
	{
		pop(stack);
	}
	free(stack);
}
