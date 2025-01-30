/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:37:29 by nveneros          #+#    #+#             */
/*   Updated: 2025/01/30 11:38:00 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// ss : sa et sb en même temps.

void	test_swap(t_stack *stack, char *message)
{
	ft_printf("BFR | ");
	ft_printf("TOP :%d\n", top(stack));
	swap(stack, message);
	ft_printf("AFT | ");
	ft_printf("TOP :%d\n", top(stack));
}

void	test_swap_stacks(t_stacks *stacks)
{
	ft_printf("BFR A | ");
	ft_printf("TOP :%d\n", top(stacks->a));
	ft_printf("BFR B | ");
	ft_printf("TOP :%d\n", top(stacks->b));
	swap_stacks(stacks);
	ft_printf("AFT A | ");
	ft_printf("TOP :%d\n", top(stacks->a));
	ft_printf("AFT B | ");
	ft_printf("TOP :%d\n", top(stacks->b));
}
void swap(t_stack *stack, char *message)
{
	int	temp_top;

	if (message != NULL)
		ft_printf("%s", message);
	if (stack_len(stack) < 2)
	{
		ft_printf("stack < 2");
		return ;
	}
	temp_top = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top -1];
	stack->arr[stack->top -1]  = temp_top;
}

void	swap_stacks(t_stacks *stacks)
{
	swap(stacks->a, NULL);
	swap(stacks->b, NULL);
	ft_printf("%s", SS);
}