/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:26:18 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/02 14:10:31 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_middle_top_stack(t_dynamic_tab *cost_a, t_stack *stack, int i_el)
{
	int i_el_copy;
	int top_stack;

	// ft_printf("mid TOP\n");
	i_el_copy = i_el;
	top_stack = stack->top;
	while (i_el_copy != top_stack)
	{
		// ft_printf("RA for %d\n", stack->arr[i_el]);
		cost_a->arr[cost_a->current_size++] =  RA;
		i_el_copy++;
	}
}

void	handle_middle_bot_stack(t_dynamic_tab *cost_a, t_stack *stack, int i_el)
{
	int i_el_copy;

	// ft_printf("mid BOT\n");
	i_el_copy = i_el;
	while (i_el_copy != 0)
	{
		// ft_printf("RRA for %d\n", stack->arr[i_el]);
		cost_a->arr[cost_a->current_size++] =  RRA;
		i_el_copy--;
	}
	// ft_printf("RRA for %d\n", stack->arr[i_el]);
	cost_a->arr[cost_a->current_size++] =  RRA;
	i_el_copy--;
}

void	get_costs_a(t_dynamic_tab *cost_a, t_stack *stack, int i_el)
{
	int middle_stack;
	int top_stack;

	middle_stack = (stack->top / 2);
	top_stack = stack->top;
	// top

	// ft_printf("I_el %d VS TOP %d\n", i_el, stack->top);
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
