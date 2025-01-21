/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:05:07 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/17 11:06:12 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next_node)
		return ;
	last = ft_stack_last(*stack);
	last->prev_node->next_node = NULL;
	last->next_node = *stack;
	last->prev_node = NULL;
	*stack = last;
	last->next_node->prev_node = last;
	set_median(*stack);
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

/*void	ft_reverse_rotate(t_stack **stack, char stack_name)*/
/*{*/
/*	t_stack	*stack_ptr_last;*/
/*	t_stack	*stack_ptr_second_last;*/
/**/
/*	if (!stack || !(*stack) || !(*stack)->next_node)*/
/*		return ;*/
/*	stack_ptr_last = ft_stack_last(*stack);*/
/*	if (!stack_ptr_last || !(stack_ptr_last->prev_node))*/
/*		return ;*/
/*	stack_ptr_second_last = stack_ptr_last->prev_node;*/
/*	stack_ptr_last->prev_node = NULL;*/
/*	stack_ptr_second_last->next_node = NULL;*/
/*	(*stack)->prev_node = stack_ptr_last;*/
/*	stack_ptr_last->next_node = (*stack);*/
/*	(*stack) = stack_ptr_last;*/
/*	ft_readjust_index(stack);*/
/*	set_median(*stack);*/
/*	if (stack_name == 'a')*/
/*		write(1, "rra\n", 4);*/
/*	else if (stack_name == 'b')*/
/*		write(1, "rrb\n", 4);*/
/*}*/

/*void	ft_rrr(t_stack **stack_a, t_stack **stack_b)*/
/*{*/
/*	ft_reverse_rotate(stack_a, NONE);*/
/*	ft_reverse_rotate(stack_b, NONE);*/
/*	write(1, "rrr\n", 4);*/
/*}*/
