/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:05:18 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/26 16:13:02 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_length(uintmax_t nbr, int base)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr / base || nbr % base)
	{
		count++;
		nbr /= base;
	}
	return (count);
}

char	*ft_itoa_base(uintmax_t nbr, int base)
{
	char	*num;
	int		rem;
	int		size;

	size = ft_itoa_length(nbr, base);
	num = ft_strnew(size);
	if (!(num))
		return (NULL);
	size--;
	while (size >= 0)
	{
		rem = nbr % base;
		if (rem >= 10)
			num[size--] = rem + 'a' - 10;
		else
			num[size--] = rem + '0';
		nbr /= base;
	}
	return (num);
}
