/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_final_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:39:07 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:33:34 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_final_str(t_printf *param)
{
	if (param->minus && param->type == 'c' && param->null_term != -1)
		write(1, &param->null_term, 1);
	while (*param->final_str)
	{
		write(1, param->final_str++, 1);
		param->len++;
	}
	if (!param->minus && param->type == 'c' && param->null_term != -1)
		write(1, &param->null_term,1);
}