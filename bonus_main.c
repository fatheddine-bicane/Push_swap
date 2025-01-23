/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:16:16 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/23 12:16:59 by fbicane          ###   ########.fr       */
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
		argv = splited_argv;
	ft_creat_stack(&stack_a, argv);
	ft_apply_command(&stack_a, &stack_b);
}
