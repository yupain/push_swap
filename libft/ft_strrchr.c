/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:20:33 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/29 03:03:53 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*kek;

	kek = (char *)s;
	if (!s)
		return (NULL);
	i = ft_strlen(kek);
	while (i >= 0)
	{
		if (kek[i] == (char)c)
			return (&kek[i]);
		i--;
	}
	return (NULL);
}
