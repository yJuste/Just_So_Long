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

// ----------------------------PROTOTYPE--------------------------
void		flood_fill(char **tab, t_point size, t_point cur,
				const char *to_fill);
void		ft_free_strs(t_map *map, void **strs, char flg);
char		**ft_strsdup(const char **src);
int			ft_is_separator(int c, const char *sep);
int			ft_strcmp(const char *s1, const char *s2);
// ---------------------------------------------------------------

// Fonction qui remplit une zone en fonction de caractères donnés.
// size est la taille de la map en x,y (comme un `strlen`);
// begin est l'`index` du début de propagation;
void	flood_fill(char **tab, t_point size, t_point cur, const char *to_fill)
{
	if (cur.y < 0 || cur.y >= size.y
		|| cur.x < 0 || cur.x >= size.x
		|| !ft_is_separator(tab[cur.y][cur.x], to_fill))
		return ;
	tab[cur.y][cur.x] = 'F';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
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

char	**ft_strsdup(const char **src)
{
	size_t		i;
	size_t		j;
	char		**dest;

	j = 0;
	while (src[j])
		j++;
	dest = ft_calloc(j + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			j = 0;
			while (j < i)
				free(dest[j++]);
			return (free(dest), NULL);
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
