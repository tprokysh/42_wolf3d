/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:19:31 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 19:28:01 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_arrlen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
