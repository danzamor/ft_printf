/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danz <danz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:33:19 by danz              #+#    #+#             */
/*   Updated: 2025/10/09 23:58:19 by danz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_lwr(unsigned int nb)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (nb < 16)
	{
		write(1, &hex[nb % 16], 1);
		return (1);
	}
	else
	{
		count += print_hex_lwr(nb / 16);
		count += print_hex_lwr(nb % 16);
	}
	return (count);
}

int	print_hex_upr(unsigned int nb)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (nb < 16)
	{
		write(1, &hex[nb % 16], 1);
		return (1);
	}
	else
	{
		count += print_hex_upr(nb / 16);
		count += print_hex_upr(nb % 16);
	}
	return (count);
}

int	print_ptr_bn(unsigned long long ptr)
{
	unsigned long long	addr;
	int					i;
	char				hex[16];
	char				*base;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long long) ptr;
	base = "0123456789abcdef";
	i = 15;
	write(1, "0x", 2);
	while (i >= 0)
	{
		hex[i] = base[addr % 16];
		addr /= 16;
		i--;
	}
	while (hex[i + 1] == '0' && i < 15)
		i++;
	write(1, &hex[i + 1], 16 - i - 1);
	return (18 - i - 1);
}

int	print_str_bn(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
