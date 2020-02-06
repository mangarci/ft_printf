/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:39:20 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:33:58 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_fill(size_t n, int i, char *str)
{
	if (n >= 10)
		ft_fill(n / 10, i - 1, str);
	str[i] = n % 10 + '0';
}

static char		*ft_itoa_uint(unsigned int n)
{
	char *str;
	unsigned int nbr;
	unsigned int len;

	len = 1;
	nbr = n;
	while (nbr /= 10)
	{
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	ft_fill(n < 0 ? -n : n, len - 1, str);
	return (str);
}

void	print_int(t_printf *param)
{
	int nb;

	nb = va_arg(param->ap, int);
	if (nb < 0 && (param->precision_flag || param->zero))
	{
		nb = nb * -1;
		param->neg_int = 1;
		param->final_str = ft_itoa(nb);
	}
	else	
		param->final_str = ft_itoa(nb);
}

void	print_uint(t_printf *param)
{
	param->final_str = ft_itoa_uint(va_arg(param->ap, unsigned int));
}

void	modify_int(t_printf *param)
{
	char *aux;

	if (param->neg_int)
	{
		if (*param->final_str != '-')
		{
			aux = ft_strjoin("-", param->final_str);
			free(param->final_str);
			param->final_str = aux;
		}
		if (param->precision_flag && param->zero)
			param->width--;
	}
}