/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:39:35 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 17:45:35 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(t_printf *param)
{
	param->zero = 0;
	while (*param->str == '0')
	{
		param->zero = 1;
		param->str++;
	}
}

void	flag_minus(t_printf *param)
{
	param->minus = 0;
	if (*param->str == '-')
	{
		param->minus = 1;
		param->str++;
	}
}
void	to_space(t_printf *param)
{
	flag_zero(param);
	flag_minus(param);
	param->width = 0;
	param->neg_int = 0;
	if (*param->str == '*')
	{
		param->width = va_arg(param->ap, int);
		if (param->width < 0)
		{
			param->width = param->width * -1;
			param->minus = 1;
		}
		param->str++;
	}
	while (*param->str >= '0' && *param->str <= '9')
	{
		param->width = (param->width * 10) + (*param->str - '0');
		param->str++;
	}
	if (param->zero && param->minus)
		param->zero = 0;
}