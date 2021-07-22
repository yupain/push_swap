/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:48:12 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/12 19:38:36 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		k;
	int		last;
	char	*x;

	k = 0;
	x = (char *)s;
	last = ft_strlen(x);
	if (c == '\0')
		return (&x[last]);
	while (x[k] != '\0')
	{
		if (x[k] == (char)c)
			return (&x[k]);
		k++;
	}
	return (NULL);
}
