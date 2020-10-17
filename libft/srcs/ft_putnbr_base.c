/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:11:36 by naddino           #+#    #+#             */
/*   Updated: 2020/10/16 23:11:38 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int i;

	i = nbr;
	if (ft_check_base(base) != 0)
	{
		if (i >= ft_strlen(base))
			ft_putnbr_base(i / ft_strlen(base), base);
		ft_putchar(base[i % ft_strlen(base)]);
	}
}
