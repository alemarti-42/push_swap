/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:28:37 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/21 16:40:17 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_list(void)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	res->first = NULL;
	res->last = NULL;
	return (res);
}

t_list_node	*append_element(int element, t_list *list)
{
	t_list_node	*new_node;

	new_node = malloc(sizeof(t_list_node));
	new_node->value = element;
	new_node->next = NULL;
	if (!list->first)
	{
		list->first = new_node;
		list->last = new_node;
		return (new_node);
	}
	list->last->next = new_node;
	list->last = new_node;
	return (new_node);
}

 

void	empty_list(t_list *list)
{
	t_list_node	*swap_head;
	t_list_node	*swap_next;

	if (!list)
		return ;
	swap_head = list->first;
	while (swap_head)
	{
		swap_next = swap_head->next;
		free(swap_head);
		swap_head = swap_next;
	}
	list->first = NULL;
	list->last = NULL;
}

t_list_node	*pop(t_list *list)
{
	t_list_node	*swap_head;

	if (!list->first)
		return (NULL);
	swap_head = list->first;
	list->first = list->first->next;
	swap_head->next = NULL;
	
	return (swap_head);
}
