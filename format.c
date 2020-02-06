/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:38:06 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:32:34 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format(t_printf *param)
{
	to_space(param);
	precision(param);
	if(!convert_to_string(param))
		return (0);
	precision_zero(param);
	if (param->precision_flag)
	{
		modify_precision(param);
		if (param->type == 'i' || param->type == 'd')
			modify_int(param);
		modify_width(param);
	}
	else
	{
		modify_width(param);
		modify_int(param);
	}	
	print_final_str(param);
	return (1);
}