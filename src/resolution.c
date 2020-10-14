//
// Created by voult on 13.10.2020.
//
#include "computorv1.h"

void resolution_zero(int *values)
{
	if (values[0] == 0)
		ft_putendl("Every number is solution.");
	else
	{
		ft_putstr("There's no solution because ");
		ft_putnbr(values[0]);
		ft_putendl(" is not equal 0.");
	}
}

void resolution_one(int *values)
{
	ft_putendl("The solution is: ");
	if (values[0] == 0)
		ft_putendl("0");
	else
		printf("%f\n", -1.0 * values[0]/ (float)values[1]);
}

void resolution_two(int *values, t_solution *solution)
{

}

void resolution(int *values, int *degrees, t_solution *solution)
{
	if (degrees[1] == 0)
		resolution_zero(values);
	else if (degrees[1] == 1)
		resolution_one(values);
	else
		resolution_two(values, solution);
}
