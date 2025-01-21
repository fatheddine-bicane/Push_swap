/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:19:48 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 17:25:46 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack && stack->next_node)
	{
		if (stack->data > stack->next_node->data)
			return (false);
		stack = stack->next_node;
	}
	return (true);
}
