/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:23 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/04/17 18:23:06 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char *)malloc(size * (count));
	if (!c)
		return (NULL);
	while (i < count * size)
	{
		c[i] = 0;
		i++;
	}
	return ((void *)c);
}
