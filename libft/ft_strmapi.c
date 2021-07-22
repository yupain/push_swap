/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:11:09 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/04/17 18:34:13 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	char	*fs;
	size_t	i;

	i = 0;
	c = (char *)s;
	if (!s)
		return (NULL);
	fs = (char *)malloc(sizeof(char) * (ft_strlen(c) + 1));
	if (!fs)
		return (NULL);
	while (c[i])
	{
		fs[i] = f(i, c[i]);
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
