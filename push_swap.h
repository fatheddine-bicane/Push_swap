/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/09 21:48:20 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*prev_node;
	int				data;
	int				index;
	struct s_stack	*next_node;
}	t_stack;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
t_stack	*ft_creat_block(int nbr, int ind);
void	ft_add_block(t_stack **stack, t_stack *node);

#endif
