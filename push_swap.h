/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:59 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/21 16:28:47 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct s_list
{
	struct s_list_node	*first;
	struct s_list_node	*last;
}					t_list;

typedef struct s_list_node
{
	int					value;
	struct s_list_node	*next;
}					t_list_node;

t_list		*new_list(void);
t_list_node	*append_element(int element, t_list *list);
void		empty_list(t_list *list);
t_list_node *pop(t_list *list);


#endif