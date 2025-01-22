/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:36 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 13:53:37 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splited_argv;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	splited_argv = ft_split(argv[1], 32);
	if (argc == 2)
	{
		argv = splited_argv;
	}
	ft_creat_stack(&stack_a, argv);
	if (!ft_stack_sorted(stack_a))
	{
		if (ft_stack_len(stack_a) == 2)
			ft_swap(&stack_a, 'a');
		else if (ft_stack_len(stack_a) == 3)
			ft_sort_stack_of_3(&stack_a);
		else
			ft_sort_stack(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	ft_free_argv(splited_argv);
}
