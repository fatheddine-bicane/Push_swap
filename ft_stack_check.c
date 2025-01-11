/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:16:56 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/11 14:24:28 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dupps(t_stack *stack, int len)
{
	t_stack	*stack_ptr1;
	t_stack	*stack_ptr2;

	if (!stack || len == 1)
		return (1);
	stack_ptr1 = stack;
	while (stack_ptr1->next_node)
	{
		stack_ptr2 = stack_ptr1->next_node;
		while (stack_ptr2)
		{
			if (stack_ptr1->data == stack_ptr2->data)
				return (0);
			stack_ptr2 = stack_ptr2->next_node;
		}
		stack_ptr1 = stack_ptr1->next_node;
	}
	return (1);
}

int	ft_syntax_check(char **argv)
{
	int		i;
	int		j;
	char	av;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			av = argv[i][j];
			if (!(av == '-' || av == '+' || (av >= '0' && av <= '9')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' && str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 42;
		i++;
	}
	return (res * sign);
}
