/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:01 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 15:05:19 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while((*stack) != top_node)
	{
		if (top_node->above_median)
			ft_rotate(stack, stack_name);
		else
		{
			if (stack_name == 'a')
				reverse_rotate(stack, 'a');
			else if (stack_name == 'b')
				reverse_rotate(stack, 'b');
		}
	}
}
