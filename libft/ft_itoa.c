/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:28:10 by mangarci          #+#    #+#             */
/*   Updated: 2019/12/12 16:52:50 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill(size_t n, int i, char *str)
{
	if (n >= 10)
		ft_fill(n / 10, i - 1, str);
	str[i] = n % 10 + '0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 1;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	else
		nbr = n;
	while (nbr /= 10)
	{
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	ft_fill(n < 0 ? -n : n, len - 1, str);
	if (n < 0)
		str[0] = '-';
	return (str);
}
