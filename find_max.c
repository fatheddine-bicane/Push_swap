/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:06:10 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 17:28:01 by fbicane          ###   ########.fr       */
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
