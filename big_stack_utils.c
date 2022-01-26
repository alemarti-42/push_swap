/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:18:38 by alemarti          #+#    #+#             */
/*   Updated: 2022/01/26 16:20:32 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_push_swap *push_swap)
{
	int	*sorted_array;
	//int	i;

	printf("\n[SORT BIG STACK]\n");
	sorted_array = stack_to_array(push_swap->stack_a);
	//print_int_array(sorted_array, push_swap->stack_a->size);
	sort_array(sorted_array, push_swap->stack_a->size);
	//print_int_array(sorted_array, push_swap->stack_a->size);
	stack_to_indexes(push_swap->stack_a, sorted_array);
	//printf("\n");
	//print_list(push_swap->stack_a);
	//print_int_array(sorted_array, push_swap->stack_a->size);
	sorted_array = stack_to_array(push_swap->stack_a);
	sort_array(sorted_array, push_swap->stack_a->size);
	//print_int_array(sorted_array, push_swap->stack_a->size);
	printf("\nCURATED STACK_A \t");
	print_list(push_swap->stack_a);


	//i = 5;
	//printf("NUM:%dINDEX:%d\n", i, value_to_index(i, push_swap->stack_a));
	//printf("\n\t[target order]: \n");
	//print_int_array(sorted_array, push_swap->stack_a->size);
	//print_list(push_swap->stack_a);
	//stack_to_indexes(push_swap->stack_a, sorted_array);
	//print_list(push_swap->stack_a);

	//check_for_duplicates(sorted_array, push_swap->stack_a->size);
	final_sorting(push_swap);
	printf("\n[\\SORT BIG STACK]\n");
	return ;
}

void	stack_to_indexes(t_list *stack, int *sorted_array)
{
	t_list_node	*centinel;
	int			n;
	int			i;

	centinel = stack->first;
	i = stack->size;
	while (i > 0)
	{
		n = 0;
		while (n < stack->size && centinel->value != sorted_array[n])
			n++;
		if (centinel->value == sorted_array[n])
				centinel->value = n;
		i--;
		centinel = centinel->next;
		//centinel->value = value_to_index(centinel->value, stack);
		//centinel = centinel->next;
	}
	return ;
}

int	value_to_index(int value, t_list *stack)
{
	int			i;
	t_list_node	*centinel;

	i = 0;
	centinel = stack->first;
	while (centinel->next != stack->first)
	{
		if (centinel->value == value)
		{
			return (i);
		}
		centinel = centinel->next;
		i++;
	}
	if (centinel->value == value)
	{
		return (i);
	}
	return (-1);
}



void	print_int_array(int *array, int size)
{
	int	i;

	i = 0;
	printf("\nprint_int_array\t");
	while (i < size)
	{
		printf("\t%i", array[i]);
		i++;
	}
	return ;
}
int	*stack_to_array(t_list *stack)
{
	t_list_node	*centinel;
	int			*res;
	int			i;

	centinel = stack->first;
	res = malloc(sizeof(int) * stack->size);
	i = 0;
	while (centinel->next != stack->first)
	{
		res[i] = centinel->value;
		centinel = centinel->next;
		i++;
	}
	res[i] = centinel->value;
	return (res);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	j = 0;
	//for (i = 0; i < n - 1; i++) 
	while (i < size)
	{
		min_idx = i;
		//for (j = i + 1; j < n; j++)
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap_mem(&arr[min_idx], &arr[i]);
		i++;
	}
}

void	swap_mem(int *xp, int *yp)
{
	int	tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

