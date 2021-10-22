/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:28:37 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/22 17:49:59 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->count_elements = 0;
	list->first = NULL;
	return (list);
}

t_list_node	*new_node(int element)
{
	t_list_node	*list_node;

	list_node = malloc(sizeof(t_list_node));
	list_node->value = element;
	list_node->next = NULL;
	list_node->prev = NULL;
	return (list_node);
}

void	push_node(t_list_node *new_node, t_list *list)
{
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
}

t_list_node	*pop_node(t_list *list)
{
	t_list_node	*node;

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

t_list	*rev_rotate(t_list *list)
{
	list->first = list->first->prev;
	return (list);
}

t_list	*rotate(t_list *list)
{
	list->first = list->first->next;
	return (list);
}

void	queue_node(t_list_node *new_node, t_list *list)
{
	push_node(new_node, list);
	rotate(list);
}

void print_list(t_list *list)
{
	t_list_node *reader;

	printf("\t\tLIST\n");
	if (list->first == NULL)
	{
		printf("\t\t(empty)\n");
		return ;
	}
	
	reader = list->first;
/* 	reader = list->first;
	printf("\t\t%d\n", reader->value); */
	while (reader->next != list->first)
	{
		printf("\t\t%d\n", reader->value);
		reader = reader->next;
	}
	printf("\t\t%d\n", reader->value);
	return ;
}
/* t_list	*new_list(void)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	res->first = NULL;
	return (res);
}

t_list_node	*new_node(int element)
{
	t_list_node	*node;

	node = malloc(sizeof(t_list_node));
	node->value = element;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void push(t_list_node *node, t_list *list)
{
	if (!list->first)
	{
		list->first = node;
		node->next = node;
		return ;
	} */
	
	

/* void	free_list_nodes(t_list *list)
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

void	push(t_list_node *list_node, t_list *list)
{
	list_node->next = list->first;
	list->first = list_node;
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

void	rotate(t_list *list)
{
	list->last->next = list->first;
	list->last = list->last->next;
	list->first = list->first->next;
	list->last->next = NULL;
}
 */