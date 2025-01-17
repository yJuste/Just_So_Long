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
// -----------------------------------------------------

// Fonction principale qui appelle les différentes touches pressées.
int	ft_key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == MAIN_PAD_ESC)
		ft_close_window(so_long);
	return (0);
}
