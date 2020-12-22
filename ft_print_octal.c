/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:00:51 by naddino           #+#    #+#             */
/*   Updated: 2020/12/17 14:00:54 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_octal(va_list argp)
{
	unsigned int	nbr;
	int				zero;
	int				neg;

	nbr = va_arg(argp, unsigned int);
	g_len = ft_len_nbr(nbr, 8);
	neg = (nbr < 0 && (g_prec > g_len || (g_w && g_w[0] == '0'))) ? 1 : 0;
	nbr = (neg && ((g_prec > 0 && g_prec > g_len) || (g_w && g_w[0] == '0' &&
	g_width > g_len && g_prec < 0))) ? ft_abs(nbr) : nbr;
	if (g_width > 0)
	{
		zero = (g_w && g_w[0] == '0' && g_prec < 0) ? 1 : 0;
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		if (g_width > g_len)
			ft_print_space_format(g_width - g_len, zero, neg);
	}
	if (g_prec > 0 && g_prec > ft_len_nbr(nbr, 8))
		ft_print_space_format(g_prec - ft_len_nbr(nbr, 8), 1, neg);
	if (g_prec != 0)
		ft_putnbr_base_fd(nbr, "01234567", 1);
	if (g_width < 0 && ft_abs(g_width) > g_len)
	{
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		ft_print_space_format(ft_abs(g_width) - g_len, 0, neg);
	}
}
