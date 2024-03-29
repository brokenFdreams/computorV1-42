/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:22:58 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/26 16:24:25 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nbr)
{
	int	i;

	i = 0;
	while (i * i < nbr)
		i++;
	return (i);
}
