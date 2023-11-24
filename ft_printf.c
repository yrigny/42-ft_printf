/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:11:59 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/23 14:18:00 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parseflag(t_flags *p_flagset, const char *fstr)
{
	while (*fstr && ft_strchr("-+ #0", *fstr))
	{
		if (*fstr == '-')
			p_flagset->left = 1;
		if (*fstr == '+')
			p_flagset->plus = 1;
		if (*fstr == ' ')
			p_flagset->space = 1;
		if (*fstr == '#')
			p_flagset->hash = 1;
		if (*fstr == '0')
			p_flagset->zero = 1;
		fstr++;
	}
	if (*fstr && *fstr >= '1' && *fstr <= '9')
		p_flagset->width = ft_atoi(fstr);
	while (*fstr && *fstr >= '0' && *fstr <= '9')
		fstr++;
	if (*fstr == '.')
		p_flagset->precis = ft_atoi(fstr + 1);
	while (*fstr && !ft_strchr("cspdiuxX%", *fstr))
		fstr++;
	p_flagset->type = *(fstr);
}

void	iniflagset(t_flags *p_flagset)
{
	p_flagset->left = 0;
	p_flagset->plus = 0;
	p_flagset->space = 0;
	p_flagset->hash = 0;
	p_flagset->zero = 0;
	p_flagset->width = 0;
	p_flagset->precis = 0;
	p_flagset->type = 0;
}

void	fprinter(const char *fstr, va_list *p_args, int *p_n)
{
	t_flags	flagset;

	iniflagset(&flagset);
	parseflag(&flagset, fstr);
	if (flagset.type == 'c')
		fprinter_c(flagset, p_args, p_n);
	if (flagset.type == 's')
		fprinter_s(flagset, p_args, p_n);
	if (flagset.type == 'p')
		fprinter_p(flagset, p_args, p_n);
	if (flagset.type == 'd' || flagset.type == 'i')
		fprinter_d(flagset, p_args, p_n);
	if (flagset.type == 'u')
		fprinter_u(flagset, p_args, p_n);
	if (flagset.type == 'x' || flagset.type == 'X')
		fprinter_x(flagset, p_args, p_n);
	if (flagset.type == '%')
		*p_n += write(1, "%", 1);
}

void	printer(const char *fstr, va_list *p_args, int *p_n)
{
	int	i;

	i = 0;
	while (fstr[i])
	{
		while (fstr[i] && fstr[i] != '%')
		{
			*p_n += write(1, &fstr[i], 1);
			i++;
		}
		if (fstr[i] == '%')
		{
			i += 1;
			fprinter(&fstr[i], p_args, p_n);
			while (fstr[i] && !ft_strchr("cspdiuxX%", fstr[i]))
				i++;
			i += 1;
		}
	}
}

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int		n;

	n = 0;
	if (!fstr)
		return (n);
	va_start(args, fstr);
	printer(fstr, &args, &n);
	va_end(args);
	return (n);
}

int	main(void)
{
	int	i;

	i = ft_printf("[%-5c]", '*');
	printf("\n%d bytes printed\n", i - 2);
	i = ft_printf("[%8.4s]", "hello");
	printf("\n%d bytes printed\n", i - 2);
	return (0);
}
