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
/*   • Lance un jeu 2D.                                                       */
/*   • ./a.out [ file ]                                                       */
/*      -> file   [ .ber ]                                                    */
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
	t_img		*img;
	t_map		*map;
	t_point		*p;
}	t_so_long;

typedef struct s_img
{
	void		*space;
	void		*walls;
	void		*stars;
	void		*ship;
	void		*astronaut;
}	t_img;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			px;
	int			py;
	int			max_stars;
	int			counter;
}	t_map;

// pour flood_fill.
typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

//	---------- MY CODE ----------

// ft_so_long.c

int			ft_close_window(t_so_long *so_long);
void		ft_error(t_so_long *so_long, int error);
void		ft_init(t_so_long **so_long);
void		ft_free_so_long(t_so_long *so_long);

// ft_parse_map.c

void		ft_parse_map(t_so_long *so_long, char **argv);
int			ft_parse_map_next(t_map *map, int fd, char *line);
void		ft_check(t_so_long *so_long, t_map *map);

// ft_check.c

void		ft_check_2(t_so_long *so_long, t_map *map);
void		ft_check_3(t_so_long *so_long, int exit, int perso);
void		ft_check_4(t_so_long *so_long, t_map *map);
void		ft_check_5(t_so_long *so_long, t_map *map);
void		ft_check_6(t_so_long *so_long, t_map *map);

// ft_so_long_next.c

void		ft_so_long(t_so_long *so_long);
void		ft_print_background(t_so_long *so_long, t_map *map);
void		ft_print_astronaut(t_so_long *so_long, t_map *map, int x, int y);
void		ft_inspect_movements(t_so_long *so_long, t_map *map,
				t_point cur, t_point next);
void		ft_print_step(t_so_long *so_long);

// ft_image.c

void		ft_image_space(t_so_long *so_long);
void		ft_image_walls(t_so_long *so_long);
void		ft_image_stars(t_so_long *so_long);
void		ft_image_ship(t_so_long *so_long);
void		ft_image_astronaut(t_so_long *so_long);

// ft_macros.c

int			ft_key_hook(int keycode, t_so_long *so_long);
void		ft_key_movements_left(int keycode, t_so_long *so_long, t_point *p);
void		ft_key_movements_right(int keycode, t_so_long *so_long, t_point *p);
void		ft_key_movements_down(int keycode, t_so_long *so_long, t_point *p);
void		ft_key_movements_up(int keycode, t_so_long *so_long, t_point *p);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t old, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strchr(const char *s, int c, char flg);

// ft_lib_2.c

void		flood_fill(char **tab, t_point size, t_point cur,
				const char *to_fill);
void		fill(char **tab, t_point size, t_point cur, const char *to_fill);
void		ft_free_strs(t_map *map, void **strs, char flg);
int			ft_is_separator(int c, const char *sep);
int			ft_strcmp(const char *s1, const char *s2);

// ft_lib_3.c

char		*ft_itoa(int n);
void		ft_itoa_next(int n, char *res, int len);
char		**ft_strsdup(const char **src);
void		ft_putnbr(int nbr);

// get_next_line.c

char		*get_next_line(int fd);
int			ft_read_buffer(t_buf *buf, int fd);
char		*ft_strdup(const char *s1);

#endif
