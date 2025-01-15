/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:36 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/15 14:01:15 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], 32);
	ft_creat_stack(&a, (argv));
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			ft_swap(&a, 'a');
		else if (stack_len(a) == 3)
			sort_for_tree(&a);
		else

	}
}

