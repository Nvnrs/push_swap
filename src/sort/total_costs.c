/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:38:12 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/04 16:36:03 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_remains(t_costs *costs, t_dynamic_tab *cost_n, int i)
{
	int ope;

	while (i < cost_n->current_size)
	{
		ope = cost_n->arr[i];
		costs->total->arr[costs->total->current_size++] = ope;
		i++;
	}
}

void	get_total_costs(t_costs *costs)
{
	int	a;
	int	b;
	int	ope_a;
	int	ope_b;

	a = 0;
	ope_a = costs->a->arr[a];
	ope_b = costs->b->arr[a];
	while (a < costs->a->current_size && a < costs->b->current_size
		&& (ope_a / 10) == (ope_b / 10))
	{
		costs->total->arr[costs->total->current_size++] = ope_a -1;
		a++;
		ope_a = costs->a->arr[a];
		ope_b = costs->b->arr[a];
	}
	b = a;
	add_remains(costs, costs->a, a);
	add_remains(costs, costs->b, b);	
}
