/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:26:18 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/04 16:37:27 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_middle_top_stack(t_dynamic_tab *cost_a, t_stack *stack, int i_el)
{
	int top_stack;

	top_stack = stack->top;
	while (i_el != top_stack)
	{
		cost_a->arr[cost_a->current_size++] =  RA;
		i_el++;
	}
}

void	handle_middle_bot_stack(t_dynamic_tab *cost_a, t_stack *stack, int i_el)
{
	while (i_el != 0)
	{
		cost_a->arr[cost_a->current_size++] =  RRA;
		i_el--;
	}
	cost_a->arr[cost_a->current_size++] =  RRA;
	i_el--;
}

void	get_costs_a(t_dynamic_tab *cost_a, t_stack *stack, int i_el)
{
	int middle_stack;
	int top_stack;

	middle_stack = (stack->top / 2);
	top_stack = stack->top;

	if (i_el == top_stack)
		return ;
	else if (i_el == 0)
	{
		cost_a->arr[cost_a->current_size++] = RRA;
		return;
	}
	if (i_el >= middle_stack)
		handle_middle_top_stack(cost_a, stack, i_el);
	else
		handle_middle_bot_stack(cost_a, stack, i_el);
}
