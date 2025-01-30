/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:44:57 by nveneros          #+#    #+#             */
/*   Updated: 2025/01/30 08:42:54 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_tab_int	*tab_int;
	t_stacks	*stacks;

	if (argc == 1)
		return (EXIT_FAILURE);
	tab_int = parse_data(argc, argv);
	if (tab_int == NULL)
		return (EXIT_FAILURE);
	stacks = init_stacks(tab_int);
	if (stacks == NULL)
		return (free_tab_int(tab_int), EXIT_FAILURE);
	sort(stacks);
	free_tab_int(tab_int);
	free_stacks(stacks);
	return (EXIT_SUCCESS);
}
