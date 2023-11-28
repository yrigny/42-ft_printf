/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprinter_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:44:18 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/28 02:40:58 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fprinter_s(t_flags flags, va_list *p_args, int *p_n)
{
	char	*s;
	int		printable_s;

	s = va_arg(*p_args, char *);
	printable_s = ft_strlen(s);
	if (flags.precis_y == 1 && flags.precis < printable_s)
		printable_s = flags.precis;
	if (flags.width > printable_s && flags.left == 0)
		*p_n += putnchar(flags.width - printable_s, ' ');
	*p_n += write(1, s, printable_s);
	if (flags.width > printable_s && flags.left == 1)
		*p_n += putnchar(flags.width - printable_s, ' ');
}

void	fprinter_p(t_flags flags, va_list *p_args, int *p_n)
{
	void	*p;
	int		numlen;

	p = va_arg(*p_args, void *);
	numlen = getnumlen((long)p, 16);
	if (flags.width > 2 + numlen && flags.left == 0)
		*p_n += putnchar(flags.width - 2 - numlen, ' ');
	*p_n += write(1, "0x", 2);
	putnbr_base((long)p, "0123456789abcdef", 16);
	*p_n += numlen;
	if (flags.width > 2 + numlen && flags.left == 1)
		*p_n += putnchar(flags.width - 2 - numlen, ' ');
}

void	fprinter_d(t_flags flags, va_list *p_args, int *p_n)
{
	int	d;
	int	printable_d;

	d = va_arg(*p_args, int);
	printable_d = getnumlen((long)d, 10);
	if (flags.precis > printable_d)
		printable_d = flags.precis;
	if (flags.plus == 1 || flags.space == 1 || d < 0)
		printable_d += 1;
	if (flags.width > printable_d && flags.left == 0 && flags.zero == 0)
		*p_n += putnchar(flags.width - printable_d, ' ');
	if (flags.plus == 1 && d >= 0)
		*p_n += write(1, "+", 1);
	if (flags.space == 1 && d >= 0)
		*p_n += write(1, " ", 1);
	if (d < 0)
		*p_n += write(1, "-", 1);
	if (flags.width > printable_d && flags.zero == 1)
		*p_n += putnchar(flags.width - printable_d, '0');
	if (flags.precis > getnumlen((long)d, 10))
		*p_n += putnchar(flags.precis - getnumlen((long)d, 10), '0');
	putnbr_base((long)d, "0123456789", 10);
	*p_n += getnumlen((long)d, 10);
	if (flags.width > printable_d && flags.left == 1)
		*p_n += putnchar(flags.width - printable_d, ' ');
}

void	fprinter_u(t_flags flags, va_list *p_args, int *p_n)
{
	unsigned int	u;
	int				numlen;
	int				printable_u;

	u = va_arg(*p_args, unsigned int);
	numlen = getnumlen((long)u, 10);
	printable_u = numlen;
	if (flags.precis > printable_u)
		printable_u = flags.precis;
	if (flags.width > printable_u && flags.zero == 1)
		*p_n += putnchar(flags.width - printable_u, '0');
	else if (flags.width > printable_u && flags.left == 0)
		*p_n += putnchar(flags.width - printable_u, ' ');
	if (flags.precis > numlen)
		*p_n += putnchar(flags.precis - numlen, '0');
	putnbr_base((long)u, "0123456789", 10);
	*p_n += numlen;
	if (flags.width > printable_u && flags.left == 1)
		*p_n += putnchar(flags.width - printable_u, ' ');
}

void	fprinter_x(t_flags flags, va_list *p_args, int *p_n, char *base)
{
	unsigned int	x;
	int				numlen;
	int				printable_x;

	x = va_arg(*p_args, unsigned int);
	numlen = getnumlen((long)x, 16);
	printable_x = numlen;
	if (flags.precis > printable_x)
		printable_x = flags.precis;
	if (flags.hash == 1)
		printable_x += 2;
	if (flags.width > printable_x && flags.left == 0 && flags.zero == 0)
		*p_n += putnchar(flags.width - printable_x, ' ');
	if (flags.hash == 1 && flags.type == 'x')
		*p_n += write(1, "0x", 2);
	else if (flags.hash == 1 && flags.type == 'X')
		*p_n += write(1, "0X", 2);
	if (flags.width > printable_x && flags.zero == 1)
		*p_n += putnchar(flags.width - printable_x, '0');
	else if (flags.precis > numlen)
		*p_n += putnchar(flags.precis - numlen, '0');
	putnbr_base((long)x, base, 16);
	*p_n += numlen;
	if (flags.width > printable_x && flags.left == 1)
		*p_n += putnchar(flags.width - printable_x, ' ');
}
