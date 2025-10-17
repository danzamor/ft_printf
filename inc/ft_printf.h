/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danz <danz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:30:42 by danzamor          #+#    #+#             */
/*   Updated: 2025/10/10 00:10:15 by danz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_str_bn(char *str);
int	print_decimal(int nbr);
int	print_uns_bn(unsigned int nb);
int	print_hex_lwr(unsigned int nb);
int	print_hex_upr(unsigned int nb);
int	print_ptr_bn(unsigned long long start);
int	ft_printf(const char *str, ...);

#endif