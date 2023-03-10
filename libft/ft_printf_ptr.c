/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:21:09 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:21:11 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_ptr(unsigned long nb)
{
	int		len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
		else
			ft_putchar(nb - 10 + 97);
	}
}

int	ft_printptr(unsigned long nb)
{
	int		len;

	len = 2;
	write(1, "0x", 2);
	if (nb == 0)
		len += write(1, "0", 1);
	else
		ft_putptr(nb);
		len += ft_len_ptr(nb);
	return (len);
}
