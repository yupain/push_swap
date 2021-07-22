/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:34:28 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/12 21:55:27 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	x;
	char	*dest1;
	char	*src1;

	dest1 = dest;
	src1 = (char *)src;
	x = 0;
	if ((dest1 == NULL && src1 == NULL) || len == 0)
		return (dest);
	if (src1 >= dest1)
		return (ft_memcpy(dest, src, len));
	else
	{
		len--;
		while (x <= len)
		{
			dest1[len - x] = src1[len - x];
			x++;
		}
	}
	dest1[ft_strlen(dest1)] = '\0';
	return (dest);
}
