/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:14:56 by arochd            #+#    #+#             */
/*   Updated: 2025/12/11 11:14:58 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

// Libft Functions
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

// Parsing Functions
char	*ft_strjoin_free(char *s1, char *s2);
char	**collect_args(int ac, char **av, int *counter);
void	free_args(char **args);
int		dupchecks(char **args);
int		valide_nbrs(char **args);

// Stack Utils
t_node	*new_node(int value);
t_stack	*new_stack(void);
void	stack_add_front(t_stack *stack, t_node *node);
void	stack_add_back(t_stack *stack, t_node *node);
t_stack	*stack_init(char **args, int count);

void	stack_free(t_stack *stack);
int		is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
t_node	*stack_peek(t_stack *stack);

// Operations Utils
t_node	*stack_remove_front(t_stack *stack);
t_node	*stack_remove_back(t_stack *stack);

// Operations Functions
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Helper functions
int		find_min_position(t_stack *a);
void	push_min_to_b(t_stack *a, t_stack *b);

// Sorting functions
void	small_sort(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *a);
void	ft_sort_four(t_stack *a, t_stack *b);
void	ft_sort_five(t_stack *a, t_stack *b);

#endif