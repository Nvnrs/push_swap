/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:28:32 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:29:01 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_dynamic_tab(t_dynamic_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->current_size)
	{
		ft_printf("%d ", tab->arr[i]);
		if (i == tab->current_size -1)
			ft_printf("\n");
		i++;
	}
}

int	positive_subtraction(int n1, int n2)
{
	int	result;

	result = n1 - n2;
	if (result < 0)
		result *= -1;
	return (result);
}
