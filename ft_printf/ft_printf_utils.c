/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybulacak <ybulacak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:42:09 by ybulacak          #+#    #+#             */
/*   Updated: 2022/09/20 21:42:13 by ybulacak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	c;

	c = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[c])
	{
		write(1, &str[c], 1);
		c++;
	}
	return (c);
}

int	ft_print_number(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
	{
		c += ft_print_string("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		c += ft_print_char('-');
		n = -n;
	}
	if (n >= 0 && n <= 9)
		c += ft_print_char(n + '0');
	if (n > 9)
	{
		c += ft_print_number(n / 10);
		c += ft_print_number(n % 10);
	}
	return (c);
}

int	ft_print_unumber(unsigned int n)
{
	int	c;

	c = 0;
	if (n <= 9)
		c += ft_print_char(n + '0');
	else
	{
		c += ft_print_unumber(n / 10);
		c += ft_print_unumber(n % 10);
	}
	return (c);
}

int	ft_hex(unsigned long p, char *base, int check, int base_len)
{
	int	c;

	c = 0;
	if (check == 1)
		c += write(1, "0x", 2);
	if (p / base_len != 0)
		c += ft_hex(p / base_len, base, 0, base_len);
	c += write(1, &base[p % base_len], 1);
	return (c);
}
