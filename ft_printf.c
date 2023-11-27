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

void	parseflag(t_flags *p_flags, const char *fstr)
{
	while (*fstr && ft_strchr("-+ #0", *fstr))
	{
		if (*fstr == '-')
			p_flags->left = 1;
		if (*fstr == '+')
			p_flags->plus = 1;
		if (*fstr == ' ')
			p_flags->space = 1;
		if (*fstr == '#')
			p_flags->hash = 1;
		if (*fstr == '0' && !ft_strchr(fstr, '.'))
			p_flags->zero = 1;
		fstr++;
	}
	if (*fstr && *fstr >= '1' && *fstr <= '9')
		p_flags->width = ft_atoi(fstr);
	while (*fstr && *fstr >= '0' && *fstr <= '9')
		fstr++;
	if (*fstr == '.')
		p_flags->precis = ft_atoi(fstr + 1);
	while (*fstr && !ft_strchr("cspdiuxX%", *fstr))
		fstr++;
	p_flags->type = *fstr;
}

void	iniflagset(t_flags *p_flags)
{
	p_flags->left = 0;
	p_flags->plus = 0;
	p_flags->space = 0;
	p_flags->hash = 0;
	p_flags->zero = 0;
	p_flags->width = 0;
	p_flags->precis = 0;
	p_flags->type = 0;
}

void	fprinter(const char *fstr, va_list *p_args, int *p_n)
{
	t_flags	flags;

	iniflagset(&flags);
	parseflag(&flags, fstr);
	if (p_flags->left == 1)
		p_flags->zero = 0;
	if (p_flags->plus == 1)
		p_flags->space = 0;
	if (flags.type == 'c')
		fprinter_c(flags, p_args, p_n);
	if (flags.type == 's')
		fprinter_s(flags, p_args, p_n);
	if (flags.type == 'p')
		fprinter_p(flags, p_args, p_n);
	if (flags.type == 'd' || flags.type == 'i')
		fprinter_d(flags, p_args, p_n);
	if (flags.type == 'u')
		fprinter_u(flags, p_args, p_n);
	if (flags.type == 'x')
		fprinter_x(flags, p_args, p_n, "0123456789abcdef");
	if (flags.type == 'X')
		fprinter_x(flags, p_args, p_n, "0123456789ABCDEF");
	if (flags.type == '%')
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
	printf("\n[%-5c]", '*');
	printf("\n%d bytes printed\n", i - 2);
	i = ft_printf("[%8.4s]", "hello");
	printf("\n[%8.4s]", "hello");
	printf("\n%d bytes printed\n", i - 2);
	i = ft_printf("[%-20p]", &i);
	printf("\n[%-20p]", &i);
	printf("\n%d bytes printed\n", i - 2);
	i = ft_printf("[%+010.5d]", 26);
	printf("\n[%+010.5d]", 26);
	printf("\n%d bytes printed\n", i - 2);
	i = ft_printf("[%010.4u]", 42);
	printf("\n[%010.4u]", 42);
	printf("\n%d bytes printed\n", i - 2);
	i = ft_printf("[%#10.6x]", 65535);
	printf("\n[%#10.6x]", 65535);
	printf("\n%d bytes printed\n", i - 2);
	i = ft_printf("[%#010X]", 65535);
	printf("\n[%#010X]", 65535);
	printf("\n%d bytes printed\n", i - 2);
	return (0);
}
