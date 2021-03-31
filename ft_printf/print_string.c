/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:39:29 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:34:09 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_printf *param)
{
	param->final_str = va_arg(param->ap, char*);
	if (param->final_str == '\0')
		param->final_str = "(null)";
}

void	print_char(t_printf *param)
{
	char *aux;
	
	param->null_term = -1;
	aux = (char*)malloc(sizeof(char) * 2);
	aux[0] = (char)va_arg(param->ap, int);
	aux[1] = '\0';
	if (aux[0])
		param->final_str = aux;
	else
	{
		param->final_str = ft_strdup("");
		param->null_term = aux[0];
		param->width--;
		param->len++;
	}
}