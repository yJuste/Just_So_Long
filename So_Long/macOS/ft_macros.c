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

// -----------------------------------PROTOTYPE---------------------------------
int			ft_key_hook(int keycode, t_so_long *so_long);
void		ft_key_movements_left(int keycode, t_so_long *so_long, t_point *p);
void		ft_key_movements_right(int keycode, t_so_long *so_long, t_point *p);
void		ft_key_movements_down(int keycode, t_so_long *so_long, t_point *p);
void		ft_key_movements_up(int keycode, t_so_long *so_long, t_point *p);
// -----------------------------------------------------------------------------

// Fonction principale qui appelle les différentes touches pressées.
int	ft_key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == ARROW_LEFT || keycode == KEY_A
		|| keycode == ARROW_RIGHT || keycode == KEY_D
		|| keycode == ARROW_DOWN || keycode == KEY_S
		|| keycode == ARROW_UP || keycode == KEY_W)
		ft_key_movements_left(keycode, so_long, so_long->p);
	else if (keycode == MAIN_PAD_ESC)
		ft_close_window(so_long);
	return (0);
}

// Fonction qui gère la touche directionnelle gauche.
void	ft_key_movements_left(int keycode, t_so_long *so_long, t_point *p)
{
	so_long->map->px = p->x;
	if (keycode == ARROW_LEFT || keycode == KEY_A)
	{
		ft_inspect_movements(so_long, so_long->map,
			(t_point){p->x, p->y},
			(t_point){p->x - 1, p->y});
	}
	ft_key_movements_right(keycode, so_long, p);
}

// Fonction qui gère la touche directionnelle droite.
void	ft_key_movements_right(int keycode, t_so_long *so_long, t_point *p)
{
	if (keycode == ARROW_RIGHT || keycode == KEY_D)
	{
		ft_inspect_movements(so_long, so_long->map,
			(t_point){p->x, p->y},
			(t_point){p->x + 1, p->y});
	}
	ft_key_movements_down(keycode, so_long, p);
}

// Fonction qui gère la touche directionnelle basse.
void	ft_key_movements_down(int keycode, t_so_long *so_long, t_point *p)
{
	so_long->map->py = p->y;
	if (keycode == ARROW_DOWN || keycode == KEY_S)
	{
		ft_inspect_movements(so_long, so_long->map,
			(t_point){p->x, p->y},
			(t_point){p->x, p->y + 1});
	}
	ft_key_movements_up(keycode, so_long, p);
}

// Fonction qui gère la touche directionnelle haute.
void	ft_key_movements_up(int keycode, t_so_long *so_long, t_point *p)
{
	if (keycode == ARROW_UP || keycode == KEY_W)
	{
		ft_inspect_movements(so_long, so_long->map,
			(t_point){p->x, p->y},
			(t_point){p->x, p->y - 1});
	}
	ft_print_astronaut(so_long, so_long->map,
		so_long->map->px, so_long->map->py);
}
