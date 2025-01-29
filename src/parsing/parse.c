/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:09:58 by nveneros          #+#    #+#             */
/*   Updated: 2025/01/29 09:48:45 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	nb_of_split(char **split_str)
{
	int	i;

	i = 0;
	if (split_str == NULL)
		return (i);
	while (split_str[i])
		i++;
	return (i);
}

void	free_tab_str(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
}
void	*error_parsing(t_bool tab_str_is_malloc, char **tab_str, t_tab_int *tab_int)
{
	ft_putstr_fd("Error\n", 2);
	if (tab_str && tab_str_is_malloc)
		free_tab_str(tab_str);
	if (tab_int)
		free_tab_int(tab_int);
	return (NULL);
}

t_tab_int	*parse_data(int argc, char **argv)
{
	char		**data;
	t_tab_int	*tab_int;
	int			nb_str;
	t_bool		tab_str_is_malloc;

	data = &argv[1];
	nb_str = argc -1;
	tab_str_is_malloc = FALSE;
	if (argc == 2)
	{
		tab_str_is_malloc = TRUE;
		data = ft_split(argv[1], ' ');
		nb_str = nb_of_split(data);
	}
	if (!check_list_of_arg(nb_str, data))
		return (error_parsing(tab_str_is_malloc, data, NULL));
	tab_int = conv_tab_strs_to_int(nb_str, data);
	if (!only_val_in_tab(tab_int->max, tab_int->arr))
		return (error_parsing(tab_str_is_malloc, data, tab_int));
	if (tab_str_is_malloc)
		free_tab_str(data);
	return (tab_int);
}
