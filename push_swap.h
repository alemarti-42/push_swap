/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:59 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 18:47:29 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include <stdio.h>

# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>

# include "./pslib/pslib.h"
# include "./pslib/libft/libft.h"

//push_swap.c
int			count_lines(char *str);
char		*join_args(int argc, char *argv[]);
int			check_for_duplicates(long *array, int size);

//small_stack_utils.c
void		sort_size_two(t_push_swap *push_swap, t_list *stack);
void		sort_size_three(t_push_swap *push_swap, t_list *stack);
t_push_swap	*sort_size_six(t_push_swap *push_swap);
t_push_swap	*merge_sorted_stacks(t_push_swap *push_swap);

//big_stack_utils.c
void		sort_big_stack(t_push_swap *push_swap);
void		stack_to_indexes(t_list *stack, long *sorted_array);
int			value_to_index(int value, t_list *stack);
void		print_int_array(int *array, int size);
long		*stack_to_array(t_list *stack);
void		sort_array(long arr[], int n);
//void 	swap_mem(int* xp, int* yp);

//big_sorting.c
void		final_sorting(t_push_swap *push_swap);
void		selection_sort(t_push_swap *push_swap, int pivot);
int			smart_allocation(t_push_swap *push_swap, int element);
void		smart_push(t_push_swap *push_swap, int element);
void		smart_rotate(t_push_swap *push_swap, t_list *stack, int element);
int			closest_element(t_push_swap *push_swap, int max_value);
#endif