/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:00:15 by bcili             #+#    #+#             */
/*   Updated: 2025/03/31 15:00:15 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_fractal_type(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
	{
		fractal->name = argv[1];
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "julia"))
	{
		fractal->name = argv[1];
		fractal->julia_x = atodbl(argv[2]);
		fractal->julia_y = atodbl(argv[3]);
	}
	else
	{
		putstr_fd("Error\nUsage: ./fractol <fractal_type> <real> <image>", 2);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	set_fractal_type(argc, argv, &fractal);
	init_fractal(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
