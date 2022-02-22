/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:16:54 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/22 16:52:23 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

int	exec_ra(t_push_swap *push_swap)
{
	if (rotate(push_swap->stack_a) == NULL)
		return (-1);
	add_command(push_swap, "ra\n");
	return (0);
}

int	exec_rb(t_push_swap *push_swap)
{
	if (rotate(push_swap->stack_b) == NULL)
		return (-1);
	add_command(push_swap, "rb\n");
	return (0);
}

int	exec_rr(t_push_swap *push_swap)
{
	if (exec_ra(push_swap) != 0 || exec_rb(push_swap) != 0)
		return (-1);
	return (0);
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
	count_rot *= ((count_rot > stack->size / 2) * -1);
	while (stack->first->value != element)
	{
		if (count_rot >= 0 && stack == push_swap->stack_a)
			exec_ra(push_swap);
		else if (count_rot >= 0)
			exec_rb(push_swap);
		else if (stack == push_swap->stack_a)
			exec_rra(push_swap);
		else
			exec_rrb(push_swap);
	}
}

int	smart_allocation(t_push_swap *push_swap, int element)
{
	t_list_node	*centinel;
	int			max_value;
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
	return (max_value);
}
