/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:15:19 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/02 18:02:07 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	stack_is_sorted(t_stack *stack)
{
	int i;
	int curr;
	int next;

	i = stack->top;
	while (i > 0)
	{
		curr = stack->arr[i];
		next = stack->arr[i - 1];
		if (curr > next)
			return (FALSE);
		i --;
	}
	return (TRUE);
}

void	run_operations(t_stacks *stacks, t_costs *costs)
{
	int i;
	int	operation;

	i = 0;
	while (i < costs->total->current_size)
	{
		operation = costs->total->arr[i];
		select_operation(stacks, operation);
		i++;
	}
}


void	run_operations_without_opti(t_stacks *stacks, t_dynamic_tab *costs)
{
	int i;
	int	operation;

	i = 0;
	while (i < costs->current_size)
	{
		operation = costs->arr[i];
		select_operation(stacks, operation);
		i++;
	}
}


t_costs	*find_low_cost_element(t_stacks *stacks)
{
	t_costs *element;
	t_costs *best;
	int		i;

	best = NULL;
	i = stacks->a->top;
	while (i >= 0)
	{
 		element = init_costs(stacks->a->arr[i], stacks->a->max);
		ft_printf("START FOR EL ________%d\n", element->element);
		get_costs_a(element->a, stacks->a, i);
		get_costs_b(element->b, stacks->b, element->element);
		get_total_costs(element);
		if (best == NULL)
		{
			ft_printf("START BEST %d \n", element->total->current_size);
			best = element;
			element = NULL;
		}
		else if (element->total->current_size < best->total->current_size)
		{
			ft_printf("NEW BEST %d \n", element->total->current_size);
			free_costs(best);
			best = element;
			element = NULL;
		}
		if (element != NULL)
			free_costs(element);
		i--;
		ft_printf("\n");
	}
	return (best);
}

// void	bubble_sort_inversed(t_stacks)
// {
	
// }

void	print_instructions(t_dynamic_tab *cost_n)
{
	int j = 0;
	while (j < cost_n->current_size)
	{
		ft_printf("%d ", cost_n->arr[j]);
		if (j == cost_n->current_size)
			ft_printf("\n");
		j++;
	}		
}

void	turk_sort(t_stacks *stacks)
{
	t_costs	*selected_el;

	ft_printf("turk sort\n");
	push(stacks->a, stacks->b, PB);
	push(stacks->a, stacks->b, PB);
	while (stack_len(stacks->a) > 3)
	{
		selected_el = find_low_cost_element(stacks);
		run_operations(stacks, selected_el);
		// ft_printf("nb instru %d\n", selected_el->total->current_size);
		// print_instructions(selected_el->total);
		// run_operations_without_opti(stacks, selected_el->a);
		// run_operations_without_opti(stacks, selected_el->b);
		free_costs(selected_el);
	}

	
	// reverse_rotate(stacks->b, RB);
	// if (!stack_is_sorted(stacks->b))
	print_stack(stacks->a);
	print_stack(stacks->b);
	// handle if 3
}

void	sort(t_stacks *stacks)
{
	if (stack_is_sorted(stacks->a))
		return ;
	if (stacks->a->max == 3)
	{
		ft_printf("use _algo for 3\n");
		return;
	} 
	else
		turk_sort(stacks);
	// ft_printf("len stack A : %d\n", stack_len(stacks->a));
	// ft_printf("len stack B : %d\n", stack_len(stacks->b));
	// reverse_rotate(stacks->a, RA);

}