/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:12:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/22 19:06:01 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(void)
{
	t_push_swap *push_swap;
	char		**commands;
	//t_list_node	*swap;

	commands = ft_split("sa\npb\npb\npb\nrr\nrrr\nsa\npa\npa\npa", '\n');

	push_swap = init_push_swap();
 	push_node(new_node(8), push_swap->stack_a);
	push_node(new_node(5), push_swap->stack_a);
	push_node(new_node(6), push_swap->stack_a);
	push_node(new_node(3), push_swap->stack_a);
	push_node(new_node(1), push_swap->stack_a);
	push_node(new_node(2), push_swap->stack_a);

	print_list(push_swap->stack_a);
	print_list(push_swap->stack_b);
	
	while (*commands)
	{
		printf("\t%s\n", *commands);
		exec_command(push_swap, *commands);
		print_list(push_swap->stack_a);
		print_list(push_swap->stack_b);
		
		commands++;
	}
	/* exec_command(push_swap, "sa");
	exec_command(push_swap, "pb");
	exec_command(push_swap, "pb");
	exec_command(push_swap, "pb");
	exec_command(push_swap, "rr");
	exec_command(push_swap, "rrr");
	exec_command(push_swap, "sa");
	exec_command(push_swap, "pa");
	exec_command(push_swap, "pa");
	exec_command(push_swap, "pa"); */



	
/*	
	queue_node(new_node(1), stack_b);
	queue_node(new_node(2), stack_b);
	queue_node(new_node(3), stack_b);
	queue_node(new_node(4), stack_b);
	queue_node(new_node(5), stack_b);
	queue_node(new_node(6), stack_b);

	push_node(pop_node(stack_a), stack_b);
	print_list(stack_a);
	print_list(stack_b); */

	/* push_node(new_node(1), lista);
	push_node(new_node(2), lista);
	push_node(new_node(3), lista);
	push_node(new_node(4), lista);
	push_node(new_node(5), lista);
	queue_node(new_node(6), lista);
	print_list(lista);
	printf("POP:\t%d\n", pop_node(lista)->value);
	printf("POP:\t%d\n", pop_node(lista)->value);
	printf("POP:\t%d\n", pop_node(lista)->value);
	print_list(lista);
	rotate(lista);
	print_list(lista);
	printf("POP:\t%d\n", pop_node(lista)->value);
	printf("POP:\t%d\n", pop_node(lista)->value);
	printf("POP:\t%d\n", pop_node(lista)->value);
	printf("POP:\t%p\n", pop_node(lista));
	push_node(new_node(1), lista);
	print_list(lista);
	printf("POP:\t%p\n", pop_node(lista));
	printf("POP:\t%p\n", pop_node(lista));
	printf("POP:\t%p\n", pop_node(lista));
	print_list(lista); */


	/* printf("POP:\t%d\n", pop_node(lista)->value);
	printf("POP:\t%d\n", pop_node(lista)->value);
	printf("POP:\t%d\n", pop_node(lista)->value); */



	return (0);
}


