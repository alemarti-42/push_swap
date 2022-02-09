/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:17:10 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/09 20:16:45 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void	final_sorting(t_push_swap *push_swap)
{
	int	chunk_size;
	int	n_chunks;
	int	pivot;

	n_chunks = 1;
	while (n_chunks * n_chunks < push_swap->stack_a->size)
		n_chunks ++;
	chunk_size = push_swap->stack_a->size / n_chunks;
	pivot = chunk_size - 1;
	//while (push_swap->stack_a->size > 0)
	//{
		selection_sort(push_swap, n_chunks);
		//pivot += chunk_size;
	//}
	//while (push_swap->stack_b->size > 0)
	//	exec_pa(push_swap);
	printf("CHUNKS: %d\n", n_chunks);
	return ;
}

void	selection_sort(t_push_swap *push_swap, int n_chunks)
{
	//int	i;
	int	next_element;
	int	chunk_size;
	int pivot;

	chunk_size = push_swap->stack_a->size / n_chunks;
	pivot = 0;
	
	while (push_swap->stack_a->size > 0)
	{
		pivot += chunk_size;
		next_element = closest_element(push_swap, pivot);
		while (next_element >= 0)
		{
			//printf("SELECTION SORT: next elem: %d, pivot %d", next_element, pivot);
			//smart_allocation(push_swap, next_element);
			smart_push(push_swap, next_element);
			//next_element = closest_element(push_swap, pivot);
			next_element = closest_element(push_swap, pivot);
		}
	}
	while (push_swap->stack_b->first->value < push_swap->stack_b->first->prev->value)
		exec_rrb(push_swap);
	while (push_swap->stack_b->size > 0)
		exec_pa(push_swap);
	
	return ;
}


 
int	smart_allocation(t_push_swap *push_swap, int element)
{
	//t_list_node	*head_b;
	t_list_node	*centinel;
	int			max_value;
	int			i;

	//int			target_element;

	//head_b = push_swap->stack_b->first;
	if (push_swap->stack_b->size == 0)
		return (0);
	i = 0;
	centinel = push_swap->stack_b->first;
	max_value = push_swap->stack_b->first->value;
	//printf("SMART ALLOC1:\t%d\n", element);
	
	while (i < push_swap->stack_b->size)
	{
		if (centinel->prev->value > element && centinel->value < element)
			return(centinel->value);
		if (centinel->value > max_value)
			max_value = centinel->value;
		centinel = centinel->next;
		i++;
	}
	//printf("SMART ALLOC MAX VAL: %d\n", max_value);
	return(max_value);

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
	// int			count_rot;
	// t_list_node	*centinel;

	// if (push_swap->stack_a->first == NULL)
	// 	return ;
	// count_rot = 0;
	// centinel = push_swap->stack_a->first;
	// while (centinel->value != element)
	// {
	// 	centinel = centinel->next;
	// 	count_rot ++;
	// }
	// if (count_rot > push_swap->stack_a->size /2)
	// 	count_rot = -1;

	// while (push_swap->stack_a->first->value != element)
	// {
	// 	if (count_rot > 0)
	// 		exec_ra(push_swap);
	// 	else
	// 		exec_rra(push_swap);
	// }
	smart_rotate(push_swap, push_swap->stack_a, element);
	smart_rotate(push_swap, push_swap->stack_b, smart_allocation(push_swap, element));
	exec_pb (push_swap);
	return ;
}

void	smart_rotate(t_push_swap *push_swap, t_list *stack, int element)
{
	int			count_rot;
	t_list_node	*centinel;

	
	if (stack->first == NULL)
		return ;
	count_rot = 0;
	centinel = stack->first;
	while (centinel->next != stack->first && centinel->value != element)
	{
		centinel = centinel->next;
		count_rot ++;
	}
	if (count_rot > stack->size /2)
		count_rot = -1;

	while (stack->first->value != element)
	{
		//printf("element smart rotate\t%d\n", element);
		if (count_rot > 0)
			if (stack == push_swap->stack_a)
				exec_ra(push_swap);
			else
				exec_rb(push_swap);
		else
			if (stack == push_swap->stack_a)
				exec_rra(push_swap);
			else
				exec_rrb(push_swap);
	}
}

int	closest_element(t_push_swap *push_swap, int max_value)
{
	int			count_rot;
	int			count_rev;
	t_list_node	*centinel;
	int			element;
	
	centinel = push_swap->stack_a->first;
	count_rot = 0;
	count_rev = 0;
	element = 0;
	//printf("MINVALUE CLOSEST ELEMNT %d\n", max_value);
	if (push_swap->stack_a->size == 0)
		return (-1);
	while (centinel->value > max_value && count_rot <=  push_swap->stack_a->size)
	{
		centinel = centinel->next;
		count_rot ++;
	}
	if (count_rot >  push_swap->stack_a->size)
	{
		//printf("-- chunk completo pivot: %d --\n", max_value);
		return (-1);
	}
	element = centinel->value;
	centinel = push_swap->stack_a->first;
	while (centinel->value > max_value)
	{
		centinel = centinel->prev;
		count_rev ++;
	}
	if (count_rot > count_rev)
		element = centinel->value;
	return (element);
}
