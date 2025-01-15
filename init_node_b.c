/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:19:47 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 15:44:41 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curent_a_node;
	t_stack	*target_node;
	long	best_match;

	while (stack_b)
	{
		best_match = LONG_MAX;
		curent_a_node = stack_a;
		while (curent_a_node)
		{
			if (curent_a_node->data > stack_b->data && curent_a_node->data < best_match)
			{
				best_match = curent_a_node->data;
				target_node = curent_a_node;
			}
			curent_a_node = curent_a_node->next_node;
		}
		if (best_match == LONG_MAX)
			target_node = find_min(stack_a);
		stack_b->taget_node = target_node;
		stack_b = stack_b->next_node;
	}
}

void	init_node_b(t_stack *stack_a, t_stack *stack_b)
{
	set_median(stack_a);
	set_median(stack_b);
	set_target_node_b(stack_a, stack_b);
}
