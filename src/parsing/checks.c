/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:57:09 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:08:48 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	is_only_digit(char *str)
{
	int	i;
	int	sign;

	i = 0;
	if (str[i] == '-' && str[i + 1])
		i++;
	else if (str[i] == '-')
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	only_val_in_tab(int nb_val, int *tab)
{
	int	i;

	i = 0;
	while (i < nb_val)
	{
		if (!comp_val_with_other(i, nb_val, tab))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	comp_val_with_other(int i_val, int nb_val, int *tab)
{
	int	i;

	i = 0;
	while (i < nb_val)
	{
		if (i != i_val)
		{
			if (tab[i] == tab[i_val])
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	is_int(char *str)
{
	int		len_str;
	char	*comp;
	t_bool	is_negative;

	comp = MAX_INT_STR;
	if (str[0] == '-')
	{
		str++;
		comp = MIN_INT_STR;
	}
	len_str = ft_strlen(str);
	if (len_str < MAX_INT_LENGTH)
		return (TRUE);
	if (len_str > MAX_INT_LENGTH)
		return (FALSE);
	if (ft_strncmp(str, comp, len_str) > 0)
		return (FALSE);
	return (TRUE);
}

t_bool	check_list_of_arg(int max_str, char **tab_str)
{
	int	i;

	i = 0;
	while (i < max_str)
	{
		if (!is_only_digit(tab_str[i]))
			return (FALSE);
		if (!is_int(tab_str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
