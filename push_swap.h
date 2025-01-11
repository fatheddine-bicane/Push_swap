/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/11 14:24:31 by fbicane          ###   ########.fr       */
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
void	ft_add_block_back(t_stack **stack, t_stack *block);
void	ft_add_block_front(t_stack **stack, t_stack *block);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_1, t_stack **stack_2);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_readjust_index(t_stack **stack);
int		ft_syntax_check(char **argv);
int		ft_check_dupps(t_stack *stack, int len);
t_stack	**ft_argv_to_int_list(char **argv, int *len);
t_stack	*ft_stack_last(t_stack *stack);

#endif
