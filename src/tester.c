/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:23:41 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/16 17:03:30 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main()
{
	t_stack *stack;
	int		cmp;

	stack = create_stack();
	cmp = push(stack, 1, 0)->num == 1;
	assert(cmp);
	cmp = ft_strcmp(push(stack, 0, "str")->str, "str");
	assert(!cmp);
	assert(stack_size(stack) == 2);
	assert(pop(stack)->num == 1);
	assert(stack_size(stack) == 1);
	assert(stack->top->num == 1);
	assert(pop(stack) == 0);
}
