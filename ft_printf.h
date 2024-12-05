/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:22:41 by efittant          #+#    #+#             */
/*   Updated: 2024/10/01 16:18:56 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printnbr(int n);
int	ft_printunsigned(unsigned int n);
int	ft_printlhexa(unsigned int n);
int	ft_printuhexa(unsigned int n);
int	ft_printvoid(void *s);

#endif
