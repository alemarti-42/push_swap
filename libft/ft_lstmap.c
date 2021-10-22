/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:11:36 by alemarti          #+#    #+#             */
/*   Updated: 2021/05/25 20:39:30 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*swap;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		swap = ft_lstnew((f)(lst -> content));
		if (!swap)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, swap);
		lst = lst -> next;
		swap = swap -> next;
	}
	return (res);
}
