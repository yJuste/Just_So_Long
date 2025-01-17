/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

// ---------------------PROTOTYPE----------------------
void		ft_image_space(t_so_long *so_long);
void		ft_image_walls(t_so_long *so_long);
void		ft_image_stars(t_so_long *so_long);
void		ft_image_ship(t_so_long *so_long);
void		ft_image_astronaut(t_so_long *so_long);
// ----------------------------------------------------

void	ft_image_space(t_so_long *so_long)
{
	int		width;
	int		height;

	width = 64;
	height = 64;
	so_long->img->space = mlx_xpm_file_to_window(so_long->mlx,
			"Images/space.xpm", &width, &height);
}

void	ft_image_walls(t_so_long *so_long)
{
	int		width;
	int		height;

	width = 64;
	height = 64;
	so_long->img->walls = mlx_xpm_file_to_window(so_long->mlx,
			"Images/walls.xpm", &width, &height);
}

void	ft_image_stars(t_so_long *so_long)
{
	int		width;
	int		height;

	width = 64;
	height = 64;
	so_long->img->stars = mlx_xpm_file_to_window(so_long->mlx,
			"Images/stars.xpm", &width, &height);
}

void	ft_image_ship(t_so_long *so_long)
{
	int		width;
	int		height;

	width = 64;
	height = 64;
	so_long->img->ship = mlx_xpm_file_to_window(so_long->mlx,
			"Images/ship.xpm", &width, &height);
}

void	ft_image_astronaut(t_so_long *so_long)
{
	int		width;
	int		height;

	width = 64;
	height = 64;
	so_long->img->astronaut = mlx_xpm_file_to_window(so_long->mlx,
			"Images/astronaut.xpm", &width, &height);
}
