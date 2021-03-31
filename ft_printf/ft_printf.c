/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:38:12 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:28:44 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *string, ...)
{
	t_printf param;

	param.len = 0;
	param.str = (char *)string;
	va_start(param.ap, string);
	while (*param.str)
	{
		while (*param.str == '%')
		{
			param.str++;
			if (!format(&param))
				return (param.len);
			if (!*param.str)
				return (param.len);
			
		}
		write(1, param.str++, 1);
		param.len++;
	}
	va_end(param.ap);
	return (param.len);
}