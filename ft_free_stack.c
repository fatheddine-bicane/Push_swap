/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:05:46 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 14:24:14 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack *stack_ptr;

	if (!stack)
		return ;
	while(*stack)
	{
		stack_ptr = (*stack)->next_node;
		free(*stack);
		(*stack) = stack_ptr;
	}
}
