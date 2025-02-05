/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:32:28 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:20:26 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	run_operations(t_stacks *stacks, t_costs *costs)
{
	int	i;
	int	operation;

	i = 0;
	while (i < costs->total->current_size)
	{
		operation = costs->total->arr[i];
		select_operation(stacks, operation);
		i++;
	}
}

void	put_max_to_top_b(t_stacks *stacks)
{
	int	operation;
	int	i_val_max;
	int	middle_stack;

	i_val_max = get_index_max_in_stack(stacks->b);
	middle_stack = stacks->b->top / 2;
	if (i_val_max >= middle_stack)
		operation = RB;
	else
		operation = RRB;
	while (!top_is_max(stacks->b))
		select_operation(stacks, operation);
}

void	back_to_a(t_stacks *stacks)
{
	int	from_b;
	int	last_a;
	int	len_stack;
	int	i;

	i = 0;
	len_stack = stack_len(stacks->a);
	while (!stack_empty(stacks->b))
	{
		last_a = stacks->a->arr[0];
		from_b = top(stacks->b);
		while (last_a > from_b && i < len_stack)
		{
			reverse_rotate(stacks->a, RRA);
			last_a = stacks->a->arr[0];
			i++;
		}
		push(stacks->b, stacks->a, PA);
	}
	while (!stack_is_sorted(stacks->a))
		reverse_rotate(stacks->a, RRA);
}

void	start_push(t_stacks *stacks)
{
	push(stacks->a, stacks->b, PB);
	push(stacks->a, stacks->b, PB);
	if (top(stacks->b) < stacks->b->arr[stacks->b->top -1])
		rotate(stacks->b, RB);
}

void	turk_sort(t_stacks *stacks)
{
	t_costs	*selected_el;

	start_push(stacks);
	while (stack_len(stacks->a) > 3)
	{
		selected_el = find_low_cost_element(stacks);
		run_operations(stacks, selected_el);
		free_costs(selected_el);
	}
	put_max_to_top_b(stacks);
	three_sort(stacks->a);
	back_to_a(stacks);
}
