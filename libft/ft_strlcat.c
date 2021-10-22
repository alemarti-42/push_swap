/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:09:26 by alemarti          #+#    #+#             */
/*   Updated: 2021/05/21 21:29:16 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	j = 0;
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	dstlen = i;
	if (dstsize == 0)
		return (dstlen + ft_strlen(src));
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstlen < dstsize)
		dst[i] = 0;
	return (dstlen + ft_strlen(src));
}
