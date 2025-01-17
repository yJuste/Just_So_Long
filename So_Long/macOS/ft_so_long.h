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

typedef struct s_so_long	t_so_long;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_point		t_point;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	void		*textures[5];
	t_img		*img;
	t_map		*map;
	t_point		*p;
}	t_so_long;

typedef struct s_img
{
	void		*ptr;
}	t_img;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}	t_map;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

//	---------- MY CODE ----------

// ft_so_long.c

void		ft_error(t_so_long *so_long, int error);
void		ft_init(t_so_long **so_long);
void		ft_free_so_long(t_so_long *so_long);

// ft_parse_map.c

void		ft_parse_map(t_so_long *so_long, char **argv);
int			ft_parse_map_next(t_so_long *so_long, t_map *map,
				int fd, char *line);
void		ft_check(t_so_long *so_long, t_map *map);

// ft_check.c

void		ft_check_2(t_so_long *so_long, t_map *map);
void		ft_check_3(t_so_long *so_long, int exit, int perso, int collec);
void		ft_check_4(t_so_long *so_long, t_map *map);
void		ft_check_5(t_so_long *so_long, t_map *map);
void		ft_check_6(t_so_long *so_long, t_map *map);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t old, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c, char flg);
int			ft_strcmp(const char *s1, const char *s2);

// ft_lib_2.c

void		flood_fill(char **tab, t_point size, t_point begin,
				const char *to_fill);
void		fill(char **tab, t_point size, t_point cur, const char *to_fill);
void		ft_free_strs(t_map *map, void **strs, char flg);
char		**ft_strsdup(const char **src);
int			ft_is_separator(int c, const char *sep);

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
