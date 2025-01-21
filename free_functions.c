/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:05:46 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 14:00:10 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*stack_ptr;
	t_stack	*next_stack_ptr;

	if (!stack || !(*stack))
		return ;
	stack_ptr = *stack;
	while (stack_ptr)
	{
		next_stack_ptr = stack_ptr->next_node;
		stack_ptr->next_node = NULL;
		stack_ptr->prev_node = NULL;
		free(stack_ptr);
		stack_ptr = next_stack_ptr;
	}
	*stack = NULL;
}

void	ft_free_argv(char **arr_s)
{
	int	i;

	i = 0;
	if (!arr_s)
		return ;
	while (arr_s[i])
	{
		free(arr_s[i]);
		i++;
	}
	free (arr_s);
}
