/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:24:57 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/04/17 18:31:39 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*c;
	size_t	lensrc;
	size_t	i;

	i = 0;
	lensrc = ft_strlen(src);
	c = (char *)malloc(sizeof(*c) * (lensrc + 1));
	if (!c)
		return (NULL);
	while (src[i] != '\0')
	{
		c[i] = src[i];
		i++;
		if (src[i] == '\0')
		{
			c[i] = '\0';
		}
	}
	return (c);
}
