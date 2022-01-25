/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:17:10 by alemarti          #+#    #+#             */
/*   Updated: 2022/01/25 18:21:19 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void	final_sorting(t_push_swap *push_swap)
{
	int	chunk_size;
	int	n_chunks;
	int	i;
	int	pivot;

	n_chunks = 5;
	i = n_chunks;
	chunk_size = push_swap->stack_a->size / n_chunks;
	pivot = chunk_size - 1;
	while (push_swap->stack_a->size > 0)
	{
		sort_chunk(push_swap, pivot);
		pivot += chunk_size;
	}
	return ;
}

void	sort_chunk(t_push_swap *push_swap, int pivot)
{
	//int	i;
	int	next_element;

	next_element = 0;
	pivot = push_swap->stack_a->size;
	//next_element = closest_element(push_swap, pivot);
	while (next_element < pivot)
	{
		smart_push(push_swap, next_element);
		//next_element = closest_element(push_swap, pivot);
		next_element ++;
	}
	return ;
}

// void	smart_rotate(t_push_swap *push_swap, int element)
// {
// 	int	count_rot_a;
// 	int	count_rot_b;
// 	int	count_rev_a;
// 	int	count_rev_b;


// }
 
void	smart_allocation(t_push_swap *push_swap, int element)
{
	int			i;
	t_list_node	*centinel;

	i = 0;
	centinel = push_swap->stack_b->first;
	while (i < push_swap->stack_b->size && centinel->value < element)
	{
		centinel = centinel->next;
		i ++;
	}
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

void	smart_push(t_push_swap *push_swap, int element)
{
	int			count_rot;
	t_list_node	*centinel;

	if (push_swap->stack_a->first == NULL)
		return ;
	count_rot = 0;
	centinel = push_swap->stack_a->first;
	while (centinel->value != element)
	{
		centinel = centinel->next;
		count_rot ++;
	}
	if (count_rot > push_swap->stack_a->size /2)
		count_rot = -1;

	while (push_swap->stack_a->first->value != element)
	{
		if (count_rot > 0)
			exec_ra(push_swap);
		else
			exec_rra(push_swap);
	}
	exec_pb (push_swap);
	return ;
}

int	closest_element(t_push_swap *push_swap, int top_value)
{
	int			count_rot;
	int			count_rev;
	t_list_node	*centinel;
	int			element;
	
	centinel = push_swap->stack_a->first;
	count_rot = 0;
	count_rev = 0;
	if (push_swap->stack_a->size == 0)
		return (-1);
	while (centinel->value > top_value && count_rot <=  push_swap->stack_a->size)
	{
		centinel = centinel->next;
		count_rot ++;
	}
	if (count_rot >=  push_swap->stack_a->size)
		return (-1);
	element = centinel->value;
	centinel = push_swap->stack_a->first;
	while (centinel->value >top_value)
	{
		centinel = centinel->prev;
		count_rev ++;
	}
	if (count_rot > count_rev)
		element = centinel->value;
	return (element);
}
