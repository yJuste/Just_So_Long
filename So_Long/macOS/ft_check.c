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
/*   • Analyse la map.                                               PART 2   */
/* ************************************************************************** */
#include "ft_so_long.h"

// -----------------------------PROTOTYPE---------------------------
void		ft_check_2(t_so_long *so_long, t_map *map);
void		ft_check_3(t_so_long *so_long, int exit, int perso);
void		ft_check_4(t_so_long *so_long, t_map *map);
void		ft_check_5(t_so_long *so_long, t_map *map);
void		ft_check_6(t_so_long *so_long, t_map *map);
// -----------------------------------------------------------------

// Fonction qui gère les lignes et les caractères invalides.
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

// Fonction qui gère le nombre de caractères minimum.
void	ft_check_3(t_so_long *so_long, int exit, int perso)
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
				so_long->map->max_stars++;
			j++;
		}
		i++;
	}
	if (exit != 1 || perso != 1 || so_long->map->max_stars < 1)
		return (ft_error(so_long, 248));
}

// Fonction qui gère que la map soit encadré par des murs.
void	ft_check_4(t_so_long *so_long, t_map *map)
{
	int		j;

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

// Fonction qui analyse si le joueur peut récupérer tous les collectibles.
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

// Fonction qui analyse si le joueur peut aussi sortir.
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
	flood_fill(out, size, begin, "0CEP");
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
