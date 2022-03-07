/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:21:54 by alemarti          #+#    #+#             */
/*   Updated: 2022/03/07 13:54:16 by alemarti         ###   ########.fr       */
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

void	free_split(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}
