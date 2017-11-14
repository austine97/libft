/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:30:15 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/13 19:58:37 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_nbprimebis(int *tab, int i, int j, int nb)
{
	int l;
	int k;

	i = 1;
	l = 0;
	if (nb <= 1)
		return (tab);
	while (i++ <= nb)
	{
		j = 1;
		k = 0;
		while (j * j < i)
		{
			if ((i % j) == 0)
				k++;
			j++;
		}
		if (k == 1)
		{
			tab[l] = i;
			l++;
		}
	}
	tab[l] = '\0';
	return (tab);
}

static void	ft_show(int *tab, int l, int nb)
{
	int i;

	i = 0;
	while (i < l)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("il y a ");
	ft_putnbr(l);
	ft_putstr(" nombres premier inferieur ou egal a ");
	ft_putnbr(nb);
}

int			*ft_nbprime(int nb)
{
	int	i;
	int	j;
	int	k;
	int	*tab;
	int	l;

	i = 0;
	l = 0;
	if (nb == 0 || nb == 1)
		return (0);
	while (++i <= nb)
	{
		j = 0;
		k = 0;
		while (++j < i)
			k += ((i % j) == 0) ? 1 : 0;
		if (k == 1)
			l++;
	}
	if ((tab = (int*)malloc(sizeof(int) * (l + 1))) == 0)
		return (NULL);
	tab = ft_nbprimebis(tab, i, j, nb);
	ft_show(tab, l, nb);
	return (tab);
}
