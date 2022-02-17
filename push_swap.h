/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:59 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/09 19:22:08 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include <stdio.h>

# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>

#include "./libft/libft.h"

typedef struct s_push_swap
{
	char			*commands;
	struct s_list	*stack_a;
	struct s_list	*stack_b;
}					t_push_swap;


typedef struct s_list
{
	int					size;
	struct s_list_node	*first;
	/* struct s_list_node	*min;
	struct s_list_node	*max; */
}					t_list;

typedef struct s_list_node
{
	int					value;
	struct s_list_node	*prev;
	struct s_list_node	*next;
}					t_list_node;

//push_swap.c
int			exec_phrase(t_push_swap *push_swap, char *phrase);
int	count_lines(char *str);
char	*join_args(int argc, char *argv[]);
int			check_for_duplicates(int *array, int size);


//list_utils.c
void		 print_stacks(t_push_swap *push_swap);

t_list		*new_list(void);
t_list_node	*new_node(int element);
void		push_node(t_list_node *new_node, t_list *list);
t_list_node	*pop_node(t_list *list);
t_list		*rotate(t_list *list);
t_list		*rev_rotate(t_list *list);
void		queue_node(t_list_node *new_node, t_list *list);
void 		print_list(t_list *list);
int			check_only_digits(char *str);
t_list		*string_tolist(char* str);
int			stack_is_sorted(t_list *stack);


//push_swap_interpreter.c


void	add_command(t_push_swap *push_swap, char *cmd);

t_push_swap	*init_push_swap(void);
int	exec_command(t_push_swap *push_swap, char *command);
int	exec_swap(t_list *stack);
int	exec_sa(t_push_swap *push_swap);
int	exec_sb(t_push_swap *push_swap);
int	exec_ss(t_push_swap *push_swap);

int	exec_push(t_list *stack_src, t_list *stack_dst);
int	exec_pa(t_push_swap *push_swap);
int	exec_pb(t_push_swap *push_swap);

int	exec_ra(t_push_swap *push_swap);
int	exec_rb(t_push_swap *push_swap);
int	exec_rr(t_push_swap *push_swap);
int	exec_rra(t_push_swap *push_swap);
int	exec_rrb(t_push_swap *push_swap);
int	exec_rrr(t_push_swap *push_swap);

//small_stack_utils.c
void		sort_size_two(t_push_swap* push_swap, t_list *stack);
void		sort_size_three(t_push_swap* push_swap, t_list *stack);
t_push_swap	*sort_size_six(t_push_swap* push_swap);
t_push_swap *merge_sorted_stacks(t_push_swap *push_swap);

//big_stack_utils.c
void	sort_big_stack(t_push_swap* push_swap);
void	stack_to_indexes(t_list *stack, int *sorted_array);
int 	value_to_index(int value , t_list *stack);
void	print_int_array(int *array, int size);
int 	*stack_to_array(t_list *stack);
void 	sort_array(int arr[], int n);
void 	swap_mem(int* xp, int* yp);

//big_sorting.c
void	final_sorting(t_push_swap *push_swap);
void	selection_sort(t_push_swap *push_swap, int pivot);
int	smart_allocation(t_push_swap *push_swap, int element);
void	smart_push(t_push_swap *push_swap, int element);
void	smart_rotate(t_push_swap *push_swap, t_list *stack, int element);
int		closest_element(t_push_swap *push_swap, int max_value);



/* t_list_node	*append_element(int element, t_list *list);
void		free_list_nodes(t_list *list);
void		push(t_list_node *list_node, t_list *list);
t_list_node	*pop(t_list *list);
void		rotate(t_list *list); */



#endif