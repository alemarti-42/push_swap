/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:59 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/21 19:07:35 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
# define PSLIB_H

//#include <stdio.h>

# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>

# include"./libft/libft.h"

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
}					t_list;

typedef struct s_list_node
{
	long				value;
	struct s_list_node	*prev;
	struct s_list_node	*next;
}					t_list_node;

//list_utils.c
void		print_stacks(t_push_swap *push_swap);

t_list		*new_list(void);
t_list_node	*new_node(long element);
void		push_node(t_list_node *new_node, t_list *list);
t_list_node	*pop_node(t_list *list);
t_list		*rotate(t_list *list);
t_list		*rev_rotate(t_list *list);
void		queue_node(t_list_node *new_node, t_list *list);
void		print_list(t_list *list);
int			check_only_digits(char *str);
t_list		*string_tolist(char *str);
int			stack_is_sorted(t_list *stack);

//push_swap_interpreter.c
void		add_command(t_push_swap *push_swap, char *cmd);

t_push_swap	*init_push_swap(void);
int			exec_command(t_push_swap *push_swap, char *command);
int			exec_swap(t_list *stack);
int			exec_sa(t_push_swap *push_swap);
int			exec_sb(t_push_swap *push_swap);
int			exec_ss(t_push_swap *push_swap);

int			exec_push(t_list *stack_src, t_list *stack_dst);
int			exec_pa(t_push_swap *push_swap);
int			exec_pb(t_push_swap *push_swap);

int			exec_ra(t_push_swap *push_swap);
int			exec_rb(t_push_swap *push_swap);
int			exec_rr(t_push_swap *push_swap);

int			exec_rra(t_push_swap *push_swap);
int			exec_rrb(t_push_swap *push_swap);
int			exec_rrr(t_push_swap *push_swap);
#endif