/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:50:43 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/13 18:59:29 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ss1;

	i = -1;
	ss1 = (char *)s;
	while (ss1[++i] &&  i < n)
	{
		if (ss1[i] == c)
			return (&ss1[i]);
	}
	if (!ss1[i] && c == '\0')
		return (&ss1[i]);
	else
		return (NULL);
}
