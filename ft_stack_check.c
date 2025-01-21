/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:16:56 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/17 11:21:42 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dupps(t_stack *stack, int to_check)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == to_check)
			return (1);
		stack = stack->next_node;
	}
	return (0);
}

bool	ft_syntax_check(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (true);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (true);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (true);
	}
	return (false);
}

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

long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
