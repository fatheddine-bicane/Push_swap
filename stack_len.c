/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:41:35 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 17:27:38 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	stack_len;

	if (!stack)
		return (0);
	stack_len = 0;
	while (stack)
	{
		stack = stack->next_node;
		stack_len++;
	}
	return (stack_len);
}
