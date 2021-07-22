/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:42:36 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/04/17 19:11:06 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_chrcnt(char const *s, char c)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			len++;
			break ;
		}
		if (*s != c)
			len++;
		s++;
	}
	return (len);
}

static	int	ft_wcnt(char const *s, char c)
{
	int	wc;

	wc = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if ((*s != c) && (*(s + 1) == c || *(s + 1) == '\0'))
			wc++;
		s++;
	}
	return (wc);
}

static	char	**ft_free(char **kek, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(kek[j]);
		j++;
	}
	free(kek);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**kek;
	size_t	len;
	size_t	i;

	i = 0;
	kek = (char **) malloc(sizeof(char *) * (ft_wcnt(s, c) + 1));
	if (!s || !kek)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = ft_chrcnt(s, c);
			kek[i] = ft_substr(s, 0, len);
			if (!kek[i])
				return (ft_free(kek, i));
			s += (len - 1);
			i++;
		}
		s++;
	}
	kek[i] = NULL;
	return (kek);
}
