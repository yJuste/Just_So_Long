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
void		*ft_realloc(void *ptr, size_t old, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strchr(const char *s, int c, char flg);
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

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void		*nptr;

	if (!ptr)
		return (ft_calloc(1, size));
	if (!size)
		return (free(ptr), NULL);
	nptr = ft_calloc(1, size);
	if (!nptr)
		return (NULL);
	if (old < size)
		ft_memcpy(nptr, ptr, old);
	else
		ft_memcpy(nptr, ptr, size);
	free(ptr);
	return (nptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c, char flg)
{
	size_t		i;

	i = 0;
	if (flg == 'r')
	{
		i = ft_strlen(s);
		while (s[i] != (char)c && i > 0)
			i--;
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	else
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				return ((char *)(s + i));
			i++;
		}
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
