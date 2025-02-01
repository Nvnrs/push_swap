/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:15:19 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/01 18:09:27 by nveneros         ###   ########.fr       */
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

void	select_operation(t_stacks *stacks, int operation)
{
	if (operation == PA)
		push(stacks->b, stacks->a, PA);
	else if (operation == PB)
		push(stacks->a, stacks->b, PB);
	else if (operation == SS)
		swap_stacks(stacks);
	else if (operation == SA)
		swap(stacks->a, SA);
	else if (operation == SB)
		swap(stacks->b, SB);
	else if (operation == RA)
		rotate(stacks->a, RA);
	else if (operation == RB)
		rotate(stacks->b, RB);
	else if (operation == RR)
		rotate_stacks(stacks);
	else if (operation == RRA)
		reverse_rotate(stacks->a, RRA);
	else if (operation == RRB)
		reverse_rotate(stacks->b, RRB);
	else if (operation == RRR)
		reverse_rotate_stacks(stacks);
}


void	run_operations(t_stacks *stacks, t_costs *element)
{
	int i;
	int	operation;

	i = 0;
	while (i < element->cost_t->max)
	{
		operation = element->cost_t->arr[i];
		select_operation(stacks, operation);
		i++;
	}
		
}

void	turk_sort(t_stacks *stacks)
{
	t_costs	*selected_el;

	ft_printf("turk sort\n");
	// while (stack_len(stacks->a) > 3)
	// {
	// 	/* code */
	// 	selected_el = get_cost();
	// 	run_operatrions(selected_el);
	// }	
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
	ft_printf("len stack A : %d\n", stack_len(stacks->a));
	ft_printf("len stack B : %d\n", stack_len(stacks->b));
	reverse_rotate(stacks->a, RA);
	print_stack(stacks->a);
}