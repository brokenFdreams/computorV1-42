//
// Created by voult on 11.10.2020.
//

#include "computorv1.h"

void	remove_all_spaces(char *expression)
{
	int	i;
	int j;

	i = 0;
	while (expression[i])
	{
		if (expression[i] == ' ')
		{
			j = i;
			while (expression[++j])
				expression[j - 1] = expression[j];
			expression[j - 1] = '\0';
		}
		i++;
	}
}

void	ft_error(char *str)
{
	ft_putstr(str);
	ft_putendl(" I can't solve.\n");
	exit(0);
}