/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:05 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:40:25 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"
# include <stdio.h>

void	set_arguments(char *expression,
			int *values, int mindegree, int *degrees);
void	resolution(int *values, int *degrees);
void	discriminant(int *values);

void	remove_all_spaces(char *expression);
void	write_reduced_form(int *values, int *degrees);
void	free_memory(int **values, int **degrees);
void	ft_error(char *str);
void	ft_error_f(char *str, int **values, int **degrees);

double	ft_sqrtf(int x);

#endif
