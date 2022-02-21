/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:18:38 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 19:30:06 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size_two(t_push_swap *push_swap, t_list *stack)
{
	if (stack->size != 2)
		return ;
	if (stack->first->value > stack->first->next->value)
	{
		if (stack == push_swap->stack_a)
			exec_command(push_swap, "sa");
		if (stack == push_swap->stack_b)
			exec_command(push_swap, "sb");
	}
	return ;
}

void	sort_size_three(t_push_swap *push_swap, t_list *stack)
{
	char	**commands;

	if (stack == push_swap->stack_a)
		commands = ft_split("sa ra rra", ' ');
	if (stack == push_swap->stack_b)
		commands = ft_split("sb rb rrb", ' ');
	while (stack_is_sorted(stack) == -1)
		if (stack->first->value < stack->first->next->value \
			&& stack->first->value < stack->first->prev->value)
			exec_command(push_swap, commands[0]);
	else if (stack->first->value > stack->first->next->value \
			&& stack->first->value > stack->first->prev->value)
	{
		if (stack->first->next->value < stack->first->prev->value)
			exec_command(push_swap, commands[1]);
		else if (stack->first->next->value > stack->first->prev->value)
			exec_command(push_swap, commands[0]);
	}
	else if (stack->first->value < stack->first->next->value \
		&& stack->first->value > stack->first->prev->value)
		exec_command(push_swap, commands[2]);
	else if (stack->first->value > stack->first->next->value \
		&& stack->first->value < stack->first->prev->value)
		exec_command(push_swap, commands[0]);
	return ;
}

t_push_swap	*sort_size_six(t_push_swap *push_swap)
{
	if (push_swap->stack_a->size > 6)
		return (push_swap);
	while (push_swap->stack_a->size > 3)
		exec_command(push_swap, "pb");
	sort_size_three(push_swap, push_swap->stack_a);
	if (push_swap->stack_b->size == 3)
		sort_size_three(push_swap, push_swap->stack_b);
	else if (push_swap->stack_b->size == 2)
		sort_size_two(push_swap, push_swap->stack_b);
	merge_sorted_stacks(push_swap);
	print_stacks(push_swap);
	return (push_swap);
}

t_push_swap	*merge_sorted_stacks(t_push_swap *push_swap)
{
	t_list_node	*swap;

	if (push_swap->stack_a->first->value < push_swap->stack_b->first->value)
		swap = push_swap->stack_a->first;
	else
		swap = push_swap->stack_b->first;
	if (push_swap->stack_a->first == swap)
		exec_command(push_swap, "ra");
	while (push_swap->stack_b->first != NULL )
	{
		if (push_swap->stack_b->first->value < push_swap->stack_a->first->value \
			|| push_swap->stack_a->first == swap)
		{
			exec_command(push_swap, "pa");
		}
		if (push_swap->stack_b->first != NULL && \
		push_swap->stack_b->first->value > push_swap->stack_a->first->value)
			exec_command(push_swap, "ra");
	}
	while (push_swap->stack_a->first->prev->value < \
	push_swap->stack_a->first->value)
	{
		exec_command(push_swap, "ra");
	}
	return (push_swap);
}
