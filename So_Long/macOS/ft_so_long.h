/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

/*
 * NOTE:
 * - La minilibx sur MacOS n'a pas été entièrement développé et c'est pour cette
 *	raison qu'il y a 1 leak de 32 bytes non atteignable dû au comportement
 *	de la lib. La raison est que mlx_destroy_display() n'a pas été ajouté
 *	pour la version mac.
 */

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// strerror, errno
# include <string.h>
# include <errno.h>

// open
# include <fcntl.h>

# include <math.h>

// minilibX
# include "minilibx_macos/mlx.h"

// My libraries

# include "Get_Next_Line/get_next_line.h"
# include "Printf_fd/ft_printf.h"

// Macros des fct
# include "ft_macros.h"

// Structures

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
}	t_so_long;

//	---------- MY CODE ----------

// ft_so_long.c

void		ft_init(t_so_long **so_long);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);
int			ft_is_separator(char c, const char *sep);

// ft_split.c

char		**ft_split(const char *s);
size_t		ft_count_words(const char *s);
char		**ft_split_next(char **out, const char *s);
char		**ft_split_error(char **out, size_t k);
char		*ft_strncpy(char *dest, const char *src, size_t n);

// get_next_line.c

char		*get_next_line(int fd);
int			ft_read_buffer(t_buf *buf, int fd);
char		*ft_strdup(const char *s1);

#endif
