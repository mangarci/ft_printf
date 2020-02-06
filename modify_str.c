/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:38:57 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:33:14 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_space(int n, char signo)
{
	char *ptr;
	int i;

	if (!(ptr = (char *)malloc((n + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < n)
	{
		ptr[i] = signo;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	modify_width(t_printf *param)
{
	char *fill;
	char *aux;
	unsigned int n;
	char c;
	
	n = 0;
	if (param->neg_int && param->zero)
		param->width--;
	if (param->width > (int)ft_strlen(param->final_str))
		n = param->width - ft_strlen(param->final_str);
	c = (param->zero == 1) ? '0' : ' ';
	fill = set_space(n, c);
	if (param->minus)
	{
		aux = ft_strjoin(param->final_str, fill);
		param->final_str = aux;
	}
	else
	{
		aux = ft_strjoin(fill, param->final_str);
		param->final_str = aux;
	}
	free(fill);
}

void	modify_precision(t_printf *param)
{
	char *aux;
	char *fill;
	int n;

	if (param->type == 'i' || param->type == 'u' || param->type == 'd'
	|| param->type == 'x' || param->type == 'X')
	{
		n = 0;
		param->zero = 0;
		if (param->precision > (int)ft_strlen(param->final_str))
			n = param->precision - (int)ft_strlen(param->final_str);
		fill = set_space(n, '0');
		aux = ft_strjoin(fill, param->final_str);
		param->final_str = aux;
		free(fill);
	}
	if (param->type == 's')
	{
		aux = ft_substr(param->final_str, 0, param->precision);
		param->final_str = aux;
	}
}

void	precision_zero(t_printf *param)
{
	if (param->precision_zero)
		if (*param->final_str == '0' && param->type != 'p'
		&& param->type != 'c' && param->type != 's')
			param->final_str = ft_strdup("");
}