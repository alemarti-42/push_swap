/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:12:03 by alemarti          #+#    #+#             */
/*   Updated: 2022/01/26 16:22:14 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	exec_phrase(t_push_swap *push_swap, char *phrase)
{
	int 	count;
	char	**commands;
	char	*buf;

	buf = ft_strdup("\0\0\0\0\0");	
	count = 0;
	commands = ft_split(phrase, ' ');
	while (read(0, buf, 3))
	{
		printf("\tCMD: %d  \t--%s--\n", ++count, buf);
		add_command(push_swap, " ");
		exec_command(push_swap, buf);
		print_stacks(push_swap);
		commands++;
	}

	/* while (*commands)
	{
		printf("\tCMD: %d  \t--%s--\n", ++count, *commands);
		add_command(push_swap, " ");
		exec_command(push_swap, *commands);
			
		 if (exec_command(push_swap, *commands) == -1)
			return (-1); 
		print_stacks(push_swap);
		
		commands++;
	} */

	
	return (0);
}

int	main(int argc, char *argv[])
{
	t_push_swap *push_swap;
	int	*sorted_array;
	//char		*commands;

	if (argc > 2)
		return (0);

	push_swap = init_push_swap();

	if (argc == 2)
		push_swap->stack_a = string_tolist(argv[1]);
	if (argc == 1)
		push_swap->stack_a = string_tolist("2 4 3 5 1");
	if (push_swap->stack_a == NULL)
	{
		printf("!ERROR:	NO SE HA PODIDO INICIALIZAR EL PROGRAMA\n");
		return (-1);
	}

	
	
	//commands = "pb pb ra ra ra ra ra pb ra pb ra  pb pb ra pb ra ra pb  ra  pa pa rb rb pa rrb rrb pa rra rb pa pa rra rra pa pa";
	//push_swap->stack_a = string_tolist("1 2 3 4 5 6");

	//commands = "pb pb ra pa pa ra ra sa ra ra";
	//commands = "pb ra pb rra pb ra pa sb pa pa";
	//push_swap->stack_a = string_tolist("2 3 1 5 4");

	/* commands = "pb pb pb ra ra ra pb ra pb ra  ra pb ra pb ra ra sa rra  sb pa pa pa rb rb pa sa sb pa pa pa";
	push_swap->stack_a = string_tolist("2 5 1 8 7 10 3 6 4 9"); */
	
	

	print_stacks(push_swap);
//	exec_phrase(push_swap, commands);
	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	if (check_for_duplicates(sorted_array, push_swap->stack_a->size) == -1)
	{
		printf("!ERROR: NUMEROS REPETIDOS\n");
		//free (push_swap, sorted_array)
		free (sorted_array);
		return (-1);
	}
	free (sorted_array);
	if (stack_is_sorted(push_swap->stack_a) == -1)
	{
		if (push_swap->stack_a->size == 2)
			sort_size_two(push_swap, push_swap->stack_a);
		else if (push_swap->stack_a->size == 3)
			sort_size_three(push_swap, push_swap->stack_a);
		else if (push_swap->stack_a->size <= 6)
			sort_size_six(push_swap);
		else
			sort_big_stack(push_swap);
	}
	
	printf("\n\tpush_swap->commands:\n%s\nSorted:[%d]\nStacks:\n", push_swap->commands, stack_is_sorted(push_swap->stack_a));
	print_stacks(push_swap);
	return (0);
}

int	check_for_duplicates(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] == array[i+1])
		{
			printf("\nDUP: %d", array[i]);
			return (-1);
		}
		i++;
	}
	return (0);
}


