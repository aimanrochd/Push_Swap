/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:16:07 by arochd            #+#    #+#             */
/*   Updated: 2025/12/13 16:16:09 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	if (size <= 500)
		return (size / 12);
	return (size / 13);
}

int	find_max_index_position(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		max_pos;
	int		pos;

	current = stack->head;
	max_index = current->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

int	is_in_chunk(int index, int chunk_min, int chunk_max)
{
	return (index >= chunk_min && index <= chunk_max);
}

int	has_chunk_numbers(t_stack *a, int chunk_min, int chunk_max)
{
	t_node	*current;

	current = a->head;
	while (current)
	{
		if (is_in_chunk(current->index, chunk_min, chunk_max))
			return (1);
		current = current->next;
	}
	return (0);
}
