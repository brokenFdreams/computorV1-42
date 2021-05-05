/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:59 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:43:31 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void	resolution_zero(int value)
{
	if (value == 0)
		ft_putendl("Every number is solution.");
	else
	{
		ft_putstr("There's no solution because ");
		ft_putnbr(value);
		ft_putendl(" is not equal 0.");
	}
}

void	resolution_one(int *values)
{
	ft_putendl("The solution is:");
	if (values[0] == 0)
		ft_putendl("0");
	else
		printf("%f\n", -1.0 * values[0] / (float)values[1]);
}

void	resolution(int *values, int *degrees)
{
	if (degrees[1] == 0)
		resolution_zero(values[degrees[0] * (-1)]);
	else if (degrees[1] == 1)
		resolution_one(values + degrees[0] * (-1));
	else
		discriminant(values + degrees[0] * (-1));
}
