/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:14 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 14:23:45 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **stack_a,
					t_stack **stack_b,
					t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->taget_node && (*stack_a) != cheapest_node)
		ft_rr(stack_a, stack_b);
	set_median(*stack_a);
	set_median(*stack_b);
}

void	reverse_rotate_both(t_stack **stack_a,
					t_stack **stack_b,
					t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->taget_node && (*stack_a) != cheapest_node)
		rrr(stack_a, stack_b);
	set_median(*stack_a);
	set_median(*stack_b);
}
