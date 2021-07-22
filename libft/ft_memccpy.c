/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:00:05 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/04 20:48:29 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = dst;
	src1 = (unsigned char *)src;
	x = 0;
	while (x < n)
	{
		dst1[x] = src1[x];
		if (dst1[x] == (unsigned char)c)
		{
			dst1[x] = c;
			return (&dst[x + 1]);
		}
		x++;
	}
	return (NULL);
}
