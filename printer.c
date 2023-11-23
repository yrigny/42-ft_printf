/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:45:55 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/23 14:38:23 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	fprinter(char *flags, char type, va_list *p_args)
{
	char	*farg;

	if (type == 'c')
		farg = parser_c(flags, p_args);
	if (type == 's')
		farg = parser_s(flags, p_args);
	if (type == 'p')
		farg = parser_p(flags, p_args);
	if (type == 'd')
		farg = parser_d(flags, p_args);
	if (type == 'i')
		farg = parser_i(flags, p_args);
	if (type == 'u')
		farg = parser_u(flags, p_args);
	if (type == 'x')
		farg = parser_xlow(flags, p_args);
	if (type == 'X')
		farg = parser_xupp(flags, p_args);
	if (type == '%' && flags == NULL)
		farg = "%";
	return (ft_putstr(farg));
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	if (n = 0)
		return (NULL);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	printer(const char *fstr, va_list *p_args)
{
	int	n;
	int	i;
	int	start;
	char	*flags;

	n = 0;
	i = 0;
	while (fstr[i])
	{
		while (fstr[i] && fstr[i] != '%')
		{
			n += write(1, fstr[i], 1);
			i++;
		}
		if (fstr[i] == '%')
		{
			start = i + 1;
			while (!ft_strchr("cspdiuxX%", fstr[i + 1]))
				i++;
			flags = ft_strncpy(flags, &fstr[start], i + 1 - start);
			n += fprinter(flags, fstr[i + 1], p_args);
			i += 1;
		}
	}
	return (n);
}
