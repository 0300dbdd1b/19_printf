/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:07:12 by naddino           #+#    #+#             */
/*   Updated: 2020/12/18 01:21:51 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int						x;
	int						neg;
	unsigned long long		output;

	x = 0;
	neg = 1;
	output = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32 || str[x] == '0')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			neg *= -1;
		x++;
	}
	while (str[x] <= '9' && str[x] >= '0' && str[x])
	{
		output = output * 10 + str[x] - '0';
		if (output > LONG_MAX)
			return ((neg == 1) ? -1 : 0);
		x++;
	}
	return ((int)((output) * (neg)));
}
