/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:55:49 by alemarti          #+#    #+#             */
/*   Updated: 2021/05/24 19:05:18 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nsize(long n);

char	*ft_itoa(int n)
{
	char	*res;
	size_t	size;
	long	nb;

	size = nsize(n);
	res = (char *)malloc(size + 1);
	nb = n;
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	res[size] = 0;
	size--;
	while (nb > 9)
	{
		res[size] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	res[size] = nb + '0';
	return (res);
}

static size_t	nsize(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
