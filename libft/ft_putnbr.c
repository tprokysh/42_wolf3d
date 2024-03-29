/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:24:03 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/29 16:53:26 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	if (n < -9 || n > 9)
		ft_putnbr(n / 10);
	if (n < 0)
	{
		if (n >= -9 && n <= 9)
			ft_putchar('-');
		ft_putchar('0' - (n % 10));
	}
	else
		ft_putchar((n % 10) + '0');
}
