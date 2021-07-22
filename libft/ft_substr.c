/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:14:55 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/04/17 19:10:48 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	if (len != 0)
	{
		while (s[i] != '\0')
		{
			if (i >= start && j < len)
			{
				substr[j] = s[i];
				j++;
			}
			i++;
		}
	}
	substr[j] = '\0';
	return (substr);
}
