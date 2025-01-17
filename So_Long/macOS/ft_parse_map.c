/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

// -----------------------------PROTOTYPE--------------------------------
void		ft_parse_map(t_so_long *so_long, char **argv);
int			ft_parse_map_next(t_so_long *so_long, t_map *map,
				int fd, char *line);
void		ft_check(t_so_long *so_long, t_map *map);
// ----------------------------------------------------------------------

// Fonction qui gère l'ouverture de fichier.
void	ft_parse_map(t_so_long *so_long, char **argv)
{
	int			fd;
	char		*line;
	char		*file;

	file = argv[1];
	file = ft_strchr(file, '.', 'r');
	if (!file)
		return (ft_error(so_long, ENOEXEC));
	if (ft_strcmp(file, ".ber") != 0)
		return (ft_error(so_long, 254));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			return (ft_error(so_long, EACCES));
		else
			return (ft_error(so_long, EBADF));
	}
	line = get_next_line(fd);
	if (!line)
		return (ft_error(so_long, 251));
	so_long->map->height = ft_parse_map_next(so_long, so_long->map, fd, line);
	close(fd);
	if (so_long->map->map)
		ft_check(so_long, so_long->map);
}

// Fonction qui transforme la map en tableau de chaines.
int	ft_parse_map_next(t_so_long *so_long, t_map *map, int fd, char *line)
{
	size_t		j;

	j = 0;
	while (line)
	{
		j++;
		map->map = ft_realloc(map->map, sizeof(char *) * (j - 1),
				sizeof(char *) * j);
		map->width = ft_strlen((const char *)line);
		if (line[map->width - 1] == '\n')
			map->width -= 1;
		map->map[j - 1] = ft_calloc(map->width + 1, sizeof(char));
		ft_strncpy(map->map[j - 1], line, map->width);
		ft_printf(1, "%s\n", map->map[j - 1]);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf(1, "\n");
	j++;
	map->map = ft_realloc(map->map, sizeof(char *) * (j - 1),
			sizeof(char *) * j);
	map->map[j - 1] = NULL;
	j -= 1;
	return (j);
}

// Fonction principale qui appelle les fonctions de parsing.
void	ft_check(t_so_long *so_long, t_map *map)
{
	ft_check_2(so_long, map);
	ft_check_3(so_long, 0, 0, 0);
	ft_check_4(so_long, map);
	ft_check_5(so_long, map);
	ft_check_6(so_long, map);
}

// Fonction qui free.
void	ft_free_so_long(t_so_long *so_long)
{
	if (so_long->map->map)
		ft_free_strs(so_long->map, (void *)so_long->map->map, 'c');
	if (so_long->img->ptr)
		mlx_destroy_image(so_long->mlx, so_long->img->ptr);
	if (so_long->win)
		mlx_destroy_window(so_long->mlx, so_long->win);
	free(so_long->img);
	free(so_long->map);
	free(so_long->p);
	free(so_long);
}
