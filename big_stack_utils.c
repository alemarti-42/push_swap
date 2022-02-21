/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:18:38 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 18:39:54 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_push_swap *push_swap)
{
	long	*sorted_array;

	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	stack_to_indexes(push_swap->stack_a, sorted_array);
	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	final_sorting(push_swap);
	return ;
}

void	stack_to_indexes(t_list *stack, long *sorted_array)
{
	t_list_node	*centinel;
	int			n;
	int			i;

	centinel = stack->first;
	i = stack->size;
	while (i > 0)
	{
		n = 0;
		while (n < stack->size && centinel->value != sorted_array[n])
			n++;
		if (centinel->value == sorted_array[n])
				centinel->value = n;
		i--;
		centinel = centinel->next;
	}
	return ;
}

int	value_to_index(int value, t_list *stack)
{
	int			i;
	t_list_node	*centinel;

	i = 0;
	centinel = stack->first;
	while (centinel->next != stack->first)
	{
		if (centinel->value == value)
		{
			return (i);
		}
		centinel = centinel->next;
		i++;
	}
	if (centinel->value == value)
	{
		return (i);
	}
	return (-1);
}

void	print_int_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(array[i], 1);
		i++;
	}
	return ;
}

long	*stack_to_array(t_list *stack)
{
	t_list_node	*centinel;
	long		*res;
	int			i;

	centinel = stack->first;
	res = malloc(sizeof(long) * stack->size);
	i = 0;
	while (centinel->next != stack->first)
	{
		res[i] = centinel->value;
		centinel = centinel->next;
		i++;
	}
	res[i] = centinel->value;
	return (res);
}

static void	swap_mem(long *xp, long *yp)
{
	long	tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

void	sort_array(long *arr, int size)
{
	long	i;
	long	j;
	long	min_idx;

	i = 0;
	j = 0;
	while (i < size)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap_mem(&arr[min_idx], &arr[i]);
		i++;
	}
	return ;
}
