/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:41:09 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/16 21:34:10 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include "../libft/libft.h"

typedef struct	s_elem
{
	struct s_elem	*next;
	struct s_elem	*prev;
	int				num;
	char			*str;
}				t_elem;

typedef struct	s_queue
{
	struct s_elem	*rear;
	struct s_elem	*front;
}				t_queue;

typedef struct	s_stack
{
	struct s_elem	*top;
}				t_stack;
/*
**-------------------------Checker--------------------
*/
int				checker(int argc, char **argv);

int				check_sorted(t_stack *stack);
/*
**-------------------------NUMBER STACK--------------------
*/
int				create_number_stack(t_stack *a, int size, char **numbers);

/*
**-------------------------Input Checker--------------------
*/
int				check_command(char *command);

int				check_duplicate(t_stack *stack, int new_num);

int				check_arg(char *arg);

/*
**-------------------------QUEUES----------------------
*/
t_elem			*create_elem(int x, char *str);

t_queue			*create_queue(void);

void			print_queue(t_queue *queue, char order);

t_elem			*dequeue(t_queue *queue);

t_elem			*enqueue(t_queue *queue, int x, char *str);
/*
**-------------------------STACKS----------------------
*/
t_stack			*create_stack(void);

t_elem			*push(t_stack *stack, int x, char *str);

t_elem			*pop(t_stack *stack);

int				stack_size(t_stack *stack);

void			print_stack(t_stack *stack);

/*
**------------------------OPERATIONS-------------------
*/
void			swap(t_stack *a);

void			push_to(t_stack *from, t_stack* to);

void			rotate(t_stack *a);

void			reverse_rotate(t_stack *a);
/*
**-----------------EXECUTE COMMANDS---------------------
*/
int				execute_commands(t_queue *commands, t_stack *a);

void			get_command_func(char *str, t_stack *a, t_stack *b);

int				get_commands(t_queue *command_queue);
/*
**------------------ERRORS------------------------------
*/
int				ret_err_free_q_s(int ret_val, char *str, t_queue *q, t_stack *s);

int				ret_err_free_s(int ret_val, char *str, t_stack *s);

int				ret_err(int ret_val, char *str);
/*
**------------------HELPERS------------------------------
*/
void			free_stack(t_stack *stack);

void			free_queue(t_queue *queue);
#endif
