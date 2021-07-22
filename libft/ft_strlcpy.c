/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:31:55 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/06 00:07:31 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	k;
	char	*src1;

	i = 0;
	if (!src)
		return (0);
	src1 = (char *)src;
	k = ft_strlen((char *)src);
	if (len == 0)
		return (k);
	while (i < len - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (k);
}
