/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:59 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/22 17:14:32 by alemarti         ###   ########.fr       */
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
char		*join_args(int argc, char *argv[]);
int			check_all_int(t_list *stack);
int			check_for_duplicates(long *array, int size);

//small_stack_utils.c
void		sort_size_two(t_push_swap *push_swap, t_list *stack);
void		sort_size_three(t_push_swap *push_swap, t_list *stack);
t_push_swap	*sort_size_six(t_push_swap *push_swap);
t_push_swap	*merge_sorted_stacks(t_push_swap *push_swap);
int			count_lines(char *str);

//big_stack_utils.c
void		stack_to_indexes(t_list *stack, long *sorted_array);
int			value_to_index(int value, t_list *stack);
long		*stack_to_array(t_list *stack);
void		sort_array(long arr[], int n);
//		void		print_int_array(int *array, int size);

//big_sorting.c
void		final_sorting(t_push_swap *push_swap);
void		selection_sort(t_push_swap *push_swap, int pivot);
int			get_biggest_node(t_list *stack);
int			closest_element(t_push_swap *push_swap, int max_value);
void		sort_big_stack(t_push_swap *push_swap);
#endif