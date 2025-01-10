/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_block_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:07:57 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 17:50:13 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_block_back(t_stack **stack, t_stack *block)
{
	t_stack	*stack_ptr;

	if (!stack || !block)
		return ;
	if (!*stack)
	{
		*stack = block;
		return ;
	}
	stack_ptr = *(stack);
	while (stack_ptr->next_node)
		stack_ptr = stack_ptr->next_node;
	stack_ptr->next_node = block;
	block->prev_node = stack_ptr;
	ft_readjust_index(stack);
}
