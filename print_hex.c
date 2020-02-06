/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:39:12 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:33:41 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(t_printf *param)
{
	if (*param->str == 'X')
		param->final_str = ft_putnbr_base(va_arg(param->ap, unsigned int), 'X');
	else
		param->final_str = ft_putnbr_base(va_arg(param->ap, unsigned int), 'x');
}

void	print_pointer(t_printf *param)
{
	char	*str;
	
	str = ft_putnbr_base(va_arg(param->ap, unsigned long int), 'x');
	param->final_str = ft_strjoin("0x", str);
	if ((param->final_str[2] == ' ' || param->final_str[2] == '0')
	&& param->precision_zero)
		param->final_str = ft_strdup("0x");
}