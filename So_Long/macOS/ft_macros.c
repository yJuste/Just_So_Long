/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

// ---------------------PROTOTYPE-----------------------
int			ft_key_hook(int keycode, t_so_long *so_long);
void		ft_key_movements(int keycode, t_so_long *so_long,
				t_map *map, t_point *p);
void		ft_key_movements_next(int keycode, t_so_long *so_long,
				t_map *map, t_point *p);
// -----------------------------------------------------

// Fonction principale qui appelle les différentes touches pressées.
int	ft_key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		ft_key_movements(keycode, so_long, so_long->map, so_long->p);
	else if (keycode == MAIN_PAD_ESC)
		ft_close_window(so_long);
	return (0);
}

void	ft_key_movements(int keycode, t_so_long *so_long,
			t_map *map, t_point *p)
{
	int		px;

	px = p->x;
	if (keycode == ARROW_LEFT)
	{
		if (ft_inspect_movements(so_long, so_long->map,
				(t_point){p->x - 1, p->y}) == 0)
		{
			ft_swap_extra(&map->map[p->y][p->x],
				&map->map[p->y][p->x - 1]);
			p->x -= 1;
		}
	}
	else if (keycode == ARROW_RIGHT)
	{
		if (ft_inspect_movements(so_long, so_long->map,
				(t_point){p->x + 1, p->y}) == 0)
		{
			ft_swap_extra(&map->map[p->y][p->x],
				&map->map[p->y][p->x + 1]);
			p->x += 1;
		}
	}
	ft_key_movements_next(keycode, so_long, map, p);
}

void	ft_key_movements_next(int keycode, t_so_long *so_long,
			t_map *map, t_point *p)
{
	int		py;

	py = p->y;
	if (keycode == ARROW_DOWN)
	{
		if (ft_inspect_movements(so_long, so_long->map,
				(t_point){p->x, p->y + 1}) == 0)
		{
			ft_swap_extra(&map->map[p->y][p->x],
				&map->map[p->y + 1][p->x]);
			p->y += 1;
		}
	}
	if (keycode == ARROW_UP)
	{
		if (ft_inspect_movements(so_long, so_long->map,
				(t_point){p->x, p->y - 1}) == 0)
		{
			ft_swap_extra(&map->map[p->y][p->x],
				&map->map[p->y - 1][p->x]);
			p->y -= 1;
		}
	}
	//ft_print_astronaut(so_long, map,);
}
