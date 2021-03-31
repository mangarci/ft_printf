/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarciasanchez <manugarciasanchez@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:38:18 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/29 20:32:13 by manugarcias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
#define _FT_PRINTF_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct s_printf
{
	unsigned int	len;
	int				precision;
	unsigned int	precision_zero;
	int				width;
	int				precision_flag;
	unsigned int	neg_int;
	unsigned int	minus;
	unsigned int	zero;
	char			*str;
	va_list			ap;
	char			*final_str;
	char			type;
	char			null_term;

} 				t_printf;

int		convert_to_string(t_printf *param);
int		ft_printf(const char *string, ...);
void	precision_zero(t_printf *param);
void	modify_int(t_printf *param);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*set_space(int count, char signo);
void	print_int(t_printf *param);
void	print_string(t_printf *param);
void	print_char(t_printf *param);
void	print_percent(t_printf *param);
void	print_uint(t_printf *param);
void	to_space(t_printf *param);
void	precision(t_printf *param);
char	*ft_putnbr_base(unsigned long int nb, char case_x);
int		format(t_printf *param);
void	print_final_str(t_printf *param);
void	modify_width(t_printf *param);
void	modify_precision(t_printf *param);
void	modify_adress(t_printf *param);
void	print_hex(t_printf *param);
void	print_pointer(t_printf *param);
#endif
