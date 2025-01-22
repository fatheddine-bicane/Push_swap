/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:19:11 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/16 18:32:41 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_dst, t_stack **stack_src, char stack_name)
{
	t_stack	*node_to_push;

	if (!(*stack_src))
		return ;
	node_to_push = *stack_src;
	*stack_src = (*stack_src)->next_node;
	if (*stack_src)
		(*stack_src)->prev_node = NULL;
	node_to_push->prev_node = NULL;
	if (!(*stack_dst))
	{
		(*stack_dst) = node_to_push;
		node_to_push->next_node = NULL;
	}
	else
	{
		node_to_push->next_node = *stack_dst;
		(*stack_dst)->prev_node = NULL;
		(*stack_dst) = node_to_push;
	}
	if (stack_name == 'a')
		write(1, "pa\n", 3);
	else if (stack_name == 'b')
		write(1, "pb\n", 3);
}
