/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 00:07:41 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/13 18:42:18 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		dlen;

	d = dst;
	s = src;
	i = len;
	while (i-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	i = len - dlen;
	if (i == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
