/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:16:28 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 18:20:25 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	push_node(t_list_node *new_node, t_list *list)
{
	list->size++;
	if (list->first == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		list->first = new_node;
		return ;
	}
	new_node->next = list->first;
	new_node->prev = list->first->prev;
	list->first->prev->next = new_node;
	list->first->prev = new_node;
	list->first = new_node;
	return ;
}

t_list_node	*pop_node(t_list *list)
{
	t_list_node	*node;

	list->size -= list->size > 0;
	if (list->first == NULL)
		return (NULL);
	node = list->first;
	list->first->prev->next = list->first->next;
	list->first->next->prev = list->first->prev;
	list->first = list->first->next;
	if (list->first == node)
		list->first = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*rotate(t_list *list)
{
	if (list->first)
		list->first = list->first->next;
	return (list);
}

t_list	*rev_rotate(t_list *list)
{
	if (list->first)
		list->first = list->first->prev;
	return (list);
}

void	queue_node(t_list_node *new_node, t_list *list)
{
	push_node(new_node, list);
	rotate(list);
}
