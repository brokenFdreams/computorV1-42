//
// Created by voult on 19.10.2020.
//

#include "computorv1.h"

double	ft_sqrtf(int x)
{
	double sqrt;
	int i;

	sqrt = x / 2;
	i = 0;
	while (i++ < 25)
		sqrt = (sqrt + x / sqrt) / 2;
	return sqrt;
}