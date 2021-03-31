/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:38:37 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:32:58 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_base(unsigned long int nb, char case_x)
{
	char *hex;
	char *base;
	unsigned long int nbr;
	unsigned int len;
	
	base = (case_x == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	len = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	nbr = nb;
	while (nbr)
	{
		len++;
		nbr = nbr / 16;
	}
	nbr = nb;	
	hex = (char*)malloc(sizeof(char) * (len + 1));
	hex[len] = '\0';
	while (nbr)
	{
		hex[--len] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (hex);
}
