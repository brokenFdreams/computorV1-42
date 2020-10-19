//
// Created by voult on 13.10.2020.
//
#include "computorv1.h"

void resolution_zero(int value)
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

void resolution_one(int *values)
{
	ft_putendl("The solution is:");
	if (values[0] == 0)
		ft_putendl("0");
	else
		printf("%f\n", -1.0 * values[0] / (float) values[1]);//TODO
}

void positive_discriminant(int *values, int discriminant)
{
	double b;
	double sqrtf;

	b = (-1.0) * values[1] / (2.0 * values[2]);
	sqrtf = ft_sqrtf(-1 * discriminant) / (2.0 * values[2]);
	printf("Discriminant is strictly negative, "
		   "the two solutions are:\n");
	printf("%lf\n", b + sqrtf);//TODO: fix printf with 0.500000 need to be 0.5
	printf("%lf\n", b - sqrtf);//TODO
}

void negative_discriminant(int *values, int discriminant)
{
	double b;
	double sqrtf;

	b = (-1.0) * values[1] / (2.0 * values[2]);
	sqrtf = ft_sqrtf(-1 * discriminant) / (2.0 * values[2]);
	printf("Discriminant is strictly positive, "
		   "the two solutions are:\n");
	if (sqrtf >= 0.0)
	{
		printf("%lf + %lf * i\n", b, sqrtf);//TODO
		printf("%lf - %lf * i\n", b, sqrtf);//TODO
	} else
	{
		printf("%lf - %lf * i\n", b, (-1.0) * sqrtf);//TODO
		printf("%lf + %lf * i\n", b, (-1.0) * sqrtf);//TODO
	}
}

void resolution_two(int *values)
{
	int discriminant;

	discriminant = values[1] * values[1] -
				   4 * values[2] * values[0];
	if (discriminant == 0)
		printf("Discriminant is equal zero, the solution is:\n%f",
			   (-1.0) * values[1] / (2.0 * values[2]));//TODO
	else if (discriminant > 0)
		positive_discriminant(values, discriminant);
	else
		negative_discriminant(values, discriminant);
}

void resolution(int *values, int *degrees)
{
	if (degrees[1] == 0)
		resolution_zero(values[degrees[0] * (-1)]);
	else if (degrees[1] == 1)
		resolution_one(values + degrees[0] * (-1));
	else
		resolution_two(values + degrees[0] * (-1));
}
