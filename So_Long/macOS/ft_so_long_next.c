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
	int			x;
	int			y;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			x = j * SPT;
			y = i * SPT;
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->img->space, x, y);
			j++;
		}
		i++;
	}
}
