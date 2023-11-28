/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:55:13 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/28 02:39:09 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_flags
{
	bool	left;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero;
	int		width;
	int		precis_y;
	int		precis;
	char	type;
}		t_flags;

int		ft_printf(const char *fstr, ...);
void	printer(const char *fstr, va_list *p_args, int *p_n);
void	fprinter(const char *fstr, va_list *p_args, int *p_n);
void	iniflagset(t_flags *p_flagset);
void	parseflag(t_flags *p_flagset, const char *fstr);
int		ft_putstr(char *str);
int		putnchar(int n, char c);
int		getnumlen(long num, int baselen);
void	putnbr_base(long nbr, char *base, int baselen);
void	fprinter_c(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_s(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_p(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_d(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_u(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_x(t_flags flags, va_list *p_args, int *p_n, char *base);

#endif
