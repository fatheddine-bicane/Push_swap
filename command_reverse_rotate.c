/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:05:07 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 13:40:43 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack, char stack_name)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stack) || !(*stack)->next_node)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next_node)
	{
		second_last = last;
		last = last->next_node;
	}
	if (second_last)
	{
		second_last->next_node = NULL;
		last->prev_node = NULL;
		last->next_node = *stack;
		(*stack)->prev_node = last;
		*stack = last;
	}
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
	ft_set_median_index(*stack);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, NONE);
	ft_reverse_rotate(stack_b, NONE);
	write(1, "rrr\n", 4);
}
