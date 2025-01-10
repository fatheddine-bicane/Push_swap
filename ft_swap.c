/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:30 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 17:48:50 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack **stack)
{
	t_stack	*first_block;
	t_stack	*second_block;
	int		tmp_data;

	if (!stack || !(*stack) || !(*stack)->next_node)
		return ;
	first_block = *stack;
	second_block = (*stack)->next_node;
	tmp_data = first_block->data;
	first_block->data = second_block->data;
	second_block->data = tmp_data;
	ft_readjust_index(stack);
}
