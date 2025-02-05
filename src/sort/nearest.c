/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:00:25 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:18:33 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_move_start_top(t_dynamic_tab *cost_b, t_stack *stack,
	int element, int nearest)
{
	int	count;
	int	i;

	count = 0;
	i = stack->top;
	while (i >= 0 && stack->arr[i] != nearest)
	{
		count++;
		i--;
	}
	return (count);
}

int	count_move_start_bot(t_dynamic_tab *cost_b, t_stack *stack,
	int element, int nearest)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < stack->top && stack->arr[i] != nearest)
	{
		count++;
		i++;
	}
	return (count);
}

int	nearest_of_element(t_stack *stack, int element)
{
	int	i;
	int	nearest;
	int	result;
	int	last_result;

	i = stack->top;
	nearest = stack->arr[i];
	last_result = positive_subtraction(stack->arr[i], element);
	while (i >= 0)
	{
		result = positive_subtraction(stack->arr[i], element);
		if (result < last_result)
		{
			nearest = stack->arr[i];
			last_result = result;
		}
		i--;
	}
	return (nearest);
}

void	up_nearest_position(t_dynamic_tab *cost_b, t_stack *stack,
		int element, int nearest)
{
	int	move_from_top;

	move_from_top = count_move_start_top(cost_b, stack, element, nearest);
	while (move_from_top != 0)
	{
		cost_b->arr[cost_b->current_size++] = RB;
		move_from_top--;
	}
}

void	down_nearest_position(t_dynamic_tab *cost_b, t_stack *stack,
		int element, int nearest)
{
	int	move_from_bot;

	move_from_bot = count_move_start_bot(cost_b, stack, element, nearest);
	while (move_from_bot != 0)
	{
		cost_b->arr[cost_b->current_size++] = RRB;
		move_from_bot--;
	}
}
