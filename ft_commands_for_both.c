/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_for_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:04:35 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/14 16:23:08 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, NONE);
	ft_rotate(stack_b, NONE);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, NONE);
	ft_reverse_rotate(stack_b, NONE);
	write(1, "rrr\n", 4);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, NONE);
	ft_swap(stack_b, NONE);
	write(1, "ss\n", 3);
}
