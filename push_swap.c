/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:12:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/26 15:59:02 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	exec_phrase(t_push_swap *push_swap, char *phrase)
{
	int 	count;
	char	**commands;
	
	count = 0;
	commands = ft_split(phrase, ' ');
	while (*commands)
	{
		printf("\tCMD: %d  \t--%s--\n", ++count, *commands);
		if (exec_command(push_swap, *commands) == -1)
			return (-1);
		print_stacks(push_swap);
		
		commands++;
	}
	return (0);
}

int	main(void)
{


	t_push_swap *push_swap;
	char		*commands;

	push_swap = init_push_swap();
	//commands = "pb pb ra ra ra ra ra pb ra pb ra  pb pb ra pb ra ra pb  ra  pa pa rb rb pa rrb rrb pa rra rb pa pa rra rra pa pa";
	//push_swap->stack_a = string_tolist("1 2 3 4 5 6");

	//commands = "pb pb ra pa pa ra ra sa ra ra";
	//commands = "pb ra pb rra pb ra pa sb pa pa";
	//push_swap->stack_a = string_tolist("2 3 1 5 4");

	commands = "pb pb pb ra ra ra pb ra pb ra  ra pb ra pb ra ra sa rra  sb pa pa pa rb rb pa sa sb pa pa pa";
	push_swap->stack_a = string_tolist("2 5 1 8 7 10 3 6 4 9");

	print_stacks(push_swap);
	exec_phrase(push_swap, commands);

	return (0);
}


