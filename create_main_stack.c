/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_main_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:20:00 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 13:34:07 by fbicane          ###   ########.fr       */
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

static void	add_node(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = num;
	new_node->cheapest = false;
	new_node->next_node = NULL;
	if (!(*stack))
	{
		*stack = new_node;
		(*stack)->prev_node = NULL;
	}
	else
	{
		last_node = ft_stack_last(*stack);
		last_node->next_node = new_node;
		new_node->prev_node = last_node;
	}
}

void	ft_creat_stack(t_stack **stack, char **argv, char **argv_s)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_syntax_check(argv[i]))
		{
			ft_free_argv(argv_s);
			ft_free_error(stack);
		}
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_free_argv(argv);
			ft_free_error(stack);
		}
		if (ft_check_dupps((*stack), (int)n))
		{
			ft_free_argv(argv_s);
			ft_free_error(stack);
		}
		add_node(stack, (int)n);
		i++;
	}
}
