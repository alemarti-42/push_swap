/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_interpreter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:49:23 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/22 18:45:01 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*init_push_swap(void)
{
	t_push_swap	*new_push_swap;

	new_push_swap = malloc(sizeof(t_push_swap));
	new_push_swap->stack_a = new_list();
	new_push_swap->stack_b = new_list();
	return (new_push_swap);
}

int	exec_command(t_push_swap *push_swap, char *command)
{
	if (command[0] == 's')
	{
		if (command[1] == 'a')
			return (exec_sa(push_swap));
		if (command[1] == 'b')
			return (exec_sb(push_swap));
		if (command[1] == 's')
			return (exec_ss(push_swap));
	}
	if (command[0] == 'p')
	{
		if (command[1] == 'a')
			return (exec_pa(push_swap));
		if (command[1] == 'b')
			return (exec_pb(push_swap));
	}
	if (command[0] == 'r')
	{
		if (command[1] == 'a')
			return (exec_ra(push_swap));
		if (command[1] == 'b')
			return (exec_rb(push_swap));
		if (command[1] == 'r')
		{
			if (command[2] == 0)
				return (exec_rr(push_swap));
			if (command[2] == 'a')
				return (exec_rra(push_swap));
			if (command[2] == 'b')
				return (exec_rrb(push_swap));
			if (command[2] == 'r')
				return (exec_rrr(push_swap));
		}
	}
	return (-1);
}

int	exec_swap(t_list *stack)
{
	t_list_node	*swap;

	swap = pop_node(stack);
	if (swap == NULL)
		return (-1);
	rotate(stack);
	push_node(swap, stack);
	rev_rotate(stack);
	return (0);
}

int	exec_sa(t_push_swap *push_swap)
{
	return (exec_swap(push_swap->stack_a));
}

int	exec_sb(t_push_swap *push_swap)
{
	return (exec_swap(push_swap->stack_b));
}

int	exec_ss(t_push_swap *push_swap)
{
	if (exec_sa(push_swap) != 0 || exec_sb(push_swap) != 0)
		return (-1);
	return (0);
}

int	exec_push(t_list *stack_src, t_list *stack_dst)
{
	t_list_node	*swap;

	swap = pop_node(stack_src);
	if (swap == NULL)
		return (-1);
	push_node(swap, stack_dst);
	return (0);
}

int	exec_pa(t_push_swap *push_swap)
{
	return (exec_push(push_swap->stack_b, push_swap->stack_a));
}

int	exec_pb(t_push_swap *push_swap)
{
	return (exec_push(push_swap->stack_a, push_swap->stack_b));
}

int	exec_ra(t_push_swap *push_swap)
{
	if (rotate(push_swap->stack_a) == NULL)
		return (-1);
	return (0);
}

int	exec_rb(t_push_swap *push_swap)
{
	if (rotate(push_swap->stack_b) == NULL)
		return (-1);
	return (0);
}

int	exec_rr(t_push_swap *push_swap)
{
	if (exec_ra(push_swap) != 0 || exec_rb(push_swap) != 0)
		return (-1);
	return (0);
}

int	exec_rra(t_push_swap *push_swap)
{
	if (rev_rotate(push_swap->stack_a) == NULL)
		return (-1);
	return (0);
}

int	exec_rrb(t_push_swap *push_swap)
{
	if (rev_rotate(push_swap->stack_b) == NULL)
		return (-1);
	return (0);
}

int	exec_rrr(t_push_swap *push_swap)
{
	if (exec_rra(push_swap) != 0 || exec_rrb(push_swap) != 0)
		return (-1);
	return (0);
}

