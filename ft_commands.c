/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:12:02 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/14 16:14:18 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_1, t_stack **stack_2, char stack_name)
{
	if (!stack_2 || !(*stack_2))
		return ;
	ft_add_block_front(stack_1, (*stack_2));
	(*stack_2) = (*stack_2)->next_node;
	if (*stack_2)
		(*stack_2)->prev_node = NULL;
	ft_readjust_index(stack_1);
	ft_readjust_index(stack_2);
	if (stack_name == 'a')
		write(1, "pa\n", 3);
	else if (stack_name == 'b')
		write(1, "pb\n", 3);
}

void	ft_swap(t_stack **stack, char stack_name)
{
	t_stack	*first_block;
	t_stack	*second_block;
	int		tmp_data;

	if (!stack || !(*stack) || !(*stack)->next_node)
		return ;
	first_block = *stack;
	second_block = (*stack)->next_node;
	tmp_data = first_block->data;
	first_block->data = second_block->data;
	second_block->data = tmp_data;
	ft_readjust_index(stack);
	if (stack_name == 'a')
		write(1, "sa\n", 3);
	else if (stack_name == 'b')
		write(1, "sb\n", 3);
}

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

void	ft_reverse_rotate(t_stack **stack, char stack_name)
{
	t_stack	*stack_ptr_last;
	t_stack	*stack_ptr_second_last;

	if (!stack || !(*stack) || !(*stack)->next_node)
		return ;
	stack_ptr_last = ft_stack_last(*stack);
	stack_ptr_second_last = stack_ptr_last->prev_node;
	stack_ptr_last->prev_node = NULL;
	stack_ptr_second_last->next_node = NULL;
	(*stack)->prev_node = stack_ptr_last;
	stack_ptr_last->next_node = (*stack);
	(*stack) = stack_ptr_last;
	ft_readjust_index(stack);
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
}
