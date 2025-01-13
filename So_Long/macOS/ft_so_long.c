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
void		ft_error(t_so_long *so_long, int error);
void		ft_init(t_so_long **so_long);
void		ft_free_so_long(t_so_long *so_long);
// -----------------------------------------------------

int	main(int argc, char **argv)
{
	t_so_long		*so_long;

	so_long = NULL;
	ft_init(&so_long);
	ft_free_so_long(so_long);
	return (0);
}

// Fonction d'erreur.
void	ft_error(t_so_long *so_long, int error)
{
	if (so_long)
		ft_free_so_long(so_long);
	ft_printf(2, "%s\n", strerror(error));
	exit(error);
}

// 1. Alloue de la mémoire pour chaque structure.
// 2. Met toutes les variables à 0.
void	ft_init(t_so_long **so_long)
{
	*so_long = ft_calloc(1, sizeof(t_so_long));
	(*so_long)->img = ft_calloc(1, sizeof(t_img));
}

// Fonction qui free.
void	ft_free_so_long(t_so_long *so_long)
{
	if (so_long->img->ptr)
		mlx_destroy_image(so_long->mlx, so_long->img->ptr);
	if (so_long->win)
		mlx_destroy_window(so_long->mlx, so_long->win);
	free(so_long->img);
	free(so_long);
}
