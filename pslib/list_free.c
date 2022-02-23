/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:08:56 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/23 19:11:21 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	free_stack(t_list *stack)
{
	t_list_node	*centinel;
	t_list_node	*swap;

	if (stack->size == 0)
	{
		free (stack);
		return ;
	}
	centinel = stack->first;
	centinel->prev->next = 0;
	while (centinel)
	{
		swap = centinel;
		centinel = centinel->next;
		free(swap);
	}
	free(stack);
}

void	free_push_swap(t_push_swap *push_swap)
{
	if (!push_swap)
		return ;
	if (push_swap->stack_a)
		free_stack(push_swap->stack_a);
	if (push_swap->stack_b)
		free_stack(push_swap->stack_b);
	free(push_swap->commands);
	free (push_swap);
}
