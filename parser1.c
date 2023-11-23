/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:28:39 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/23 16:28:43 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*parser_c(char *flags, va_list *p_args)
{
	int	arg;
	t_flags	flagset;
	char	*farg;
	int	i;

	arg = va_arg(*p_args, int);
	flagset = {0};
	i = 0;
	while (ft_strchr("-+ #0", flags[i]))
	{
		if (flags[i] == '-')
			flagset.minus = 1;
		i++;
	}
	flagset.width = ft_atoi(&flags[i]));
}
