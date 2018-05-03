/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 10:26:35 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/02 20:19:05 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#define NUM top->num
#define NEXT_NUM top->next->num
#define O 0
#define R 1

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argc, argv);
}

int		push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_queue *command_queue;

	a = create_stack();
	if (!create_number_stack(a, argc, argv))
		return (0);
	command_queue = create_queue();
	sort_stack(a, command_queue);
	clean_queue(command_queue);
	print_queue(command_queue, 'R');
	free_stack(a);
	free_queue(command_queue);
	return (1);
}
