/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:55:13 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/23 11:07:56 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_flags
{
	bool			left;
	bool			plus;
	bool			space;
	bool			hash;
	bool			zero;
	unsigned int	width;
	unsigned int	precis;
}				t_flags;

int     ft_printf(const char *fstr, ...);
int	printer(const char *fstr, va_list *args);
int	fprinter(char *flags, char type, va_list *p_args);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_putstr(char *str);

#endif
