/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:14 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 13:53:03 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_stack *stack)
{
	int	stack_len;

	if (!stack)
		return (0);
	stack_len = 0;
	while (stack)
	{
		stack = stack->next_node;
		stack_len++;
	}
	return (stack_len);
}

bool	ft_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack && stack->next_node)
	{
		if (stack->data > stack->next_node->data)
			return (false);
		stack = stack->next_node;
	}
	return (true);
}

void	ft_rotate_both(t_stack **stack_a,
					t_stack **stack_b,
					t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->taget_node
		&& (*stack_a) != cheapest_node)
		ft_rr(stack_a, stack_b);
	ft_set_median_index(*stack_a);
	ft_set_median_index(*stack_b);
}

void	ft_reverse_rotate_both(t_stack **stack_a,
					t_stack **stack_b,
					t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->taget_node
		&& (*stack_a) != cheapest_node)
		ft_rrr(stack_a, stack_b);
	ft_set_median_index(*stack_a);
	ft_set_median_index(*stack_b);
}

void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while ((*stack) != top_node)
	{
		if (top_node->above_median)
			ft_rotate(stack, stack_name);
		else
		{
			if (stack_name == 'a')
				ft_reverse_rotate(stack, 'a');
			else if (stack_name == 'b')
				ft_reverse_rotate(stack, 'b');
		}
	}
}
