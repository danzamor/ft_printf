/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danz <danz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:26:30 by danzamor          #+#    #+#             */
/*   Updated: 2025/10/09 23:34:36 by danz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char c, va_list vars)
{
	char	p;

	if (c == 'c')
	{
		p = va_arg(vars, int);
		write(1, &p, 1);
		return (1);
	}
	else if (c == 's')
		return (print_str_bn(va_arg(vars, char *)));
	else if (c == 'p')
		return (print_ptr_bn(va_arg(vars, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (print_decimal(va_arg(vars, int)));
	else if (c == 'u')
		return (print_uns_bn(va_arg(vars, unsigned)));
	else if (c == 'x')
		return (print_hex_lwr(va_arg(vars, unsigned)));
	else if (c == 'X')
		return (print_hex_upr(va_arg(vars, unsigned)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	vars;
	int		i;
	int		ret;

	if (!str)
		return (-1);
	va_start(vars, str);
	ret = 0;
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i = print_arg(*str, vars);
			if (i == -1)
				return (-1);
			ret += i;
		}
		else
			ret += write(1, str, 1);
		str++;
	}
	va_end(vars);
	return (ret);
}
