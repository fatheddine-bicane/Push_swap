/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:03:02 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/17 11:06:46 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char stack_name)
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
	if (stack_name == 'a')
		write(1, "sa\n", 3);
	else if (stack_name == 'b')
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, NONE);
	ft_swap(stack_b, NONE);
	write(1, "ss\n", 3);
}
