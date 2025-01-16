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
/*   • Gestion des touches du clavier.                                MACOS   */
/* ************************************************************************** */
#ifndef FT_MACROS_H
# define FT_MACROS_H

// Taille de la map de jeu.
# define WIDTH			800
# define HEIGHT			700

//	---------- Macros for buttons ----------

// For EXIT and RESET.

# define MAIN_PAD_ESC		53
# define KEY_R			15

// For MOVING.

# define ARROW_LEFT		123
# define ARROW_RIGHT		124
# define ARROW_DOWN		125
# define ARROW_UP		126

// For the ZOOM.

# define NUM_PAD_PLUS		69
# define MAIN_PAD_PLUS		24

# define NUM_PAD_MINUS		78
# define MAIN_PAD_MINUS		27

// For ROTATION.

// alpha
# define NUM_PAD_1		83
# define NUM_PAD_4		86
# define MAIN_PAD_1		18
# define MAIN_PAD_2		19

// beta
# define NUM_PAD_2		84
# define NUM_PAD_5		87
# define MAIN_PAD_3		20
# define MAIN_PAD_4		21

// gamma
# define NUM_PAD_3		85
# define NUM_PAD_6		88
# define MAIN_PAD_5		23
# define MAIN_PAD_6		22

// For PROJECTION et POUDREUSE

# define KEY_I			34
# define KEY_P			35

// For HEIGHT.

# define NUM_PAD_8		91
# define NUM_PAD_9		92
# define MAIN_PAD_8		28
# define MAIN_PAD_9		25

// For SPLIT.

# define SEP			"\n"

#endif
