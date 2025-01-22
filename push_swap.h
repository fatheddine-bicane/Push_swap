/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:19:51 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/22 14:02:11 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

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

// create the stack.
/*-------------------------------------------------------------*/
long	ft_atol(const char *str);
int		ft_check_dupps(t_stack *stack, int to_check);
t_stack	*ft_stack_last(t_stack *stack);
bool	ft_syntax_check(char *argv);
char	**ft_split(char const *s, char c);
t_stack	*ft_creat_node(int nbr, int ind);
void	ft_creat_stack(t_stack **stack, char **argv);
/*-------------------------------------------------------------*/

// The algorithm that will sort the satck.
/*---------------------------------------------------------*/
void	ft_sort_stack_of_3(t_stack **stack);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
/*---------------------------------------------------------*/

// commands to sort (moves).
/*------------------------------------------------------------------------*/
void	ft_push(t_stack **stack_dst, t_stack **stack_src, char stack_name);
void	ft_swap(t_stack **stack, char stack_name);
void	ft_rotate(t_stack **stack, char stack_name);
void	ft_reverse_rotate(t_stack **stack, char stack_name);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
/*------------------------------------------------------------------------*/

// utility functions to sort the stack.
/*---------------------------------------------------------------------------*/
void	ft_initialize_node_b(t_stack *stack_a, t_stack *stack_b);
void	ft_initialize_node_a(t_stack *stack_a, t_stack *stack_b);
void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	ft_set_median_index(t_stack *stack);
bool	ft_stack_sorted(t_stack *stack);
int		ft_stack_len(t_stack *stack);
t_stack	*ft_find_max(t_stack *stack);
t_stack	*ft_find_min(t_stack *stack);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
/*---------------------------------------------------------------------------*/

// free functions.
/*-------------------------------------*/
void	ft_free_argv(char **argv);
void	ft_free_stack(t_stack **stack);
void	ft_free_error(t_stack **stack);
/*-------------------------------------*/

#endif
