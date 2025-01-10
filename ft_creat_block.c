/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:08:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/10 17:47:31 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_creat_node(int nbr, int ind)
{
	t_stack	*new_block;

	new_block = malloc(sizeof(t_stack));
	if (!new_block)
		return (NULL);
	new_block->prev_node = NULL;
	new_block->data = nbr;
	new_block->index = ind;
	new_block->next_node = NULL;
	return (new_block);
}
