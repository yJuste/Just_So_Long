/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Gestion des touches du clavier.                                LINUX   */
/* ************************************************************************** */
#ifndef FT_MACROS_H
# define FT_MACROS_H

// Taille de la map de jeu.
# define WIDTH			800
# define HEIGHT			700

//	---------- Macros for buttons ----------

// For EXIT and RESET.

# define MAIN_PAD_ESC		65307
# define KEY_R			114

// For MOVING.

# define ARROW_LEFT		65361
# define ARROW_RIGHT		65363
# define ARROW_DOWN		65364
# define ARROW_UP		65362

// For the ZOOM.

# define NUM_PAD_PLUS		65451
# define MAIN_PAD_PLUS		61

# define NUM_PAD_MINUS		65453
# define MAIN_PAD_MINUS		45

// For ROTATION.

// alpha
# define NUM_PAD_1		65436
# define NUM_PAD_4		65430
# define MAIN_PAD_1		49
# define MAIN_PAD_2		50

// beta
# define NUM_PAD_2		65433
# define NUM_PAD_5		65437
# define MAIN_PAD_3		51
# define MAIN_PAD_4		52

// gamma
# define NUM_PAD_3		65435
# define NUM_PAD_6		65432
# define MAIN_PAD_5		53
# define MAIN_PAD_6		54

// For PROJECTION et POUDREUSE.

# define KEY_I			105
# define KEY_P			112

// For HEIGHT.

# define NUM_PAD_8		65431
# define NUM_PAD_9		65434
# define MAIN_PAD_8		56
# define MAIN_PAD_9		57

// For SPLIT.

# define SEP			" \n\t"

#endif
