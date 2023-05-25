/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:10:33 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/06 22:10:34 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double	ft_atoi_my_version(const char *str)
{
	int		i;
	int		j;
	double	signe;
	double	nbr;

	i = 0;
	j = 0;
	signe = 1.0;
	nbr = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		j = 1;
		if (str[i++] == '-')
			signe *= -1.0;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] != '.')
			nbr = nbr * 10.0 + str[i] - 48.0;
		i++;
	}
	nbr = nbr / pow(10.0, i - (2 + j));
	return (nbr * signe);
}

void	check_set(t_data *var)
{
	if (var->cx == NULL && var->cy == NULL)
	{
		var->c_x = -0.70176;
		var->c_y = -0.3842;
	}
	else
	{
		var->c_x = ft_atoi_my_version(var->cx);
		var->c_y = ft_atoi_my_version(var->cy);
	}
}

void	ft_julia(t_data *var)
{
	check_set(var);
	var->y = -2.0 * (H / 4);
	while (var->y <= 2.0 * (H / 4))
	{
		var->x = -2.0 * (W / 4);
		while (var->x <= 2.0 * (H / 4))
		{
			var->z_x = var->x / var->i;
			var->z_y = var->y / var->i;
			var->iter = 0;
			ft_calc(var);
			var->x++;
		}
		var->y++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
}
