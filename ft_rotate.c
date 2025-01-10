/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:16:19 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 18:38:11 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*stack_ptr1;
	t_stack	*stack_ptr2;

	if (!stack || !(*stack))
		return ;
	if (!(*stack)->next_node)
		return ;
	stack_ptr1 = (*stack);
	(*stack) = (*stack)->next_node;
	(*stack)->prev_node = NULL;
	stack_ptr2 = ft_stack_last(*stack);
}
