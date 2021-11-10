/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:28:37 by alemarti          #+#    #+#             */
/*   Updated: 2021/11/10 15:37:37 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FOR TESTING
void print_stacks(t_push_swap *push_swap)
{
	printf("[A]size:%d:\t", push_swap->stack_a->size);
	print_list(push_swap->stack_a);
	printf("[B]size:%d:\t", push_swap->stack_b->size);
	print_list(push_swap->stack_b);
}
//

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->size = 0;
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

t_list	*rev_rotate(t_list *list)
{
	
	if (list->first)
		list->first = list->first->prev;
	return (list);
}

t_list	*rotate(t_list *list)
{
	if (list->first)
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

	if (list->first == NULL)
	{
		printf("\t(empty)\n");
		return ;
	}
	
	reader = list->first;
/* 	reader = list->first;
	printf("\t\t%d\n", reader->value); */
	while (reader->next != list->first)
	{
		printf("\t%d", reader->value);
		reader = reader->next;
	}
	printf("\t%d\n", reader->value);
	return ;
}


t_list	*string_tolist(char* str)
{
	char	**chopped;
	t_list	*res;

	res = new_list();
	chopped = NULL;
	chopped = ft_split(str, ' ');
	printf("[TEST]STRING: %s\n", str);
	while(*chopped)
	{
		printf("[TEST]ATOI: %d\n", ft_atoi(*chopped));

		queue_node(new_node(ft_atoi(*chopped)), res);
		free(*chopped);
		chopped++;
	}
	return (res);
}

int		stack_is_ordered(t_list *stack)
{
	t_list_node	*sentinel;

	if (!stack->first)
		return (-1);
	sentinel = stack->first;
	while (sentinel->next && sentinel->next != stack->first)
	{
		if (sentinel->next->value < sentinel->value)
		{
			return (-1);
		}
		sentinel = sentinel->next;
	}
	return (0);
}