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
void		ft_check_2(t_so_long *so_long, t_map *map);
void		ft_check_3(t_so_long *so_long, int exit, int perso, int collec);
void		ft_check_4(t_so_long *so_long, t_map *map);
void		ft_check_5(t_so_long *so_long, t_map *map);
void		ft_check_6(t_so_long *so_long, t_map *map);
// -----------------------------------------------------

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
			{
				so_long->p->x = j;
				so_long->p->y = i;
				perso++;
			}
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
	size_t		j;

	j = 0;
	while (j < map->width)
		if (map->map[0][j++] != '1')
			return (ft_error(so_long, 247));
	j = 0;
	while (j < map->width)
		if (map->map[map->height - 1][j++] != '1')
			return (ft_error(so_long, 247));
	j = 0;
	while (j < map->height)
		if (map->map[j++][0] != '1')
			return (ft_error(so_long, 247));
	j = 0;
	while (j < map->height)
		if (map->map[j++][map->width - 1] != '1')
			return (ft_error(so_long, 247));
}

void	ft_check_5(t_so_long *so_long, t_map *map)
{
	char		**out;
	size_t		i;
	size_t		j;
	t_point		size;
	t_point		begin;

	size.x = map->width;
	size.y = map->height;
	begin.x = so_long->p->x;
	begin.y = so_long->p->y;
	out = ft_strsdup((const char **)map->map);
	flood_fill(out, size, begin, "0CP");
	i = 0;
	while (out[i])
	{
		j = 0;
		while (out[i][j])
			if (out[i][j++] == 'C')
				return (ft_free_strs(map, (void **)out, 'c'),
					ft_error(so_long, 246));
		i++;
	}
	ft_free_strs(map, (void **)out, 'c');
}

void	ft_check_6(t_so_long *so_long, t_map *map)
{
	char		**out;
	size_t		i;
	size_t		j;
	t_point		size;
	t_point		begin;

	size.x = map->width;
	size.y = map->height;
	begin.x = so_long->p->x;
	begin.y = so_long->p->y;
	out = ft_strsdup((const char **)map->map);
	flood_fill(out, size, begin, "0CPE");
	i = 0;
	while (out[i])
	{
		j = 0;
		while (out[i][j])
			if (out[i][j++] == 'E')
				return (ft_free_strs(map, (void **)out, 'c'),
					ft_error(so_long, 246));
		i++;
	}
	ft_free_strs(map, (void **)out, 'c');
}