/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:28:06 by arochd            #+#    #+#             */
/*   Updated: 2025/12/10 17:22:52 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_free(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
