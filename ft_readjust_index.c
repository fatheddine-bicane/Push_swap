/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readjust_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:26:26 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 17:46:53 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_readjust_index(t_stack **stack)
{
	t_stack	*stack_ptr;
	int		index;

	stack_ptr = (*stack);
	index = 0;
	while (stack_ptr)
	{
		stack_ptr->index = index;
		index++;
		stack_ptr = stack_ptr->next_node;
	}
}
