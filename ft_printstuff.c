/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:23:08 by efittant          #+#    #+#             */
/*   Updated: 2024/10/01 15:33:19 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
			len++;
		}
		if (n >= 10)
			len += ft_printnbr(n / 10);
		ft_printchar(n % 10 + 48);
		len++;
	}
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_printnbr(n / 10);
	ft_printchar(n % 10 + 48);
	len++;
	return (len);
}

/*#include <stdio.h>

int main(void)
{
    void *s;
    //ft_printchar('a');
    printf("\nchar len:%d\n", ft_printchar('a'));
    printf("\nog: %i", printf("a"));
    printf("\n");
    //ft_printnbr(165415);
    printf("\nnbr len:%d\n", ft_printnbr(165415));
    printf("\nog: %i\n", printf("165415"));
    printf("\n");

    printf("str len:%d\n", ft_printstr("hey this is a string"));
    printf("\nog strlen:%d", printf("Hey this is a string"));
    printf("\n");

    printf("\nunnsigned len:%d\n", ft_printunsigned(165415));
    printf("\nog strlen: %d", printf("165415"));
    printf("\n");

    printf("\nlhexa len:%d\n", ft_printlhexa(123));
    printf("\nog strlen: %d", printf("7b"));
    printf("\n");
    
    printf("\nUhexa len:%d\n", ft_printuhexa(123));
    printf("\nog strlen: %d", printf("7B"));
    printf("\n");

    printf("\nUhexa len:%d\n", ft_printvoid(s));
    printf("%p", s);
    printf("\n");
    //ft_printvoid()
}*/
