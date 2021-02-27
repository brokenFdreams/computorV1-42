/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:47 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:32:32 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

double	ft_sqrtf(int x)
{
	double	sqrt;
	int		i;

	sqrt = x / 2;
	i = 0;
	while (i++ < 25)
		sqrt = (sqrt + x / sqrt) / 2;
	return (sqrt);
}
