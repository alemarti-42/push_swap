/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear..c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:09:15 by alemarti          #+#    #+#             */
/*   Updated: 2021/05/25 19:00:57 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swap1;
	t_list	*swap2;

	if (!lst || !del)
		return ;
	swap1 = *lst;
	swap2 = *lst;
	while (swap1)
	{
		swap2 = swap2 -> next;
		del(swap1 -> content);
		free(swap1);
		swap1 = swap2;
	}
	*lst = NULL ;
}
