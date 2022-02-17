/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:12:03 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/09 20:57:59 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	exec_phrase(t_push_swap *push_swap, char *phrase)
{
	char	**commands;
	char	*buf;

	buf = ft_strdup("\0\0\0\0\0");
	commands = ft_split(phrase, ' ');
	while (read(0, buf, 3))
	{
		//printf("\tCMD: %d  \t--%s--\n", ++count, buf);
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

int	count_lines(char *str)
{
	int	i;

	i = 0;
	while (*str)
		if (*(str++) == '\n')
			i++;
	return (i);
}

char	*join_args(int argc, char *argv[])
{
	int		i;
	char	*res;
	char	*swap;

	i = 1;
	res = malloc(1);
	*res = 0;
	while (i < argc)
	{
		swap = ft_strjoin(res, argv[i]);
		free(res);
		res = swap;
		swap = ft_strjoin(res, " ");
		free(res);
		res = swap;
		i++;
	}
	//printf("RES: %s\n", res);
	return (res);
}

// char	*simplify_rotations(char *commands)
// {
// 	int	i;
// 	int	next_rot;
// 	int	next_rev;

// 	i = 0;
// 	next_rot = -1;
// 	next_rev = -1;
// 	while(commands[i])
// 	{
// 		if (commands[i] == 'r')
// 		{
// 			if (commands[i] == 'r')
// 			{
// 				if (commands[i] == 'a')
// 					next_rev == 1;
// 				if (commands[i] == 'b' && next_rev == 1)
// 			}
// 		}
// 		i++;
// 	}

// }

int	main(int argc, char *argv[])
{
	t_push_swap *push_swap;
	int	*sorted_array;
	//int	n_commands;
	//char		*commands;

	if (argc <= 1)
		return (-1);
	push_swap = init_push_swap();
	
	// if (argc == 2)
	// 	push_swap->stack_a = string_tolist(argv[1]);

	push_swap->stack_a = string_tolist(join_args(argc, argv));
	
	if (push_swap->stack_a == NULL)
	{
		ft_putstr_fd("Fallo inicializacion\n", 2);
		ft_putstr_fd("Error\n", 1);
		//system("leaks push_swap");
		return (-1);
	}

	//print_stacks(push_swap);
//	exec_phrase(push_swap, commands);
	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	if (check_for_duplicates(sorted_array, push_swap->stack_a->size) == -1)
	{
		//printf("!ERROR: NUMEROS REPETIDOS\n");
		ft_putstr_fd("Numeros repetidos\n", 2);
		ft_putstr_fd("Error\n", 1);
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
	//push_swap->commands = simplify_rotations(push_swap->commands);
		

	//n_commands = count_lines(push_swap->commands);
	//printf("\n\tpush_swap->commands:\n%s\n", push_swap->commands);
	ft_putstr_fd(push_swap->commands, 1);
	//printf("\n\tsize %d \n\t%d commands\n\tSorted:[%d]\n",push_swap->stack_a->size, n_commands, stack_is_sorted(push_swap->stack_a));
	
	//print_stacks(push_swap);
	//system("leaks push_swap");
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
			return (-1);
		}
		i++;
	}
	return (0);
}


