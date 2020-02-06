/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:37:48 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:32:22 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_to_string(t_printf *param)
{
	param->type = *param->str;
	if (*param->str == 'c')
		print_char(param);
	else if (*param->str == 'd' || *param->str == 'i')
		print_int(param);
	else if (*param->str == 's')
		print_string(param);
	else if (*param->str == 'p')
		print_pointer(param);
	else if (*param->str == 'u')
		print_uint(param);
	else if (*param->str == 'x' || *param->str == 'X')
		print_hex(param);
	else if (*param->str == '%')
		print_percent(param);
	else
		return (0);
	param->str++;
	return (1);
}