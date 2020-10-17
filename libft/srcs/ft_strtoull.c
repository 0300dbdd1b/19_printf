/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:01:37 by naddino           #+#    #+#             */
/*   Updated: 2020/10/16 23:06:49 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long		ft_strtoull(const char *str)
{
	unsigned long long		x;
	unsigned long long		output;

	x = 0;
	output = 0;
	while (str[x] == ' ' || str[x] == '\t' || str[x] == '\v'
		|| str[x] == '\n' || str[x] == '\r' || str[x] == '\f')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			return (0);
		x++;
	}
	while (str[x] <= '9' && str[x] >= '0' && str[x])
	{
		output = output * 10 + str[x] - '0';
		x++;
	}
	return (output);
}
