/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_to_int_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:28 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 12:56:36 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_argv_to_int_list(char **argv)
{
	t_stack	*head;
	t_stack	*tmp_block;
	int		i;
	int		ind;

	head = NULL;
	i = 1;
	ind = 0;
	while (argv[i])
	{
		tmp_block = ft_creat_block(ft_atoi(argv[i]), ind);
		ind++;
		ft_add_block(&head, tmp_block);
		i++;
	}
	return (head);
}
