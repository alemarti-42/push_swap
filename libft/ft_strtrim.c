/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:52:30 by alemarti          #+#    #+#             */
/*   Updated: 2021/05/22 21:19:01 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		firstchar;
	char	*res;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[i]) && s1[i] != 0)
		i++;
	firstchar = i;
	if (s1[i] == 0)
		return (ft_strdup(""));
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i > firstchar)
		i--;
	res = ft_substr(s1, firstchar, i - firstchar + 1);
	return (res);
}
