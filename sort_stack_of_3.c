/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_of_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:53:31 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 13:50:05 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_of_3(t_stack **stack)
{
	t_stack	*highest_data;

	highest_data = ft_find_max(*stack);
	if ((*stack) == highest_data)
		ft_rotate(stack, 'a');
	else if ((*stack)->next_node == highest_data)
		ft_reverse_rotate(stack, 'a');
	if ((*stack)->data > (*stack)->next_node->data)
		ft_swap(stack, 'a');
}
