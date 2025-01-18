/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Affiche les éléments visuels.                                          */
/* ************************************************************************** */
#include "ft_so_long.h"

// ----------------------------------PROTOTYPE----------------------------------
void		ft_so_long(t_so_long *so_long);
void		ft_print_background(t_so_long *so_long, t_map *map);
void		ft_print_astronaut(t_so_long *so_long, t_map *map, int x, int y);
void		ft_inspect_movements(t_so_long *so_long, t_map *map,
				t_point cur, t_point next);
// -----------------------------------------------------------------------------

// Fonction d'initialisation du jeu.
// 1. Alloue de la mémoire pour les images.
// 2. Affiche les éléments.
void	ft_so_long(t_so_long *so_long)
{
	ft_image_space(so_long);
	ft_image_walls(so_long);
	ft_image_stars(so_long);
	ft_image_ship(so_long);
	ft_image_astronaut(so_long);
	ft_print_background(so_long, so_long->map);
	ft_print_astronaut(so_long, so_long->map, -1, -1);
}

// Affiche le background: mur, collectible, sortie, vide.
void	ft_print_background(t_so_long *so_long, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img->walls, j * SPT, i * SPT);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img->stars, j * SPT, i * SPT);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img->ship, j * SPT, i * SPT);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img->space, j * SPT, i * SPT);
			j++;
		}
		i++;
	}
}

// Affiche l'astronaute.
void	ft_print_astronaut(t_so_long *so_long, t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	if (x >= 0 && y >= 0)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->img->space, x * SPT, y * SPT);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img->astronaut, j * SPT, i * SPT);
			j++;
		}
		i++;
	}
}

// Check les mouvements de l'astronaute quand il bouge.
void	ft_inspect_movements(t_so_long *so_long, t_map *map,
		t_point cur, t_point next)
{
	if (next.y < 0 || next.y >= map->height
		|| next.x < 0 || next.x >= map->width)
		return ;
	else if (map->map[next.y][next.x] == '1')
		return ;
	else if (map->map[next.y][next.x] == 'E')
	{
		if (map->max_stars != 0)
			return ;
		else
			return (ft_free_so_long(so_long),
				write(1, "You won, congratulations!\n", 26),
				exit(0));
	}
	so_long->p->x = next.x;
	so_long->p->y = next.y;
	if (map->map[next.y][next.x] == 'C')
	{
		map->map[next.y][next.x] = '0';
		map->max_stars -= 1;
	}
	ft_swap_extra(&so_long->map->map[cur.y][cur.x],
		&so_long->map->map[next.y][next.x]);
}
