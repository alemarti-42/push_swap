/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:59:59 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/23 16:11:40 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		sizebytes;
	void		*res;

	sizebytes = size * count;
	res = malloc(sizebytes);
	if (!res)
		return (0);
	ft_memset(res, 0, sizebytes);
	return (res);
}
