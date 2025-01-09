/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:07:57 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/09 21:08:15 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_node(t_stack **stack, t_stack *node)
{
	t_stack	*tmp_head;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp_head = *stack;
	while (tmp_head->next_node)
		tmp_head = tmp_head->next_node;
	tmp_head->next_node = node;
	node->prev_node = tmp_head;
}
