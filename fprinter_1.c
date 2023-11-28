/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:33:39 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/24 13:33:44 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	putnchar(int n, char c)
{
	int	i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}

int	getnumlen(long num, int baselen)
{
	int	numlen;

	numlen = 1;
	while (num >= baselen || num <= -baselen)
	{
		numlen += 1;
		num /= baselen;
	}
	return (numlen);
}

void	putnbr_base(long nbr, char *base, int baselen)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= baselen)
	{
		putnbr_base(nbr / baselen, base, baselen);
		write(1, &base[nbr % baselen], 1);
	}
	else
		write(1, &base[nbr], 1);
}

void	fprinter_c(t_flags flags, va_list *p_args, int *p_n)
{
	char	*farg;
	int		c;

	c = va_arg(*p_args, int);
	if (flags.width <= 1)
	{
		farg = (char *)ft_calloc(2, 1);
		farg[0] = (char)c;
	}
	else
	{
		farg = (char *)ft_calloc(flags.width + 1, 1);
		ft_memset(farg, ' ', flags.width);
		if (flags.left == 1)
			farg[0] = (char)c;
		if (flags.left == 0)
			farg[flags.width - 1] = (char)c;
	}
	*p_n += ft_putstr(farg);
	free(farg);
}
