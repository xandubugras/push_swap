/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:27:08 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/01 15:13:32 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#define NUM top->num
#define NEXT_NUM top->next->num
#define R 1
#define O 0

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

t_elem	*get_min_elem(t_stack *stack)
{
	t_elem *min;

	if (!stack)
		return (0);
	if (stack->top && !stack->top->next)
		return (stack->top);
	if (stack->top->next)
		min = stack->NUM < stack->NEXT_NUM ? stack->top : stack->top->next;
	if (stack->top->next->next)
		min = min->num < stack->top->next->next->num ?
			min : stack->top->next->next;
	if (stack->bot && stack->bot != stack->top->next->next)
		min = min->num < stack->bot->num ? min : stack->bot;
	if (stack->bot && stack->bot->prev)
		min = min->num < stack->bot->prev->num ? min : stack->bot->prev;
	return (min);
}

t_elem	*get_max_elem(t_stack *stack)
{
	t_elem *max;

	if (!stack)
		return (0);
	if (stack->top && !stack->top->next)
		return (stack->top);
	if (stack->top->next)
		max = stack->NUM > stack->NEXT_NUM ? stack->top : stack->top->next;
	if (stack->top->next->next)
		max = max->num > stack->top->next->next->num ?
			max : stack->top->next->next;
	if (stack->bot && stack->bot != stack->top->next->next)
		max = max->num > stack->bot->num ? max : stack->bot;
	if (stack->bot && stack->bot->prev)
		max = max->num > stack->bot->prev->num ? max : stack->bot->prev;
	return (max);
}

int		compare(int a, int b, char cmp)
{
	if (cmp == O)
		return (a < b);
	if (cmp == R)
		return (a > b);
	return (0);
}
