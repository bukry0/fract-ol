/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:03:00 by bcili             #+#    #+#             */
/*   Updated: 2025/03/31 15:03:00 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static int	get_color(int i, int max_iterations, char *fractal_name)
{
	double	t;
	int		red;
	int     green;
	int     blue;

	t = (double)i / max_iterations;
	if (!ft_strcmp(fractal_name, "mandelbrot"))
	{
		red = 255 - (int)(2 * (1 - t) * t * t * 100);
		green = 255 - (int)(18 * (1 - t) * (1 - t) * t * t * 180);
		blue = 255 - (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 220);
	}
	else if (!ft_strcmp(fractal_name, "julia"))
	{
		red = 255 - (int)(16 * (1 - t) * t * t * 220);
		green = 255 - (int)(12 * (1 - t) * (1 - t) * t * 130);
		blue = 255;
	}
	return ((red << 16) | (green << 8) | blue);
}

static void	set_initial_c(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else  if (!ft_strcmp(fractal->name, "mandelbrot"))
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

    z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	set_initial_c(&z, &c, fractal);
	i = 0;
	while (i < fractal->iterations_definition)
	{
		z = add_complex(square_complex(z), c);
		if (norm_complex(z) > fractal->escape_value)
			break ;
		i++;
	}
	color = get_color(i, fractal->iterations_definition, fractal->name);
	put_pixel(x, y, &fractal->img, color);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
