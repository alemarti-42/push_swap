/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:04:49 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 20:45:19 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	smart_rotate(t_push_swap *push_swap, t_list *stack, long element)
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
		count_rot++;
	}
	if (count_rot > stack->size / 2)
		count_rot = -1;
	printf("countrot: %d\n", count_rot);
	while (stack->first->value != element)
	{
		if (count_rot > 0)
		{
			if (stack == push_swap->stack_a)
				exec_ra(push_swap);
			else
				exec_rb(push_swap);
		}
		else
		{
			if (stack == push_swap->stack_a)
				exec_rra(push_swap);
			else
				exec_rrb(push_swap);
		}
	}
}

long	closest_element(t_push_swap *push_swap, long max_value)
{
	int			count_rot;
	int			count_rev;
	t_list_node	*centinel;
	int			element;

	centinel = push_swap->stack_a->first;
	count_rot = 0;
	count_rev = 0;
	element = 0;
	if (push_swap->stack_a->size == 0)
		return (-1);
	while (centinel->value > max_value && count_rot <= push_swap->stack_a->size \
	&& count_rot++)
	{
		printf("count_rot: %d\n", count_rot);
		centinel = centinel->next;
	}
	if (count_rot > push_swap->stack_a->size)
		return (-1);
	element = centinel->value;
	centinel = push_swap->stack_a->first;
	while (centinel->value > max_value && count_rev++)
		centinel = centinel->prev;
	if (count_rot > count_rev)
		element = centinel->value;
	//printf("closest %d\n", element);
	return (element);
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

void	sorter(t_push_swap *push_swap)
{
	if (push_swap->stack_a->size == 2)
		sort_size_two(push_swap, push_swap->stack_a);
	else if (push_swap->stack_a->size == 3)
		sort_size_three(push_swap, push_swap->stack_a);
	else if (push_swap->stack_a->size <= 6)
		sort_size_six(push_swap);
	else
		sort_big_stack(push_swap);
}
