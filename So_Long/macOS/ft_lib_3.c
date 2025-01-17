/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Third Lib.                                                             */
/* ************************************************************************** */
#include "ft_so_long.h"

// ----------------------PROTOTYPE----------------------
char		*ft_itoa(int n);
void		ft_itoa_next(int n, char *res, int len);
char		**ft_strsdup(const char **src);
void		ft_putnbr(int nbr);
// -----------------------------------------------------

char	*ft_itoa(int n)
{
	int		nbr;
	int		len;
	char	*res;

	nbr = n;
	len = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_itoa_next(n, res, len);
	return (res);
}

void	ft_itoa_next(int n, char *res, int len)
{
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return ;
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return ;
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

void	ft_putnbr(int nbr)
{
	char		c;

	c = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}
