/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:38:50 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/14 16:37:12 by fbicane          ###   ########.fr       */
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
	return (stack);
}

static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a);
	
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_len;

	stack_a_len = stack_len(*stack_a);
	if (stack_a_len-- > 3 && !stack_sorted(*stack_a))
		ft_push(stack_b, stack_a, 'b');
	if (stack_a_len-- > 3 && !stack_sorted(*stack_a))
		ft_push(stack_b, stack_a, 'b');
	while (stack_a_len-- > 3 && !stack_sorted(*stack_a))
	{
		init_node(*stack_a, *stack_b);

	}
}
