/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:25:42 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/13 19:52:44 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*c;
	char	*ss;
	size_t	len;

	ss = (char *)s1;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *ss) && *ss)
		ss++;
	len = ft_strlen(ss);
	while (ft_strrchr(set, ss[len]) && len > 0)
		len--;
	c = ft_substr(ss, 0, len + 1);
	return (c);
}
