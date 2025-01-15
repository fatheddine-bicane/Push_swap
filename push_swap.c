/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:36 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 16:54:21 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], 32);
	ft_creat_stack(&stack_a, (argv));
	ft_check_dupps(stack_a, stack_len(stack_a));
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			ft_swap(&stack_a, 'a');
		else if (stack_len(stack_a) == 3)
			sort_for_tree(&stack_a);
		else
			ft_sort_stack(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
}

