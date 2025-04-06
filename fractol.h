/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:55:51 by bcili             #+#    #+#             */
/*   Updated: 2025/03/31 14:55:51 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <signal.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

int			ft_strcmp(char *s1, char *s2);
void		putstr_fd(char *s, int fd);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	add_complex(t_complex z1, t_complex z2);
double		norm_complex(t_complex z);
t_complex	square_complex(t_complex z);
int			handle_keypress(int keysym, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		init_fractal_data(t_fractal *fractal);
void		init_fractal(t_fractal *fractal);
int			exit_program(t_fractal *fractal);
int			handle_mouse(int button, int x, int y, t_fractal *fractal);
double		atodbl(char *s);

#endif