/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/17 11:21:19 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*prev_node;
	int				data;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*taget_node;
	struct s_stack	*next_node;
}	t_stack;

# define NONE 'x'

// The algorithm that will sort the satck
void	sort_for_tree(t_stack **stack);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);

// commands => u have define what stack r u dealing with a,b or both.
/*-----------------------------------------------------------------------------*/
/*void	ft_push(t_stack **stack_1, t_stack **stack_2, char stack_name);*/
void	ft_push(t_stack **stack_dst, t_stack **stack_src, char stack_name);
void	ft_swap(t_stack **stack, char stack_name);
void	ft_rotate(t_stack **stack, char stack_name);
void	ft_reverse_rotate(t_stack **stack, char stack_name);
/*now commands for both stack*/
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
/*-----------------------------------------------------------------------------*/

// utility functions for sorting
/*--------------------------------------*/
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
bool	stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	init_node_a(t_stack *stack_a, t_stack *stack_b);
void	init_node_b(t_stack *stack_a, t_stack *stack_b);
void	set_median(t_stack *stack);
void	rotate_both(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	init_node_b(t_stack *stack_a, t_stack *stack_b);
void	init_node_a(t_stack *stack_a, t_stack *stack_b);
/*--------------------------------------*/

// utility functions that help creating and manipulating a stack
/*-------------------------------------------------------------*/
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
t_stack	*ft_creat_node(int nbr, int ind);
void	ft_add_block_back(t_stack **stack, t_stack *block);
void	ft_add_block_front(t_stack **stack, t_stack *block);
void	ft_creat_stack(t_stack **stack, char **argv);
void	ft_readjust_index(t_stack **stack);
t_stack	*ft_stack_last(t_stack *stack);
/*-------------------------------------------------------------*/


void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);



int		ft_syntax_check(char **argv);
void	ft_check_dupps(t_stack *stack, int len);
void	ft_free_stack(t_stack **stack);
void	ft_error(void);

#endif
