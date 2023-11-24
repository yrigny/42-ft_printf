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
	free(str);
	return (i);
}

void	fprinter_c(t_flags flagset, va_list *p_args, int *p_n)
{
	char	*farg;
	int		c;

	c = va_arg(*p_args, int);
	if (flagset.width <= 1)
	{
		farg = (char *)ft_calloc(2, 1);
		farg[0] = (char)c;
		*p_n += ft_putstr(farg);
	}
	farg = (char *)ft_calloc(flagset.width + 1, 1);
	farg = ft_memset(farg, ' ', flagset.width);
	if (flagset.left == 1)
		farg[0] = (char)c;
	if (flagset.left == 0)
		farg[flagset.width - 1] = (char)c;
	*p_n += ft_putstr(farg);
}

void	fprinter_s(t_flags flagset, va_list *p_args, int *p_n)
{
	char		*farg;
	char		*s;
	unsigned int	printable_s;
	
	s = va_arg(*p_args, char *);
	printable_s = ft_strlen(s);
	if (flagset.precis < printable_s)
		printable_s = flagset.precis;
	if (flagset.width < printable_s)
	{
		farg = (char *)ft_calloc(printable_s + 1, 1);
		farg = ft_memcpy(farg, s, printable_s);
		*p_n += ft_putstr(farg);
	}
	farg = (char *)ft_calloc(flagset.width + 1, 1);
	farg = ft_memset(farg, ' ', flagset.width);
	if (flagset.left == 1)
		ft_memcpy(farg, s, printable_s);
	if (flagset.left == 0)
		ft_memcpy(farg + flagset.width - printable_s, s, printable_s);
	*p_n += ft_putstr(farg);
}

void	fprinter_p(t_flags flagset, va_list *p_args, int *p_n)
{
	char	*farg;
	void	*p;

	p = va_arg(*p_args, void *);





















}

void	fprinter_d(t_flags flagset, va_list *p_args, int *p_n)
{
	char	*farg;
	int	d;

	d = va_arg(*p_args, int);























}
