/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:16:54 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 18:24:43 by alemarti         ###   ########.fr       */
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
