/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:15:54 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/01 17:24:52 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	message_operation(int operation)
{
	char base;

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
