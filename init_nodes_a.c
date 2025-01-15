/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:27 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 14:01:35 by fbicane          ###   ########.fr       */
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

static void	set_cost_a(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = stack_len(stack_a);
	stack_b_len = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = stack_a_len - (stack_a->index);
		if (stack_a->taget_node->above_median)
			stack_a->push_cost += stack_a->taget_node->index;
		else
			stack_a->push_cost += stack_b_len - (stack_a->taget_node->index);
		stack_a = stack_a->next_node;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next_node;
	}
	cheapest_node->cheapest = true;
}

void	init_node(t_stack *stack_a, t_stack *stack_b)
{
	set_median(stack_a);
	set_median(stack_b);
	set_target_nodes_a(stack_a, stack_b);
	set_cost_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
