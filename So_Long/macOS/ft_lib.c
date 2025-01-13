/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • First Lib.                                                             */
/* ************************************************************************** */
#include "ft_so_long.h"

// ---------------------------PROTOTYPE---------------------------
void		*ft_calloc(size_t count, size_t size);
int			ft_is_separator(char c, const char *sep);
// ---------------------------------------------------------------

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		tot;
	void		*ptr;

	i = 0;
	tot = count * size;
	ptr = malloc(tot);
	if (!ptr)
		return (NULL);
	while (i < tot)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_is_separator(char c, const char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}
