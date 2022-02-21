/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:17:10 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 20:35:59 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	final_sorting(t_push_swap *push_swap)
{
	int	n_chunks;

	n_chunks = 1;
	while (n_chunks * n_chunks < push_swap->stack_a->size)
		n_chunks ++;
	selection_sort(push_swap, n_chunks);
	return ;
}

void	selection_sort(t_push_swap *push_swap, int n_chunks)
{
	int	next_element;
	int	chunk_size;
	int	pivot;

	chunk_size = push_swap->stack_a->size / n_chunks;
	pivot = 0;
	while (push_swap->stack_a->size > 0)
	{
		pivot += chunk_size;
		next_element = closest_element(push_swap, pivot);
		while (next_element >= 0)
		{
			smart_push(push_swap, next_element);
			next_element = closest_element(push_swap, pivot);
		}
	}
	while (push_swap->stack_b->first->value < \
	push_swap->stack_b->first->prev->value)
		exec_rrb(push_swap);
	while (push_swap->stack_b->size > 0)
		exec_pa(push_swap);
	return ;
}

long	smart_allocation(t_push_swap *push_swap, long element)
{
	t_list_node	*centinel;
	long			max_value;
	int			i;

	if (push_swap->stack_b->size == 0)
		return (0);
	i = 0;
	centinel = push_swap->stack_b->first;
	max_value = push_swap->stack_b->first->value;
	while (i < push_swap->stack_b->size)
	{
		if (centinel->prev->value > element && centinel->value < element)
			return (centinel->value);
		if (centinel->value > max_value)
			max_value = centinel->value;
		centinel = centinel->next;
		i++;
	}
	printf("\tmaxvalue: %ld\n", max_value);
	return (max_value);
}

long	get_biggest_node(t_list *stack)
{
	int			biggest;
	t_list_node	*centinel;

	if (!stack)
		return (-1);
	centinel = stack->first;
	biggest = -1;
	while (centinel->next != stack->first)
	{
		if (centinel->value > biggest)
			biggest = centinel->value;
		centinel = centinel->next;
	}
	if (centinel->value > biggest)
			biggest = centinel->value;
	return (biggest);
}

void	smart_push(t_push_swap *push_swap, long element)
{
	smart_rotate(push_swap, push_swap->stack_a, element);
	smart_rotate(push_swap, push_swap->stack_b, smart_allocation(push_swap, element));
	exec_pb (push_swap);
	return ;
}
