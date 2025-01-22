/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:38:50 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 13:54:01 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_cheapest_node(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next_node;
	}
	return (NULL);
}

static void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	cheapest_node = get_cheapest_node(*stack_a);
	if (cheapest_node->above_median && cheapest_node->taget_node->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->taget_node->above_median))
		ft_reverse_rotate_both(stack_a, stack_b, cheapest_node);
	ft_prep_for_push(stack_a, cheapest_node, 'a');
	ft_prep_for_push(stack_b, cheapest_node->taget_node, 'b');
	ft_push(stack_b, stack_a, 'b');
}

static void	push_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	ft_prep_for_push(stack_a, (*stack_b)->taget_node, 'a');
	ft_push(stack_a, stack_b, 'a');
}

static void	min_data_on_top(t_stack **stack)
{
	while ((*stack)->data != (ft_find_min(*stack)->data))
	{
		if (ft_find_min(*stack)->above_median)
			ft_rotate(stack, 'a');
		else
			ft_reverse_rotate(stack, 'a');
	}
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_len;

	stack_a_len = ft_stack_len(*stack_a);
	if (stack_a_len-- > 3 && !ft_stack_sorted(*stack_a))
		ft_push(stack_b, stack_a, 'b');
	if (stack_a_len-- > 3 && !ft_stack_sorted(*stack_a))
		ft_push(stack_b, stack_a, 'b');
	while (stack_a_len-- > 3 && !ft_stack_sorted(*stack_a))
	{
		ft_initialize_node_a(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
	}
	ft_sort_stack_of_3(stack_a);
	while (*stack_b)
	{
		ft_initialize_node_b(*stack_a, *stack_b);
		push_b_to_a(stack_b, stack_a);
	}
	ft_set_median_index(*stack_a);
	min_data_on_top(stack_a);
}
