/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_strs_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:41:30 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/02 09:58:05 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_tab_int(t_tab_int *tab_int)
{
	free(tab_int->arr);
	free(tab_int);
}

t_tab_int	*conv_tab_strs_to_int(int nb_str, char **tab_str)
{
	int			i;
	t_tab_int	*tab_int;

	i = 0;
	tab_int = malloc(sizeof(t_tab_int));
	tab_int->arr = malloc(nb_str * sizeof(int));
	if (tab_int->arr == NULL)
		return (NULL);
	tab_int->max = nb_str;
	if (tab_int == NULL)
		return (NULL);
	while (tab_str[i])
	{
		tab_int->arr[i] = ft_atoi(tab_str[i]);
		i++;
	}
	return (tab_int);
}
