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

// ---------------------PROTOTYPE-----------------------
void		ft_parse_map(t_so_long *so_long, char **argv);
int			ft_parse_map_next(t_so_long *so_long, t_map *map,
				int fd, char *line);
// -----------------------------------------------------

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
	so_long->map->height
		= ft_parse_map_next(so_long, so_long->map, fd, line);
	close(fd);
}

/*

		while (out[i])
		{
			if (ft_is_separator(out[0][i], "01CEP"))
				return (ft_error(so_long, 2));
		}

*/

void	ft_print_strs(char **strs)
{
	size_t		i;

	i = 0;
	while (strs[i])
	{
		ft_printf(1, "%s\n", strs[i]);
		i++;
	}
	return ;
}

int	ft_parse_map_next(t_so_long *so_long, t_map *map, int fd, char *line)
{
	size_t		j;

	j = 0;
	while (line)
	{
		if (!line)
			break ;
		j++;
		map->map = ft_realloc(map->map, sizeof(char *) * (j - 1),
				sizeof(char *) * j);
		map->width = ft_strlen((const char *)line) - 1;
		map->map[j - 1] = ft_calloc(map->width + 1, sizeof(char));
		ft_strncpy(map->map[j - 1], line, map->width);
		ft_printf(1, "%s\n", map->map[j - 1]);
		free(line);
		line = get_next_line(fd);
	}
	// ft_print_strs(map->map);
	return (j);
}

void	ft_parse_map_next_next(t_map *map, char **out, size_t j)
{
	size_t		i;
	char		*strchr;

	i = 0;
	strchr = NULL;
	return ;
}
