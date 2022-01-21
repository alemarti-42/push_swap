/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:17:10 by alemarti          #+#    #+#             */
/*   Updated: 2022/01/21 18:01:46 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void	final_sorting(t_push_swap *push_swap, int *sorted_array)
{
	int	chunk_size;
	int	n_chunks;

	n_chunks = 5;

	chunk_size = push_swap->stack_a->size / n_chunks;
	chunk_size += push_swap->stack_a->size % n_chunks != 0;
	
	push_swap = NULL;
	sorted_array = NULL;
	return ;
}


