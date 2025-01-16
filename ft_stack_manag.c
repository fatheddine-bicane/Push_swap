/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_manag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:20:00 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/13 18:45:17 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_creat_node(int nbr, int ind)
{
	t_stack	*new_block;

	new_block = malloc(sizeof(t_stack));
	if (!new_block)
		return (NULL);
	new_block->prev_node = NULL;
	new_block->data = nbr;
	new_block->index = ind;
	new_block->next_node = NULL;
	return (new_block);
}

void	ft_add_block_back(t_stack **stack, t_stack *block)
{
	t_stack	*stack_ptr;

	if (!stack || !block)
		return ;
	if (!*stack)
	{
		*stack = block;
		return ;
	}
	stack_ptr = *(stack);
	while (stack_ptr->next_node)
		stack_ptr = stack_ptr->next_node;
	stack_ptr->next_node = block;
	block->prev_node = stack_ptr;
	ft_readjust_index(stack);
}

void	ft_add_block_front(t_stack **stack, t_stack *block)
{
	if (!block)
		return ;
	block->prev_node = NULL;
	if (!stack || !(*stack))
	{
		block->index = 0;
		*stack = block;
		return ;
	}
	block->next_node = (*stack);
	(*stack)->prev_node = block;
	(*stack) = block;
	/*ft_readjust_index(stack);*/
	set_median(*stack);
}

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

void	ft_creat_stack(t_stack **stack, char **argv)
{
	t_stack	*new_block;
	int		i;
	int		index;

	if (!argv || !(*argv[1]))
		return ;
	if (ft_syntax_check(argv) == 0)
		ft_error();
	i = 1;
	index = 0;
	while (argv[i])
	{
		new_block = ft_creat_node(ft_atoi(argv[i]), index);
		ft_add_block_back(stack, new_block);
		i++;
		index++;
	}
}
