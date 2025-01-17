/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

// ---------------------PROTOTYPE-----------------------
int			ft_close_window(t_so_long *so_long);
void		ft_error(t_so_long *so_long, int error);
void		ft_init(t_so_long **so_long);
void		ft_free_so_long(t_so_long *so_long);
// -----------------------------------------------------

int	main(int argc, char **argv)
{
	t_so_long		*so_long;

	so_long = NULL;
	if (argc == 2)
	{
		ft_init(&so_long);
		ft_parse_map(so_long, argv);
		so_long->mlx = mlx_init();
		so_long->win = mlx_new_window(so_long->mlx,
				so_long->map->width * SPT,
				so_long->map->height * SPT,
				"Just'So_Long");
		ft_so_long(so_long);
		mlx_hook(so_long->win, 2, 0, ft_key_hook, so_long);
		mlx_hook(so_long->win, 17, 0, ft_close_window, so_long);
		//mlx_loop_hook(fdf->mlx, ft_loop_hook, fdf);
		mlx_loop(so_long->mlx);
	}
	else
		return (ft_error(so_long, 255), 0);
	return (0);
}

// Ferme la fenêtre.
int	ft_close_window(t_so_long *so_long)
{
	if (so_long)
		ft_free_so_long(so_long);
	ft_printf(1, "Window closed\n");
	return (exit(0), 0);
}

// Fonction d'erreur.
void	ft_error(t_so_long *so_long, int error)
{
	if (so_long)
		ft_free_so_long(so_long);
	if (error == 255)
		ft_printf(2, "Error\nToo few/many arguments.\n");
	else if (error == 254)
		ft_printf(2, "Error\nFormat should be .ber.\n");
	else if (error == 253)
		ft_printf(2, "Error\nInvalid character.\n");
	else if (error == 252)
		ft_printf(2, "Error\nMisaligned lines.\n");
	else if (error == 251)
		ft_printf(2, "Error\nThis is an empty file.\n");
	else if (error == 250)
		ft_printf(2, "Error\nEmpty line.\n");
	else if (error == 249)
		ft_printf(2, "Error\nInvalid character.\n");
	else if (error == 248)
		ft_printf(2, "Error\nInvalid number of characters.\n");
	else if (error == 247)
		ft_printf(2, "Error\nThe map must be framed by walls.\n");
	else if (error == 246)
		ft_printf(2, "Error\nThe level is unsolvable.\n");
	else
		ft_printf(2, "Error\n%s\n", strerror(error));
	exit(error);
}

// 1. Alloue de la mémoire pour chaque structure.
// 2. Met toutes les variables à 0.
void	ft_init(t_so_long **so_long)
{
	*so_long = ft_calloc(1, sizeof(t_so_long));
	(*so_long)->img = ft_calloc(1, sizeof(t_img));
	(*so_long)->map = ft_calloc(1, sizeof(t_map));
	(*so_long)->p = ft_calloc(1, sizeof(t_map));
}
