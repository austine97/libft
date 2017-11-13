/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:18:11 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/11 12:42:55 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbw(char *s, char c)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			sym = 1;
		}
		while (s[i] == c && s[i])
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count + 2);
}

static int	nbc(char *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count + 1);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((res = malloc(sizeof(char *) * nbw((char *)s, c))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * nbc((char*)s, i, c))) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
