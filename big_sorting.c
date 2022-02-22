/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:17:10 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/22 17:05:46 by alemarti         ###   ########.fr       */
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

int	get_biggest_node(t_list *stack)
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

int	closest_element(t_push_swap *push_swap, int max_value)
{
	int			count_rot;
	t_list_node	*centinel;
	int			element;

	centinel = push_swap->stack_a->first;
	count_rot = 0;
	if (push_swap->stack_a->size == 0)
		return (-1);
	while (centinel->value > max_value && count_rot <= push_swap->stack_a->size)
	{
		centinel = centinel->next;
		count_rot ++;
	}
	if (count_rot > push_swap->stack_a->size)
		return (-1);
	element = centinel->value;
	centinel = push_swap->stack_a->first;
	while (centinel->value > max_value)
	{
		centinel = centinel->prev;
		count_rot--;
	}
	if (count_rot > 0)
		element = centinel->value;
	return (element);
}

void	sort_big_stack(t_push_swap *push_swap)
{
	long	*sorted_array;

	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	stack_to_indexes(push_swap->stack_a, sorted_array);
	free (sorted_array);
	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	final_sorting(push_swap);
	free(sorted_array);
	return ;
}
