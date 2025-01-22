/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:06:10 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 13:32:15 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_max(t_stack *stack)
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

t_stack	*ft_find_min(t_stack *stack)
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

void	ft_set_median_index(t_stack *stack)
{
	int	median;
	int	index;

	median = ft_stack_len(stack) / 2;
	index = 0;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next_node;
		index++;
	}
}
