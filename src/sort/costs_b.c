/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:40:49 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:15:01 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cost_add_element_in_b(int element, int nearest, t_dynamic_tab *cost_b,
		t_bool nearest_at_the_bottom)
{
	if (element > nearest)
	{
		if (nearest_at_the_bottom)
			cost_b->arr[cost_b->current_size++] = RRB;
		cost_b->arr[cost_b->current_size++] = PB;
	}
	else if (element < nearest)
	{
		if (!nearest_at_the_bottom)
			cost_b->arr[cost_b->current_size++] = RB;
		cost_b->arr[cost_b->current_size++] = PB;
	}
}

void	get_costs_b(t_dynamic_tab *cost_b, t_stack *stack,
	int element, int i_el)
{
	int		nearest;
	t_bool	down;
	int		middle_stack;

	nearest = nearest_of_element(stack, element);
	middle_stack = stack->top / 2;
	down = FALSE;
	if (i_el >= middle_stack)
		up_nearest_position(cost_b, stack, element, nearest);
	else
	{
		down = TRUE;
		down_nearest_position(cost_b, stack, element, nearest);
	}
	cost_add_element_in_b(element, nearest, cost_b, down);
}
