/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/17 10:11:03 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include "stdlib.h"
# include "stdio.h"

# define SS 2
# define W 1500 * SS 
# define H 800 * SS
# define FOV 30
# define KEY_ESC 53
# define DIST_MAX 20000
# define AVERAGE(a, b)   ( ((((a) ^ (b)) & 0xfffefefeL) >> 1) + ((a) & (b)) )

# define KEY_ESC 53
# define DIST_MAX 20000

enum	e_type
{
	PLANE = 2,
	SPHERE,
	CYLINDER,
	CONE
};

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_object
{
	int				type;
	t_vector		origin;
	double			radius;
	t_vector		direction;
	t_color			color;
	struct s_object	*next;
}				t_object;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			sl;
	t_vector	camera;
	int			endian;
	char		*data;
	t_vector	light;
	unsigned int	*img_temp;
	t_object	*obj;
}				t_env;

unsigned int	ret_colors(t_color color);
t_vector		normalize(t_vector vector);
t_vector		c_vector(double x, double y, double z);
t_vector		vec_ope_min(t_vector v1, t_vector v2);
t_vector		vec_ope_add(t_vector v1, t_vector v2);
t_vector		vec_ope_mult(t_vector v1, double d);
t_vector		vec_ope_div(t_vector v1, double d);
t_ray			c_ray(t_vector i, t_vector j);
t_color			c_color(double r, double g, double b);
t_env			*set_win_img(void);
int				raytrace(t_env *e);
void			super_sampler(t_env *e);
double			dot(t_vector v, t_vector b);
double			intersect_sphere(t_ray ray, t_object sphere);
int				key_hook(int keycode, t_env *e);
void			color_mult(t_color *color, double taux);
double			get_length(t_vector v);
double			intersect_plane(t_ray ray, t_object sphere);
double			intersect_cylinder(t_ray ray, t_object cylinder);
t_color			*compute_color_sphere(t_env *e, t_vector poi, t_object sphere);
t_env			*parse(t_env *e);
t_color			*copy_color(t_color color);
t_color			*compute_color_plane(t_env *e, t_vector poi, t_object plane);
t_color			*compute_color_cylinder(t_env *e, t_vector poi, t_object cylinder);

#endif
