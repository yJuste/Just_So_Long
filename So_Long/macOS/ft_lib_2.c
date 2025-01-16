/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Second Lib.                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

// -------------------------------PROTOTYPE-------------------------------
void		flood_fill(char **tab, t_point size, t_point begin);
void		fill(char **tab, t_point size, t_point cur, char to_fill);
void		ft_free_strs(t_map *map, void **strs, char flg);
int			ft_is_separator(int c, const char *sep);
// -----------------------------------------------------------------------

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	ft_free_strs(t_map *map, void **strs, char flg)
{
	size_t		i;

	i = 0;
	if (!strs)
		return ;
	if (flg == 'c')
	{
		while (strs[i])
		{
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
	}
	else if (flg == 'i')
	{
		while (i < map->height)
		{
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
	}
	free(strs);
	strs = NULL;
}

int	ft_is_separator(int c, const char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}
