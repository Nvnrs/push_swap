/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:38:12 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/04 09:09:48 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_remains(t_costs *costs, t_dynamic_tab *cost_n, int i)
{
	int ope;

	while (i < cost_n->current_size)
	{
		ope = cost_n->arr[i];
		// ft_printf("ope 2 %d\n", cost_n->arr[i]);
		costs->total->arr[costs->total->current_size++] = ope;
		i++;
	}
}

// void	get_total_costs(t_costs *costs)
// {
// 	int i;
// 	int j;
// 	int ope_a;
// 	int ope_b;

// 	i = 0;
// 	// ft_printf("LENGTH a : %d\n", costs->a->current_size);
// 	// ft_printf("LENGTH b : %d\n", costs->b->current_size);
// 	while (i < costs->a->current_size
// 		&& i < costs->b->current_size)
// 	{
// 		ope_a = costs->a->arr[i];
// 		ope_b = costs->b->arr[i];
// 		if ((ope_a / 10) == (ope_b / 10))
// 		{
// 			// ft_printf("combi a %d\n", costs->a->arr[i]);
// 			// ft_printf("combi b %d\n", costs->b->arr[i]);
// 			costs->total->arr[costs->total->current_size++] = ope_a -1;
// 			i++;
// 			continue;
// 		}
// 		costs->total->arr[costs->total->current_size++] = ope_a;
// 		costs->total->arr[costs->total->current_size++] = ope_b;
// 		i++;
// 	}  
// 	j = i;
// 	// ft_printf("REMAINS A\n");
// 	add_remains(costs, costs->a, i);
// 	// ft_printf("REMAINS B\n");
// 	add_remains(costs, costs->b, j);
// 	// ft_printf("TOTAL %d\n", costs->total->current_size);
// }

void	print_dynamic_tab(t_dynamic_tab *tab)
{	
	int i;

	i = 0;
	while (i < tab->current_size)
	{
		/* code */
		ft_printf("%d ", tab->arr[i]);
		if (i == tab->current_size -1)
			ft_printf("\n");
		i++;
	}	
}

void	get_total_costs(t_costs *costs)
{
	int a;
	int b;
	int ope_a;
	int ope_b;

	a = 0;
	b = 0;
	// copy A and combine
	// ft_printf("A : %d\n", costs->a->current_size);
	// print_dynamic_tab(costs->a);
	// ft_printf("B : %d\n", costs->b->current_size);
	// print_dynamic_tab(costs->b);
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
	// ft_printf("TOTAL : %d\n", costs->total->current_size);
	// print_dynamic_tab(costs->total);
	
}