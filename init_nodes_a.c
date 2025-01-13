/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:27 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 18:55:35 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_median(t_stack *stack)
{
	int	median;
	int	index;

	median = stack_len(stack) / 2;
	index = 0;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next_node;
		index++;
	}
}

static void	set_target_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curent_b_node;
	t_stack	*target_node;
	long	best_match;

	while (stack_a)
	{
		best_match = LONG_MIN;
		curent_b_node = stack_b;
		while (curent_b_node)
		{
			if (stack_a->data > curent_b_node->data
				&& curent_b_node->data > best_match)
			{
				best_match = curent_b_node->data;
				target_node = curent_b_node;
			}
			curent_b_node = curent_b_node->next_node;
		}
		if (best_match == LONG_MIN)
			target_node = find_max(stack_b);
		stack_a->taget_node = target_node;
		stack_a = stack_a->next_node;
	}
}
