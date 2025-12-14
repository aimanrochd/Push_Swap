/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:22:58 by arochd            #+#    #+#             */
/*   Updated: 2025/12/14 14:46:06 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	void	move_largest_to_top(t_stack *b)
{
	int	max_pos;
	int	size;

	max_pos = find_max_index_position(b);
	size = b->size;
	if (max_pos == 0)
		return ;
	if (max_pos <= size / 2)
		while (max_pos-- > 0)
			rb(b);
	else
		while (max_pos++ < size)
			rrb(b);
}

static	void	push_all_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		move_largest_to_top(b);
		pa(a, b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	window;

	assign_indexes(a);
	i = 0;
	window = get_chunk_size(a->size);
	while (a->size > 0)
	{
		if (a->head->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->head->index <= i + window)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_all_back_to_a(a, b);
}
