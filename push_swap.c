/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:12:03 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 20:20:04 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (res);
}

int	check_all_int(t_list *stack)
{
	t_list_node	*centinel;
	int			tracker;

	tracker = 0;
	centinel = stack->first;
	while (tracker < stack->size)
	{
		if (centinel->value > 2147483647)
			return (-1);
		centinel = centinel->next;
		tracker++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_push_swap	*push_swap;
	long		*sorted_array;

	if (argc <= 1)
		return (-1);
	push_swap = init_push_swap();
	push_swap->stack_a = string_tolist(join_args(argc, argv));
	if (push_swap->stack_a == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	if (check_for_duplicates(sorted_array, push_swap->stack_a->size) == -1 || \
	check_all_int(push_swap->stack_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (stack_is_sorted(push_swap->stack_a) == -1)
		sorter(push_swap);
	ft_putstr_fd(push_swap->commands, 1);
	return (0);
}

int	check_for_duplicates(long *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] == array[i + 1])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
