/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:18:38 by alemarti          #+#    #+#             */
/*   Updated: 2021/11/10 15:26:07 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_push_swap* push_swap)
{
    int *sorted_array;
    int i;

    printf("\nBUUUUUUG\n");
    sorted_array = stack_to_array(push_swap->stack_a);
    sort_array(sorted_array, push_swap->stack_a->size);
    i = 5;
    printf("NUM:%dINDEX:%d\n", i, value_to_index(i, push_swap->stack_a));
    return ;
}

int *stack_to_array(t_list *stack)
{
    t_list_node *centinel;
    int         *res;
    int         i;

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

void sort_array(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;

    *xp = *yp;
    *yp = temp;
}

int value_to_index(int value , t_list *stack)
{
    int         i;
    t_list_node *centinel;

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

