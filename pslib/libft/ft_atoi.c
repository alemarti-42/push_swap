/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:02:33 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 18:19:19 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_size(long res, int sign);

long	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (check_size(res, sign) == -1)
			return (2147483650);
	}
	res *= sign;
	return ((int)res);
}

static int	check_size(long res, int sign)
{
	if ((res > 2147483647 && sign == 1) || res > 2147483648)
		return (-1);
	return (1);
}
