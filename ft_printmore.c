/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:34:16 by efittant          #+#    #+#             */
/*   Updated: 2024/10/01 15:34:18 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlhexa(unsigned int n)
{
	int		len;
	char	*hexa;

	hexa = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_printlhexa(n / 16);
	ft_printchar(hexa[n % 16]);
	len++;
	return (len);
}

int	ft_printuhexa(unsigned int n)
{
	int		len;
	char	*hexa;

	hexa = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_printuhexa(n / 16);
	ft_printchar(hexa[n % 16]);
	len++;
	return (len);
}

static int	ft_hexvoid(unsigned long long n)
{
	int		len;
	char	*hexa;

	hexa = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_hexvoid(n / 16);
	ft_printchar(hexa[n % 16]);
	len++;
	return (len);
}

int	ft_printvoid(void *s)
{
	int					len;
	unsigned long long	address;

	len = 0;
	address = (unsigned long long) s;
	if (s == NULL)
	{
		len += ft_printstr("(nil)");
		return (len);
	}
	len += ft_printstr("0x");
	len += (unsigned long long)ft_hexvoid(address);
	return (len);
}
