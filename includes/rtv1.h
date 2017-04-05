/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/05 20:19:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include "stdlib.h"
# include "stdio.h"

# define W 1500
# define H 800
# define FOV 30

# define KEY_ESC 53
# define DIST_MAX 20000

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	o;		//origin
	t_vector	d;		//direction
}				t_ray;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_sphere
{
	t_vector	c;		//center
	t_color		p;		//color
	double		r;		//radius
}				t_sphere;


typedef struct	s_screen
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			sizeline;
	int			endian;
	char		*data;
}				t_screen;

unsigned int	ret_colors(t_color colo);
t_vector		normalize(t_vector vector);
t_vector		get_normal(t_sphere s, t_vector poi);
t_vector		c_vector(double x, double y, double z);
t_vector		vec_ope_min(t_vector v1, t_vector v2);
t_vector		vec_ope_add(t_vector v1, t_vector v2);
t_vector		vec_ope_mult(t_vector v1, double d);
t_vector		vec_ope_div(t_vector v1, double d);
t_ray			c_ray(t_vector i, t_vector j);
t_sphere		c_sphere(t_vector center, double radius);
t_color			c_color(double r, double g, double b);
t_screen		*set_win_img(void);
void			raytrace(t_screen *fst);
double			dot(t_vector v, t_vector b);
int				intersect_sphere(t_ray ray, double *t, t_sphere sphere);
int				key_hook(int keycode, t_screen *e);
t_color			color_mult(t_color colo, double taux);
double			get_length(t_vector v);

#endif
