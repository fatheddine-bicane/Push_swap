/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:13:00 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 21:49:20 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*stack_ptr_last;
	t_stack	*stack_ptr_second_last;

	if (!stack || !(*stack) || !(*stack)->next_node)
		return ;
	stack_ptr_last = ft_stack_last(*stack);
	stack_ptr_second_last = stack_ptr_last->prev_node;
	stack_ptr_last->prev_node = NULL;
	stack_ptr_second_last->next_node = NULL;
	(*stack)->prev_node = stack_ptr_last;
	stack_ptr_last->next_node = (*stack);
	(*stack) = stack_ptr_last;
	ft_readjust_index(stack);
}
