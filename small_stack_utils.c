/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:18:38 by alemarti          #+#    #+#             */
/*   Updated: 2021/11/10 15:26:07 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*sort_size_two(t_push_swap* push_swap)
{
	if (push_swap->stack_a->size != 2)
		return (push_swap);
	
	if (push_swap->stack_a->first->value > push_swap->stack_a->first->next->value)
		exec_command(push_swap, "sa");
	return (push_swap);
}

t_push_swap	*sort_size_three(t_push_swap* push_swap)
{
	if (push_swap->stack_a->size != 3)
		return (push_swap);
	if (push_swap->stack_a->first->value > push_swap->stack_a->first->next->value)
		exec_command(push_swap, "sa");
	return (push_swap);
}