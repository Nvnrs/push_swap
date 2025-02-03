/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:15:19 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/03 19:36:57 by nveneros         ###   ########.fr       */
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
		// ft_printf("START FOR EL ________%d\n", element->element);
		get_costs_a(element->a, stacks->a, i);
		get_costs_b(element->b, stacks->b, element->element, i);
		get_total_costs(element);
		// ft_printf("OPERATION %d \n", element->total->current_size);
		if (best == NULL)
		{
			// ft_printf("START BEST %d \n", element->total->current_size);
			best = element;
			element = NULL;
		}
		else if (element->total->current_size < best->total->current_size)
		{
			// ft_printf("NEW BEST %d \n", element->total->current_size);
			free_costs(best);
			best = element;
			element = NULL;
		}
		if (element != NULL)
			free_costs(element);
		i--;
		// ft_printf("\n");
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

void	start_push(t_stacks *stacks)
{
	push(stacks->a, stacks->b, PB);
	push(stacks->a, stacks->b, PB);
	if (top(stacks->b) < stacks->b->arr[stacks->b->top -1])
	{
		// ft_printf("rotate start\n");
		rotate(stacks->b, RB);
	}
}

int	get_index_max_in_stack(t_stack *stack)
{
	int max;
	int next;

	max = stack->top;
	next = stack->top -1;
	while (next > 0)
	{
		if (stack->arr[next] > stack->arr[max])
			max = next;
		next--;
	}
	// ft_printf("MAX VAL IN STACK %d\n", stack->arr[max]);
	// print_stack(stack);
	// ft_printf("\n");
	return (max);
}

void	put_max_to_top_b(t_stacks *stacks)
{
	int operation;
	int i_val_max;
	int middle_stack;

	i_val_max = get_index_max_in_stack(stacks->b);
	middle_stack = stacks->b->top / 2;
	if (i_val_max >= middle_stack)
		operation = RB;
	else
		operation = RRB;
	while (!top_is_max(stacks->b))
		select_operation(stacks, operation);
}

void	turk_sort(t_stacks *stacks)
{
	t_costs	*selected_el;

	int i = 1;
	ft_printf("turk sort\n");
	start_push(stacks);
	while (stack_len(stacks->a) > 3)
	{
		selected_el = find_low_cost_element(stacks);
		run_operations(stacks, selected_el);
		// run_operations_without_opti(stacks, selected_el->a);
		// run_operations_without_opti(stacks, selected_el->b);
		// get_index_max_in_stack(stacks->b);
		// while(!top_is_max(stacks->b))
		// {
		// 	rotate(stacks->b, RB);
		// }
		// ft_printf("nb instru %d\n", selected_el->total->current_size);
		// print_instructions(selected_el->total);
		free_costs(selected_el);
	}
	put_max_to_top_b(stacks);

	// reverse_rotate(stacks->b, RB);
	// if (!stack_is_sorted(stacks->b))
	// print_stack(stacks->a);
	// ft_printf("\n");
	// print_stack(stacks->b);
	// handle if 3
}

void	sort(t_stacks *stacks)
{
	if (stack_is_sorted(stacks->a))
	{
		ft_printf("sdtacks is sorted");
		return ;
	}
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