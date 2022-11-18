/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:38:13 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:42:20 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void	positive_discriminant(int *values, int discriminant)
{
	double	b;
	double	sqrtf;

	b = (-1.0) * values[1] / (2.0 * values[2]);
	sqrtf = ft_sqrtf(-1 * discriminant) / (2.0 * values[2]);
	printf("Discriminant is strictly negative, "
		"the two solutions are:\n");
	printf("%lf\n", b + sqrtf);
	printf("%lf\n", b - sqrtf);
}

void	negative_discriminant(int *values, int discriminant)
{
	double	b;
	double	sqrtf;

	b = (-1.0) * values[1] / (2.0 * values[2]);
	sqrtf = ft_sqrtf(-1 * discriminant) / (2.0 * values[2]);
	printf("Discriminant is strictly positive, "
		"the two solutions are:\n");
	if (sqrtf >= 0.0)
	{
		printf("%lf + %lf * i\n", b, sqrtf);
		printf("%lf - %lf * i\n", b, sqrtf);
	}
	else
	{
		printf("%lf - %lf * i\n", b, (-1.0) * sqrtf);
		printf("%lf + %lf * i\n", b, (-1.0) * sqrtf);
	}
}

void	discriminant(int *values)
{
	int	discriminant;

	discriminant = values[1] * values[1] - 4 * values[2] * values[0];
	if (discriminant == 0)
		printf("Discriminant is equal zero, the solution is:\n%f",
			(-1.0) * values[1] / (2.0 * values[2]));
	else if (discriminant > 0)
		positive_discriminant(values, discriminant);
	else
		negative_discriminant(values, discriminant);
}
