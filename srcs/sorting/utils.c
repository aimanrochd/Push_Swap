/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:03:52 by arochd            #+#    #+#             */
/*   Updated: 2025/12/14 14:47:08 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	distance_to_chunk_top(t_stack *a, int min, int max)
{
	t_node	*current;
	int		dist;

	dist = 0;
	current = a->head;
	while (current)
	{
		if (is_in_chunk(current->index, min, max))
			return (dist);
		current = current->next;
		dist++;
	}
	return (dist);
}

int	distance_to_chunk_bottom(t_stack *a, int min, int max)
{
	t_node	*current;
	int		dist;

	dist = 1;
	current = a->tail;
	while (current)
	{
		if (is_in_chunk(current->index, min, max))
			return (dist);
		current = current->prev;
		dist++;
	}
	return (dist);
}
