/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:41:09 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/02 22:26:40 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
	struct s_elem	*bot;
}				t_stack;
/*
**-------------------------CHECKER--------------------
*/
int				checker(int argc, char **argv);

int				check_sorted(t_stack *stack);
/*
**-------------------------SOLVER---------------------
*/
int				push_swap(int argc, char **argv);

void			clean_queue(t_queue *commands);
/*
**-------------------------SORTING---------------------
*/
int				sort_stack(t_stack *a, t_queue *commands);

int				stack_sorted(t_stack *a);

void			divide_medium(t_stack *a, t_stack *b,
		t_queue *commands, int order);

int				solve_stack_two_three(t_stack *a, t_queue *commands);

void			push_smart(t_stack *from, t_stack *to,
				char order, t_queue *commands);

void			send_smart(t_stack *from, t_stack *to,
				char order, t_queue *commands);

void			receive_smart(t_stack *to, char order, t_queue *commands);

void			simulator(t_stack *a, t_queue *commands);
/*
**-------------------------NUMBER STACK--------------------
*/
int				create_number_stack(t_stack *a, int size, char **numbers);

int				*bubble_sort(int size, t_stack *numbers);

int				get_median(int size, t_stack *numbers);

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
**-------------------------LISTS----------------------
*/
t_elem			*remove_list(t_elem *elem);
/*
**------------------------OPERATIONS-------------------
*/
int				swap(t_stack *a);

int				push_to(t_stack *from, t_stack *to);

int				rotate(t_stack *a);

int				reverse_rotate(t_stack *a);
/*
**------------------------OPERATIONS-------------------
*/
void			swap_q(t_stack *s, char order, t_queue *commands);

void			rotate_q(t_stack *s, char order, t_queue *commands);

void			reverse_rotate_q(t_stack *s, char order,
				t_queue *commands);

void			push_q(t_stack *from, t_stack *to, char order,
				t_queue *commands);
/*
**-----------------EXECUTE COMMANDS---------------------
*/
int				execute_commands(t_queue *commands, t_stack *a);

void			get_command_func(char *str, t_stack *a, t_stack *b);

int				get_commands(t_queue *command_queue);
/*
**------------------ERRORS------------------------------
*/
int				ret_err_free_q_s(int ret_val, char *str, t_queue *q,
				t_stack *s);

int				ret_err_free_s(int ret_val, char *str, t_stack *s);

int				ret_err(int ret_val, char *str);
/*
**------------------HELPERS------------------------------
*/
t_elem			*get_min_elem(t_stack *stack);

t_elem			*get_max_elem(t_stack *stack);

int				compare(int a, int b, char cmp);

void			free_stack(t_stack *stack);

void			free_queue(t_queue *queue);

int				size_dbl_str(char **str);
#endif
