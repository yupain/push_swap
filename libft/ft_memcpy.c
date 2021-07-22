/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:33:14 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/02 20:32:37 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;
	size_t	i;

	i = 0;
	dest1 = dest;
	src1 = (char *)src;
	if (dest1 == NULL && src1 == NULL)
		return (dest);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
