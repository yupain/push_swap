/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:24:19 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/04/17 18:26:14 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static	int	ft_intlen(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static	char	char_hex(unsigned long int n)
{
	if ((n % 16) >= 0 && (n % 16) <= 9)
		return (n % 16 + '0');
	else if (n % 16 == 10)
		return ('a');
	else if (n % 16 == 11)
		return ('b');
	else if (n % 16 == 12)
		return ('c');
	else if (n % 16 == 13)
		return ('d');
	else if (n % 16 == 14)
		return ('e');
	else
		return ('f');
}

char	*ft_itoa_hex(unsigned long int n)
{
	char		*c;
	int			len;

	len = ft_intlen(n);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	len--;
	if (n == 0)
	{
		c[0] = '0';
		return (c);
	}
	while (len >= 0 && n != 0)
	{
		c[len] = char_hex(n);
		n /= 16;
		len--;
	}
	return (c);
}
