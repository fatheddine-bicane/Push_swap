/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:26:35 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 18:30:28 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*stack_ptr;

	if (!stack)
		return (NULL);
	stack_ptr = stack;
	while (stack_ptr->next_node)
		stack_ptr = stack_ptr->next_node;
	return (stack_ptr);
}
