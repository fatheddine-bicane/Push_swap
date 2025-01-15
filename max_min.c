/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:06:10 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 15:37:23 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_data;

	max_data = stack;
	while (stack)
	{
		if (stack->data > max_data->data)
			max_data = stack;
		stack = stack->next_node;
	}
	return (max_data);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_data;

	min_data = stack;
	while (stack)
	{
		if (stack->data < min_data->data)
			min_data = stack;
		stack = stack->next_node;
	}
	return (min_data);
}
