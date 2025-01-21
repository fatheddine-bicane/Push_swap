/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:04:04 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/17 11:07:04 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char stack_name)
{
	t_stack	*stack_ptr1;
	t_stack	*stack_ptr2;

	if (!stack || !(*stack))
		return ;
	if (!(*stack)->next_node)
		return ;
	stack_ptr1 = (*stack);
	(*stack) = (*stack)->next_node;
	(*stack)->prev_node = NULL;
	stack_ptr2 = ft_stack_last(*stack);
	stack_ptr2->next_node = stack_ptr1;
	stack_ptr1->prev_node = stack_ptr2;
	stack_ptr1->next_node = NULL;
	ft_readjust_index(stack);
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else if (stack_name == 'b')
		write(1, "rb\n", 3);
}

/*void	ft_ra(t_stack **stack_a)*/
/*{*/
/*	ft_rotate(stack_a);*/
/*	write(1, "ra\n", 3);*/
/*}*/
/**/
/*void	ft_rb(t_stack **stack_b)*/
/*{*/
/**/
/*}*/

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, NONE);
	ft_rotate(stack_b, NONE);
	write(1, "rr\n", 3);
}
