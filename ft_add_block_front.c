/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_block_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:28:36 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 17:40:05 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_block_front(t_stack **stack, t_stack *block)
{
	if (!block)
		return ;
	block->prev_node = NULL;
	if (!stack || !(*stack))
	{
		block->index = 0;
		*stack = block;
		return ;
	}
	block->next_node = (*stack);
	(*stack)->prev_node = block;
	(*stack) = block;
	ft_readjust_index(stack);
}
