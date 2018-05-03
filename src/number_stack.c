/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:51:57 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/02 22:06:45 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
}

int		create_str_split(t_stack *a, char *numbers)
{
	char	**str;
	int		tmp;
	int		i;

	str = ft_strsplit(numbers, ' ');
	i = -1;
	while (str[++i])
	{
		if (!check_arg(str[i]))
		{
			free_str(str);
			free_stack(a);
			return (ret_err(0, "Error\n"));
		}
		tmp = ft_atoi(str[i]);
		if (!check_duplicate(a, tmp))
		{
			free_str(str);
			free_stack(a);
			return (ret_err(0, "Error\n"));
		}
		push(a, tmp, 0);
	}
	free_str(str);
	return (1);
}

int		create_number_stack(t_stack *a, int size, char **numbers)
{
	int	tmp;

	if (size == 2)
		return (create_str_split(a, numbers[1]));
	size--;
	while (size > 0)
	{
		if (!check_arg(numbers[size]))
		{
			free_stack(a);
			return (ret_err(0, "Error\n"));
		}
		tmp = ft_atoi(numbers[size]);
		if (!check_duplicate(a, tmp))
		{
			free_stack(a);
			return (ret_err(0, "Error\n"));
		}
		push(a, tmp, 0);
		size--;
	}
	return (1);
}

int		*bubble_sort(int size, t_stack *numbers)
{
	int		*list;
	int		i;
	t_elem	*el;

	el = numbers->top;
	size--;
	list = malloc(sizeof(int) * size);
	i = 0;
	while (el)
	{
		list[i] = el->num;
		el = el->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		if (list[i] > list[i + 1])
		{
			ft_swap(&(list[i]), &(list[i + 1]));
			i = 0;
		}
		i++;
	}
	return (list);
}

int		get_median(int size, t_stack *numbers)
{
	int *list;
	int	ret;

	list = bubble_sort(size, numbers);
	ret = list[size / 2 + 1];
	free(list);
	return (ret);
}
