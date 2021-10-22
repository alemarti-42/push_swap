/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:50:40 by alemarti          #+#    #+#             */
/*   Updated: 2021/05/25 17:06:59 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pl;

	pl = *lst;
	if (!pl)
	{
		*lst = new;
		return ;
	}
	while (pl -> next)
		pl = pl -> next;
	pl -> next = new;
}
