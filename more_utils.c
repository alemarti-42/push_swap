/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:21:54 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/23 17:29:02 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_lines(char *str)
{
	int	i;

	i = 0;
	while (*str)
		if (*(str++) == '\n')
			i++;
	return (i);
}

int	return_error(t_push_swap *push_swap)
{
	free_push_swap(push_swap);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}
