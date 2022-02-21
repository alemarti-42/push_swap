/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:16:46 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 18:23:22 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->size = 0;
	list->first = NULL;
	return (list);
}

t_list_node	*new_node(long element)
{
	t_list_node	*list_node;

	list_node = malloc(sizeof(t_list_node));
	list_node->value = element;
	list_node->next = NULL;
	list_node->prev = NULL;
	return (list_node);
}

int	check_only_digits(char *str)
{
	while (*str && ((*str >= '0' && *str <= '9') || \
	*str == ' ' || *str == '-' || *str == '+'))
	{
		if (*str == '+' || *str == '-' )
			if (*(str - 1) != ' ' || (*(str + 1) < '0' || *(str + 1) > '9'))
				return (-1);
		str ++;
	}
	if (*str == 0)
		return (0);
	return (-1);
}

int	stack_is_sorted(t_list *stack)
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
	return (1);
}
