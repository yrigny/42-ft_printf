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

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int	n;

	if (!fstr)
		return (0);
	va_start(args, fstr);
	n = printer(fstr, &args);
	va_end(args);
	return (n);
}

int	main()
{
	int	i;

	i = ft_printf("Hello World");
	printf("%d bytes printed\n", i);
	return 0;
}
