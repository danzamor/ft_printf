/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danz <danz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:26:32 by danz              #+#    #+#             */
/*   Updated: 2025/10/09 23:36:40 by danz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(int nbr)
{
	char	pr;
	long	nb;
	int		count;

	nb = (long)nbr;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		count++;
	}
	if (nb < 10)
	{
		pr = nb + 48;
		write(1, &pr, 1);
		return (1 + count);
	}
	else
	{
		count += print_decimal(nb / 10);
		count += print_decimal(nb % 10);
	}
	return (count);
}

int	print_uns_bn(unsigned int nb)
{
	char	pr;
	int		count;

	count = 0;
	if (nb < 10)
	{
		pr = nb + 48;
		write(1, &pr, 1);
		return (1);
	}
	else
	{
		count += print_uns_bn(nb / 10);
		count += print_uns_bn(nb % 10);
	}
	return (count);
}
