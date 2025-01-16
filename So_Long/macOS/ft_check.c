/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

// ---------------------PROTOTYPE-----------------------
void		ft_check(t_so_long *so_long, t_map *map);
void		ft_check_2(t_so_long *so_long, t_map *map);
void		ft_check_3(t_so_long *so_long, int exit, int perso, int collec);
void		ft_check_4(t_so_long *so_long, t_map *map);
// -----------------------------------------------------

void	ft_check(t_so_long *so_long, t_map *map)
{
	ft_check_2(so_long, map);
	ft_check_3(so_long, 0, 0, 0);
	ft_check_4(so_long, map);
}

void	ft_check_2(t_so_long *so_long, t_map *map)
{
	size_t		i;
	size_t		j;
	size_t		len1;
	size_t		len2;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] == '\0')
			return (ft_error(so_long, 250));
		j = 0;
		while (map->map[i][j])
			if (ft_is_separator(map->map[i][j++], "01CEP") == 0)
				return (ft_error(so_long, 249));
		i++;
	}
	i = 0;
	while (map->map[i + 1])
	{
		len1 = ft_strlen((const char *)map->map[i]);
		len2 = ft_strlen((const char *)map->map[i + 1]);
		if (len1 != len2)
			return (ft_error(so_long, 252));
		i++;
	}
}

void	ft_check_3(t_so_long *so_long, int exit, int perso, int collec)
{
	int			i;
	int			j;

	i = 0;
	while (so_long->map->map[i])
	{
		j = 0;
		while (so_long->map->map[i][j])
		{
			if (so_long->map->map[i][j] == 'E')
				exit++;
			else if (so_long->map->map[i][j] == 'P')
				perso++;
			else if (so_long->map->map[i][j] == 'C')
				collec++;
			j++;
		}
		i++;
	}
	if (exit != 1 || perso != 1 || collec < 1)
		return (ft_error(so_long, 248));
}

void	ft_check_4(t_so_long *so_long, t_map *map)
{
	return ;
}
