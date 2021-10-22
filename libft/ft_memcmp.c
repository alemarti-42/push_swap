/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:43:02 by alemarti          #+#    #+#             */
/*   Updated: 2021/05/21 13:36:49 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 		str1 > str2 	->	>0
 * 		str1 < str2		->	<0
 * 		str1 == str2	->	=0
 */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)&str1[i] != *(unsigned char *)&str2[i])
			return (*(unsigned char *)&str1[i] - *(unsigned char *)&str2[i]);
		i++;
	}
	return (0);
}
