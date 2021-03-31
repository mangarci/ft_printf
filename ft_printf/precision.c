/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:39:02 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:33:27 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision(t_printf *param)
{
	param->precision = 0;
	param->precision_zero = 0;
	param->precision_flag = 0;
	if (*param->str == '.')
	{
		param->precision_flag = 1;
		param->str++;
		while (*param->str == '0')
			param->str++;
		if (*param->str == '*')
		{
			param->precision = va_arg(param->ap, int);
			param->str++;
		}
		while (*param->str >= '0' && *param->str <= '9')
		{
			param->precision = (param->precision * 10) + (*param->str - '0');
			param->str++;
		}
		if (param->precision < 0)
		{
			param->precision_flag = 0;
			param->precision = 0;
		}
		if (param->precision_flag && param->precision == 0)
			param->precision_zero = 1;
	}
}