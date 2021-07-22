/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:34:34 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/16 19:32:21 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		ft_putint(nb + '0', fd);
	else if (nb == -2147483648)
	{
		ft_putint('-', fd);
		ft_putint('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (nb == 2147483647)
	{
		ft_putint('2', fd);
		ft_putnbr_fd(147483647, fd);
	}
	else if (nb < 0)
	{
		ft_putint('-', fd);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		ft_putint((nb % 10) + '0', fd);
	}
}
