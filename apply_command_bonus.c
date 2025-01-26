/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_command_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:33:12 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/26 10:35:09 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static bool	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	if (!(s1[i] && s2[i]))
		return (true);
	else
		return (false);
}

static void	ft_command_helper(t_stack **stack_a, t_stack **stack_b,
								char operation, char *command)
{
	if (operation == 's')
	{
		ft_swap(stack_a, NONE);
		ft_swap(stack_b, NONE);
	}
	else if (operation == 'r')
	{
		ft_rotate(stack_a, NONE);
		ft_rotate(stack_b, NONE);
	}
	else if (operation == 'R')
	{
		ft_reverse_rotate(stack_a, NONE);
		ft_reverse_rotate(stack_b, NONE);
	}
	else if (operation == 'f')
	{
		free(command);
		get_next_line(-1);
		ft_free_stack(stack_a);
		ft_free_error(stack_b);
	}
}

static void	ft_check_command(char *command, t_stack **stack_a,
							t_stack **stack_b)
{
	if (ft_strcmp("sa\n", command))
		ft_swap(stack_a, NONE);
	else if (ft_strcmp("sb\n", command))
		ft_swap(stack_b, NONE);
	else if (ft_strcmp("ss\n", command))
		ft_command_helper(stack_a, stack_b, 's', command);
	else if (ft_strcmp("pa\n", command))
		ft_push(stack_a, stack_b, NONE);
	else if (ft_strcmp("pb\n", command))
		ft_push(stack_b, stack_a, NONE);
	else if (ft_strcmp("ra\n", command))
		ft_rotate(stack_a, NONE);
	else if (ft_strcmp("rb\n", command))
		ft_rotate(stack_b, NONE);
	else if (ft_strcmp("rr\n", command))
		ft_command_helper(stack_a, stack_b, 'r', command);
	else if (ft_strcmp("rra\n", command))
		ft_reverse_rotate(stack_a, NONE);
	else if (ft_strcmp("rrb\n", command))
		ft_reverse_rotate(stack_b, NONE);
	else if (ft_strcmp("rrr\n", command))
		ft_command_helper(stack_a, stack_b, 'R', command);
	else
		ft_command_helper(stack_a, stack_b, 'f', command);
}

void	ft_apply_command(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		ft_check_command(command, stack_a, stack_b);
		free(command);
		command = get_next_line(0);
	}
	free(command);
	get_next_line(-1);
	if ((*stack_b) || !(ft_stack_sorted(*stack_a)))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		write(1, "KO\n", 3);
	}
	else if (ft_stack_sorted(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		write(1, "OK\n", 3);
	}
}
