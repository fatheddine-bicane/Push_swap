/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:53:31 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 17:27:18 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_tree(t_stack **stack)
{
	t_stack	*highest_data;

	highest_data = find_max(*stack);
	if ((*stack) == highest_data)
		ft_rotate(stack, 'a');
	else if ((*stack)->next_node == highest_data)
		ft_reverse_rotate(stack, 'a');
	if ((*stack)->data > (*stack)->next_node->data)
		ft_swap(stack, 'a');
}
