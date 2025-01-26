/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:25:12 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/26 10:33:57 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <stdint.h>
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// create the stack.
/*-------------------------------------------------------------*/
long	ft_atol(const char *str);
int		ft_check_dupps(t_stack *stack, int to_check);
t_stack	*ft_stack_last(t_stack *stack);
bool	ft_syntax_check(char *argv);
char	**ft_split(char const *s, char c);
t_stack	*ft_creat_node(int nbr, int ind);
void	ft_creat_stack(t_stack **stack, char **argv, char **argv_s);
/*-------------------------------------------------------------*/

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

// free functions.
/*-------------------------------------*/
void	ft_free_argv(char **argv);
void	ft_free_stack(t_stack **stack);
void	ft_free_error(t_stack **stack);
/*-------------------------------------*/

// the bonus
/*------------------------------------------------------------------*/
void	ft_apply_command(t_stack **stack_a, t_stack **stack_b);

// utility functions
bool	ft_stack_sorted(t_stack *stack);

// get_next_line functions
/*----------------------------------------------------------*/
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
/*----------------------------------------------------------*/
/*------------------------------------------------------------------*/

#endif
