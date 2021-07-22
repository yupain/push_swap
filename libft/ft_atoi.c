/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:40:42 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/07 21:34:53 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	int	i;
	int	pn;
	int	b;

	i = 0;
	b = 0;
	pn = 1;
	while ((nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		&& nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			pn = (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		b = b * 10 + nptr[i] - '0';
		i++;
	}
	return (b * pn);
}
