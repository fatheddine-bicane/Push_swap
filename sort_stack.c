/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:38:50 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 18:55:41 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_len;

	stack_a_len = stack_len(*stack_a);
	if (stack_a_len-- > 3 && !stack_sorted(*stack_a))
		ft_push(stack_b, stack_a, 'b');
	if (stack_a_len-- > 3 && !stack_sorted(*stack_a))
		ft_push(stack_b, stack_a, 'b');
	while (stack_a_len-- > 3 && !stack_sorted(*stack_a))
	{

	}
}
