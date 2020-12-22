/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:00:37 by naddino           #+#    #+#             */
/*   Updated: 2020/12/18 00:59:33 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list argp)
{
	char c;

	c = va_arg(argp, int);
	if (g_width > 0)
		ft_print_space_format(g_width - 1, 0, 0);
	ft_putchar_fd(c, 1);
	if (g_width < 0)
		ft_print_space_format(ft_abs(g_width) - 1, 0, 0);
}

void	ft_print_string(va_list argp)
{
	char	*str;
	int		len;
	int		nbr_space;
	int		zero;

	zero = (g_w && g_w[0] == '0') ? 1 : 0;
	nbr_space = 0;
	str = va_arg(argp, char *);
	if (str == NULL)
		str = "(null)";
	len = (((size_t)g_prec < ft_strlen(str) && g_prec != 0) || g_prec == 0) ?
	g_prec : ft_strlen(str);
	if (g_width > 0)
		nbr_space = (g_width > len) ? g_width - len : 0;
	else if (g_width < 0)
		nbr_space = (ft_abs(g_width) > len) ? ft_abs(g_width) - len : 0;
	if (nbr_space > 0 && ft_abs(g_width) == g_width)
		ft_print_space_format(nbr_space, zero, 0);
	if (g_prec != 0)
		ft_crop(str, g_prec);
	if (nbr_space > 0 && ft_abs(g_width) != g_width)
		ft_print_space_format(nbr_space, zero, 0);
}

void	ft_print_pointer(va_list argp)
{
	size_t	nbr;
	int		zero;

	nbr = va_arg(argp, size_t);
	g_len = ft_len_pointer(nbr);
	if (g_width > 0)
	{
		zero = (g_w && g_w[0] == '0' && g_prec < 0) ? 1 : 0;
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		if (g_width > g_len + 2)
			ft_print_space_format(g_width - g_len - 2, 0, 0);
	}
	ft_putstr_fd("0x", 1);
	if (g_prec > 0 && g_prec > ft_len_pointer(nbr))
		ft_print_space_format(g_prec - ft_len_pointer(nbr), 1, 0);
	if (g_prec != 0 || nbr != 0)
		ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
	if (g_width < 0 && ft_abs(g_width) > g_len + 2)
	{
		g_len = ((g_prec == 0 && nbr == 0) || g_prec > g_len) ? g_prec : g_len;
		ft_print_space_format(ft_abs(g_width) - g_len - 2, 0, 0);
	}
}

void	ft_print_space(const char *format, int i, va_list argp)
{
	int		nbr_space;
	int		z;
	char	c;
	int		neg;

	nbr_space = 0;
	if (format[i] == '*' && format[i - 1] == '.')
		va_arg(argp, int);
	while (ft_isdigit(format[i]) || format[i] == '*'
	|| format[i] == '.')
		i--;
	neg = (format[i] == '-') ? -1 : 1;
	if ((format[i + 1] == '*') ||
	(format[i + 1] == '0' && format[i + 2] == '*'))
		nbr_space = va_arg(argp, int) * neg;
	else if (ft_isdigit(format[i + 1]))
		nbr_space = ft_atoi(&format[i + 1]) * neg;
	if (nbr_space < 0)
		ft_putchar_fd('%', 1);
	c = (format[i + 1] == '0' && nbr_space > 0 && format[i] != '-') ? '0' : ' ';
	z = ft_abs(nbr_space);
	while (z-- && z > 0)
		ft_putchar_fd(c, 1);
	if (ft_abs(nbr_space) == nbr_space)
		ft_putchar_fd('%', 1);
}

void	ft_stock(const char *format, int i, va_list argp)
{
	while (ft_isdigit(format[i]) || format[i] == '-' || format[i] == '+')
		i--;
	if (format[i] == '.')
	{
		g_p = &format[i + 1];
		g_prec = ft_atoi(&format[i + 1]);
	}
	if (format[i] != '.' || (format[i] == '.' && ft_isdigit(format[i - 1])))
	{
		if (format[i] == '.')
			i--;
		while (ft_isdigit(format[i]) || format[i] == '-' || format[i] == '+')
			i--;
		i++;
		g_w = &format[i];
		g_width = ft_atoi(&format[i]);
	}
	if (format[i] == '.' && format[i - 1] == '*')
	{
		g_width = va_arg(argp, int);
		g_width = (format[i - 2] == '-' && g_width > 0) ? g_width * -1 :
		g_width;
		if (format[i - 2] == ' ')
			g_space = 1;
	}
}
