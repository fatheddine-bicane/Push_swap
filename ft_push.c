/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:19:32 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 18:14:56 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	if (!stack_2 || !(*stack_2))
		return ;
	ft_add_block_front(stack_1, (*stack_2));
	(*stack_2) = (*stack_2)->next_node;
	if (*stack_2)
		(*stack_2)->prev_node = NULL;
	ft_readjust_index(stack_1);
	ft_readjust_index(stack_2);
}
