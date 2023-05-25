/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:51:04 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/06 21:51:05 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_data *var)
{
	var->y = -2.0 * (H / 4.0);
	while (var->y <= 2.0 * (H / 4.0))
	{
		var->c_y = var->y / var->i;
		var->x = -2.0 * (W / 4.0);
		while (var->x <= 2.0 * (H / 4.0))
		{
			var->z_y = var->y / var->i;
			var->z_x = var->x / var->i;
			var->c_x = var->x / var->i;
			var->iter = 0;
			ft_calc(var);
			var->x++;
		}
			var->y++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
}
