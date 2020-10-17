/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:10:59 by naddino           #+#    #+#             */
/*   Updated: 2020/10/16 23:12:14 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	unsigned int i;

	i = nbr;
	if (ft_check_base(base) != 0)
	{
		if (i >= ft_strlen(base))
			ft_putnbr_base(i / ft_strlen(base), base);
		ft_putchar_fd(base[i % ft_strlen(base)], fd);
	}
}
