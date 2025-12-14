/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:00:00 by arochd            #+#    #+#             */
/*   Updated: 2025/12/13 03:30:00 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	error_exit(char **args, t_stack *a, t_stack *b)
{
	if (args)
		free_args(args);
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
	write(2, "Error\n", 6);
	exit(1);
}

static	void	choose_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else
		chunk_sort(a, b);
}

static	t_stack	*init_stacks(int ac, char **av, t_stack **stack_b)
{
	char	**args;
	int		count;
	t_stack	*stack_a;

	count = 0;
	args = collect_args(ac, av, &count);
	if (!args)
		error_exit(NULL, NULL, NULL);
	if (!valide_nbrs(args) || dupchecks(args))
		error_exit(args, NULL, NULL);
	stack_a = stack_init(args, count);
	*stack_b = new_stack();
	if (!stack_a || !*stack_b)
		error_exit(args, stack_a, *stack_b);
	free_args(args);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = init_stacks(ac, av, &stack_b);
	if (!is_sorted(stack_a))
		choose_sort(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
