/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:15:54 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:07:30 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	message_operation(int operation)
{
	char	base;

	if (operation >= SS && operation <= SB)
		base = 's';
	else if (operation >= PA && operation <= PB)
		base = 'p';
	else if (operation >= RR && operation <= RB)
		base = 'r';
	else if (operation >= RRR && operation <= RRB)
	{
		base = 'r';
		ft_printf("%c", base);
	}
	ft_printf("%c", base);
	if (operation % 10 == 1)
		ft_printf("a");
	else if (operation % 10 == 2)
		ft_printf("b");
	else
		ft_printf("%c", base);
	ft_printf("\n");
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
