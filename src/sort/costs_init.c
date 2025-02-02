/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:24:49 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/02 12:01:34 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_costs(t_costs *costs)
{
	if (costs->a)
		free_dynamic_tab(costs->a);
	if (costs->b)
		free_dynamic_tab(costs->b);
	if (costs->total)
		free_dynamic_tab(costs->total);
	free(costs);
}

void	free_dynamic_tab(t_dynamic_tab *tab)
{
	free(tab->arr);
	free(tab);
}

t_dynamic_tab	*init_dynamic_tab(int max)
{
	int i;
	t_dynamic_tab	*tab;

	tab = malloc(sizeof(t_dynamic_tab));
	if (tab == NULL)
		return (NULL);
	tab->arr = malloc(max * sizeof(int));
	if (tab->arr == NULL)
	{
		free(tab);
		return (NULL);
	}
	tab->max = max;
	tab->current_size = 0;
	return (tab);
}


t_costs	*init_costs(int element, int max_size)
{
	t_costs	*costs;

	costs = malloc(sizeof(t_costs));
	costs->a = NULL;
	costs->b = NULL;
	costs->total = NULL;
	if (costs == NULL)
		return (NULL);
	costs->element = element;
	costs->a = init_dynamic_tab(max_size);
	if (costs->a == NULL)
		return (free_costs(costs), NULL);
	costs->b = init_dynamic_tab(max_size);
	if (costs->b == NULL)
		return (free_costs(costs), NULL);
	costs->total = init_dynamic_tab(max_size * 2);
	if (costs->total == NULL)
		return (free_costs(costs), NULL);\
	return (costs);
}