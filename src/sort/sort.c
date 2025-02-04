/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:15:19 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/04 11:34:31 by nveneros         ###   ########.fr       */
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

void	print_instructions(t_dynamic_tab *cost_n)
{
	int j = 0;
	while (j < cost_n->current_size)
	{
		ft_printf("%d ", cost_n->arr[j]);
		if (j == cost_n->current_size -1)
			ft_printf("\n");
		j++;
	}		
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

void	three_sort(t_stack *stack)
{
	int top;
	int mid;
	int last;

	top = stack->arr[stack->top];
	mid = stack->arr[stack->top - 1];
	last = stack->arr[0];
	if (stack_is_sorted(stack))
		return;
	if (last > mid && last > top)
		swap(stack, SA);
	else if (top > mid && mid > last)
	{
		swap(stack, SA);
		reverse_rotate(stack, RRA);
	}
	else if (top > mid && top > last)
		rotate(stack, RA);
	else if (last < mid && last < top)
		reverse_rotate(stack, RRA);
	else if (top < mid && last < mid)
	{
		swap(stack, SA);
		rotate(stack, RA);
	}
	print_stack(stack);
}

void	back_to_a(t_stacks *stacks)
{
	int from_b;
	int last_a;
	int	i;

	i = 0;
	while (!stack_empty(stacks->b))
	{
		last_a = stacks->a->arr[0];
		from_b = top(stacks->b);
		while (last_a > from_b && i < 3)
		{
			reverse_rotate(stacks->a, RRA);
			last_a = stacks->a->arr[0];
			i++;
		}
		push(stacks->b, stacks->a, PA);
	}
}

void	turk_sort(t_stacks *stacks)
{
	t_costs	*selected_el;

	int i = 1;
	// ft_printf("turk sort\n");
	start_push(stacks);
	while (stack_len(stacks->a) > 3)
	{
		selected_el = find_low_cost_element(stacks);
		// ft_printf("RUN for %d\n", selected_el->element);
		// ft_printf("A :");
		// print_instructions(selected_el->a);
		// ft_printf("B :");
		// print_instructions(selected_el->b);
		// ft_printf("T :");
		// print_instructions(selected_el->total);
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
	three_sort(stacks->a);
	back_to_a(stacks);

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
		three_sort(stacks->a);
		print_stack(stacks->a);
		return;
	} 
	else
		turk_sort(stacks);
	// ft_printf("len stack A : %d\n", stack_len(stacks->a));
	// ft_printf("len stack B : %d\n", stack_len(stacks->b));
	// reverse_rotate(stacks->a, RA);

}