/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:16:20 by alemarti          #+#    #+#             */
/*   Updated: 2022/02/23 17:11:26 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

// FOR TESTING
void	print_stacks(t_push_swap *push_swap)
{
	ft_putstr_fd("Stack A: \t", 1);
	print_list(push_swap->stack_a);
	ft_putstr_fd("Stack B: \t", 1);
	print_list(push_swap->stack_b);
}

void	print_list(t_list *list)
{
	t_list_node	*reader;

	if (list->first == NULL)
	{
		return ;
	}
	reader = list->first;
	while (reader->next != list->first)
	{
		ft_putnbr_fd(reader->value, 2);
		ft_putstr_fd("\t", 2);
		reader = reader->next;
	}
	ft_putnbr_fd(reader->value, 2);
	ft_putstr_fd("\n", 2);
	return ;
}

t_list	*string_tolist(char *str)
{
	char	**chopped;
	t_list	*res;
	long	swap;
	void	*centinel;

	if (check_only_digits(str) == -1)
	{
		free (str);
		return (NULL);
	}
	res = new_list();
	chopped = ft_split(str, ' ');
	centinel = chopped;
	free (str);
	while (*chopped)
	{
		swap = ft_atoi(*chopped);
		queue_node(new_node((long)swap), res);
		free(*chopped);
		chopped++;
	}
	free (centinel);
	return (res);
}
