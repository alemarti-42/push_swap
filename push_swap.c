/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:12:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/21 16:44:04 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	t_list_node	*swap_head;
	t_list_node	*swap_next;

	if (!list)
		return;
	printf("\t\tLISTA\n");
	swap_head = list->first;
	while (swap_head)
	{
		swap_next = swap_head->next;
		printf("\t%d\n", swap_head->value);
		swap_head = swap_next;
	}
}

int	main(void)
{
	t_list *lista;

	lista = new_list();
	append_element(1, lista);
	append_element(2, lista);
	append_element(3, lista);
	append_element(4, lista);
	append_element(5, lista);
	print_list(lista);
	printf("\n\t\tPOP:\t%p\n", pop(lista));
	printf("\n\t\tPOP:\t%p\n", pop(lista));
		printf("\n\t\tPOP:\t%p\n", pop(lista));
	printf("\n\t\tPOP:\t%p\n", pop(lista));
		printf("\n\t\tPOP:\t%p\n", pop(lista));
	printf("\n\t\tPOP:\t%p\n", pop(lista));

	
	
	/* printf("\n\t\tPOP:\t%d\n", pop(lista)->value);
	printf("\n\t\tPOP:\t%d\n", pop(lista)->value);
	printf("\n\t\tPOP:\t%d\n", pop(lista)->value);
	printf("\n\t\tPOP:\t%d\n", pop(lista)->value);
	printf("\n\t\tPOP:\t%d\n", pop(lista)->value);
	printf("\n\t\tPOP:\t%d\n", pop(lista)->value); */
	//printf("\n\t\tPOP:\t%p\n", pop(lista));

	print_list(lista);
	return (0);
}


