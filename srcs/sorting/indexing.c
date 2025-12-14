/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:50:06 by arochd            #+#    #+#             */
/*   Updated: 2025/12/13 15:50:07 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*cmp;
	int		index;

	current = stack->head;
	while (current)
	{
		index = 0;
		cmp = stack->head;
		while (cmp)
		{
			if (cmp->value < current->value)
				index++;
			cmp = cmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
