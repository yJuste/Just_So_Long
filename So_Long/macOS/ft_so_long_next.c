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
#include "ft_so_long.h"

// ---------------------PROTOTYPE-----------------------
void		ft_so_long(t_so_long *so_long);
void		ft_print_background(t_so_long *so_long, t_map *map);
void		ft_print_astronaut(t_so_long *so_long, t_map *map, int x, int y);
int			ft_inspect_movements(t_so_long *so_long, t_map *map, t_point p);
// -----------------------------------------------------

void	ft_so_long(t_so_long *so_long)
{
	ft_image_space(so_long);
	ft_image_walls(so_long);
	ft_image_stars(so_long);
	ft_image_ship(so_long);
	ft_image_astronaut(so_long);
	ft_print_background(so_long, so_long->map);
}

void	ft_print_background(t_so_long *so_long, t_map *map)
{
	size_t		i;
	size_t		j;

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

void	ft_print_astronaut(t_so_long *so_long, t_map *map, int x, int y)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img->astronaut, j * SPT, i * SPT);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img->space, j * SPT, i * SPT);
			j++;
		}
		i++;
	}
}

int	ft_inspect_movements(t_so_long *so_long, t_map *map, t_point p)
{
	if (p.y < 0 || p.y >= map->height
		|| p.x < 0 || p.x >= map->width)
		return (1);
	if (map->map[p.y][p.x] == '1')
		return (1);
	return (0);
}
