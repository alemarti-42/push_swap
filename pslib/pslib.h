/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:59 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/23 17:43:32 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
# define PSLIB_H

# include"../libft/libft.h"

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
t_list		*new_list(void);
t_list_node	*new_node(long element);
int			check_only_digits(char *str);
int			stack_is_sorted(t_list *stack);

//list_print.c
void		print_stacks(t_push_swap *push_swap);
void		print_list(t_list *list);
t_list		*string_tolist(char *str);

//list_exec.c
void		push_node(t_list_node *new_node, t_list *list);
t_list_node	*pop_node(t_list *list);
t_list		*rotate(t_list *list);
t_list		*rev_rotate(t_list *list);
void		queue_node(t_list_node *new_node, t_list *list);

//list_free.c
void		free_stack(t_list *stack);
void		free_push_swap(t_push_swap *push_swap);

//ps_push.c
int			exec_push(t_list *stack_src, t_list *stack_dst);
int			exec_pa(t_push_swap *push_swap);
int			exec_pb(t_push_swap *push_swap);
void		smart_push(t_push_swap *push_swap, int element);

//ps_rotate.c
int			exec_ra(t_push_swap *push_swap);
int			exec_rb(t_push_swap *push_swap);
int			exec_rr(t_push_swap *push_swap);
void		smart_rotate(t_push_swap *push_swap, t_list *stack, int element);
int			smart_allocation(t_push_swap *push_swap, int element);

//ps_reverse.c
int			exec_rra(t_push_swap *push_swap);
int			exec_rrb(t_push_swap *push_swap);
int			exec_rrr(t_push_swap *push_swap);

//ps_swap.c
int			exec_swap(t_list *stack);
int			exec_sa(t_push_swap *push_swap);
int			exec_sb(t_push_swap *push_swap);
int			exec_ss(t_push_swap *push_swap);

//push_swap_interpreter.c
t_push_swap	*init_push_swap(char *str);
int			exec_command(t_push_swap *push_swap, char *command);
void		add_command(t_push_swap *push_swap, char *cmd);
#endif