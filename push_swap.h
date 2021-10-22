/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:59 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/22 18:58:17 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>

#include "./libft/libft.h"

typedef struct s_push_swap
{
	struct s_list	*stack_a;
	struct s_list	*stack_b;
}					t_push_swap;


typedef struct s_list
{
	int					count_elements;
	struct s_list_node	*first;
	//struct s_list_node	*last;
}					t_list;

typedef struct s_list_node
{
	int					value;
	struct s_list_node	*prev;
	struct s_list_node	*next;
}					t_list_node;

//list_utils.c
t_list		*new_list(void);
t_list_node	*new_node(int element);
void		push_node(t_list_node *new_node, t_list *list);
t_list_node	*pop_node(t_list *list);
t_list		*rotate(t_list *list);
t_list		*rev_rotate(t_list *list);
void		queue_node(t_list_node *new_node, t_list *list);
void 		print_list(t_list *list);

//push_swap_interpreter.c
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


/* t_list_node	*append_element(int element, t_list *list);
void		free_list_nodes(t_list *list);
void		push(t_list_node *list_node, t_list *list);
t_list_node	*pop(t_list *list);
void		rotate(t_list *list); */



#endif