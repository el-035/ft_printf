/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:22:52 by efittant          #+#    #+#             */
/*   Updated: 2024/09/25 17:22:58 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversions(va_list arg, char c, int len)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' \
		&& c != 'u' && c != 'x' && c != 'X' && c != '%')
		return (len += ft_printchar(37) + ft_printchar((int)c));
	if (c == 'c')
		len += ft_printchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_printstr(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_printvoid(va_arg(arg, void *));
	else if (c == 'd')
		len += ft_printnbr(va_arg(arg, int));
	else if (c == 'i')
		len += ft_printnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_printunsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		len += ft_printlhexa(va_arg(arg, unsigned int));
	else if (c == 'X')
		len += ft_printuhexa(va_arg(arg, unsigned int));
	else if (c == '%')
		len += ft_printchar(37);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	if (str == NULL)
		return (-1);
	va_start(arg, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i] && ++len)
			write(1, &str[i++], 1);
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len = ft_conversions(arg, str[++i], len);
			i++;
		}
		else if (str[i - 1] == ' ' && str[i] == '%' && str[i + 1] == '\0')
			return (va_end(arg), -1);
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (va_end(arg), len += ft_printchar(37));
	}
	va_end(arg);
	return (len);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    //void *ptr;
    //char *str = "";
    //ptr = malloc(1);
    //ft_printf("char: %c, str: %s, dec: %d, int: %i, void: %p, unsigned: \\
	%u; Uhexa: %X, Lhexa: %x, percent: %%\n", 'c', "string", 1, 1, ptr, 1, \\
	150, 150);
    //ft_printf("len:%d\n", ft_printf("char: %c, str: %s, dec: %d, int: %i, \\
	void: %p, unsigned: %u; Uhexa: %X, Lhexa: %x, percent: %%\n", 'c', str, \\
	1, 1, ptr, 1, 150, 150));
    //printf("len:%d\n", printf("char: %c, str: %s, dec: %d, int: %i, void: \\
	%p, unsigned: %u; Uhexa: %X, Lhexa: %x, percent: %%\n", 'c', str, 1, 1, \\
	ptr, 1, 150, 150));
	//ft_printf("return: %i\n", ft_printf("%s", str));
	//printf("return: %i\n", printf("%s", str));
	
	//ft_printf("%i\n", ft_printf("hello %s % jhe\n", "str"));
	//printf("%i\n", printf("hello %s % jhe\n", "str" ));

	//ft_printf("%i\n", ft_printf("Im not supported %y\n", "str"));
	//printf("%i\n", printf("Im not supported %y\n", "str" ));

    //ft_printf("len:%d\n", ft_printf("%%%%%%%%%%%%"));
    //printf("len:%d\n", printf("%%%%%%%%%%%%"));

	//ft_printf("len:%d\n", ft_printf("%p\n", 18446744073709551615ULL));
	//printf("len:%d\n", printf("%p\n", 18446744073709551615ULL));

	//ft_printf("len:%d\n", ft_printf(" % c\n", '0'));
	//printf("len:%d\n", printf(" % c\n", '0'));

	//ft_printf("len:%d\n", ft_printf(NULL, 42));
	//printf("len:%d\n", printf(NULL, 42));

	ft_printf("len:%d\n", ft_printf(" %w%", "hello"));
	printf("len:%d\n", printf(" %w%", "hello"));

	ft_printf("len:%d\n", ft_printf("'   %"));
	printf("len:%d\n", printf("'   %"));

}*/
