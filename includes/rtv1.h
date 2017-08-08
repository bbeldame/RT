/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/08 17:00:05 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <math.h>
# include "../miniLibX/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
** if we want to switch on or off supersampler we need to change
** SS value. 1 for off, 2 for on.
*/

# define DEFAULT_SUPERSAMPLING 1
# define SS (e->setup.supersampling + 1)
# define W 1500 * SS
# define H 800 * SS
# define FOV 30
# define KEY_ESC 53
# define DIST_MAX 20000
# define DIST_MIN -80000
# define AMBIENT_LIGHT 50

/*
** Compute the average color between two 24-bits RGB colors
** https://www.compuphase.com/graphic/scale3.htm
*/

# define AVERAGE(a, b)   ( ((((a) ^ (b)) & 0xfffefefeL) << 1) + ((a) & (b)) )

//# define AVERAGE(a, b)   ( ((((a) ^ (b)) & 0xfffefefeL) >> 1) + ((a) + (b)) ) //effect bizarre

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

typedef struct	s_setup
{
	int			supersampling;
	int			bpp;
	int			sl;
	int			endian;
	t_vector	camera;
}				t_setup;

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

typedef struct		s_light
{
	double			intensity;
	t_vector		origin;
	struct s_light	*next;
}					t_light;

typedef struct	s_object
{
	int				type;
	double			radius;
	t_vector		normal;
	t_vector		origin;
	t_vector		direction;
	t_color			color;
	struct s_object	*next;
}				t_object;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_setup			setup;
	char			*data;
	t_light			*light;
	unsigned int	*img_temp;
	t_object		*obj;
	int				nbline;
	int				fd;
}					t_env;

unsigned int	ret_colors(t_color color);
t_vector		normalize(t_vector vector);
t_vector		c_vector(double x, double y, double z);
t_vector		vec_ope_min(t_vector v1, t_vector v2);
t_vector		vec_ope_add(t_vector v1, t_vector v2);
t_vector		vec_ope_mult(t_vector v1, double d);
t_vector		vec_ope_div(t_vector v1, double d);
t_ray			c_ray(t_vector i, t_vector j);
t_color			c_color(double r, double g, double b);
void			set_win_img(t_env *e);
int				raytrace(t_env *e);
void			super_sampler(t_env *e);
void			anti_supersampler(t_env *e);
double			dot(t_vector v, t_vector b);
double			intersect_sphere(t_ray ray, t_object sphere);
int				key_hook(int keycode, t_env *e);
t_color			*color_mult(t_color color, double taux);
double			get_length(t_vector v);
double			intersect_plane(t_ray ray, t_object sphere);
double			intersect_cylinder(t_ray ray, t_object cylinder);
t_color			*copy_color(t_color color);
double			intersect_cone(t_ray ray, t_object cone);
double			intensity_cone(t_env *e, t_vector poi,
					t_object cone, t_light light);
double			intensity_sphere(t_env *e, t_vector poi,
					t_object sphere, t_light light);
double			intensity_plane(t_env *e, t_vector poi,
					t_object plane, t_light light);
double			intensity_cylinder(t_env *e, t_vector poi,
					t_object cylinder, t_light light);
double			get_min_dist(t_env *e, t_ray ray, t_object **closest, int cangoneg);
int				obj_in_shadow(t_env *e, t_vector poi, t_light light);
double			get_res_of_quadratic(double a, double b, double c);

/*
** Parser
*/

t_env			*parse(char *scene);
void			syntax_error(char *line, char *explain, int nbline);
void			unknown_setting(char *line, int nbline);
char			*trim_setting(t_env *e, char *setting);
char			*trim_option(t_env *e, char *option, char **arg);
void			dispatch(t_env *e, char *line);
void			set_sphere(t_env *e);
void			set_plane(t_env *e);
void			set_plane_data(t_object *plane);
void			set_cylinder(t_env *e);
void			set_cone(t_env *e);
void			set_camera(t_env *e);
void			set_light(t_env *e);
void			set_supersampling(t_env *e, char *line);
t_vector		set_vector(t_env *e, char *arg);
t_color			set_color(t_env *e, char *arg);
void			unknown_option(char *line, int nbline, char *caller);
void			set_first_obj(t_env *e, t_object *obj);
void			set_first_light(t_env *e, t_light *light);

#endif
