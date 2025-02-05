/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_low_costs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:34:15 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:16:53 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_costs	*look_if_new_best_cost(t_costs *element, t_costs *last_best)
{
	t_costs	*new_best;

	new_best = last_best;
	if (last_best == NULL)
	{
		new_best = element;
		element = NULL;
	}
	else if (element->total->current_size < last_best->total->current_size)
	{
		free_costs(last_best);
		new_best = element;
		element = NULL;
	}
	if (element != NULL)
		free_costs(element);
	return (new_best);
}

t_costs	*find_low_cost_element(t_stacks *stacks)
{
	t_costs	*element;
	t_costs	*best;
	int		i;

	best = NULL;
	i = stacks->a->top;
	while (i >= 0)
	{
		element = init_costs(stacks->a->arr[i], stacks->a->max);
		get_costs_a(element->a, stacks->a, i);
		get_costs_b(element->b, stacks->b, element->element, i);
		get_total_costs(element);
		best = look_if_new_best_cost(element, best);
		i--;
	}
	return (best);
}
