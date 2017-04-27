
#include "../../includes/rtv1.h"

void		set_sphere(t_env *e)
{
	static t_object		*sphere;
	char				*option;
	char				*option_arg;

	if (!sphere)
		sphere = (t_object *)semalloc(sizeof(t_object));
	sphere->type = SPHERE;
	e->nbline++;
	if (get_next_line(e->fd, &option) == 1 && option[0] == ' ')
	{
		option = trim_option(e, option, &option_arg);
		if (!ft_strcmp("origin", option))
			sphere->origin = set_vector(e, option_arg);
		else if (!ft_strcmp("radius", option))
			sphere->radius = ft_atoi(option_arg);
		else if (!ft_strcmp("color", option))
			sphere->color = set_color(e, option_arg);
		else
			unknown_option(option, e->nbline, "sphere");
		free(option);
		set_sphere(e);
	}
	else
	{
		set_first_obj(e, sphere);
		sphere = NULL;
		dispatch(e, option);
	}
}

void		set_plane(t_env *e)
{
	static t_object		*plane;
	char				*option;
	char				*option_arg;

	if (!plane)
		plane = (t_object *)semalloc(sizeof(t_object));
	plane->type = PLANE;
	e->nbline++;
	if (get_next_line(e->fd, &option) == 1 && option[0] == ' ')
	{
		option = trim_option(e, option, &option_arg);
		if (!ft_strcmp("origin", option))
			plane->origin = set_vector(e, option_arg);
		else if (!ft_strcmp("normal", option))
			plane->normal = set_vector(e, option_arg);
		else if (!ft_strcmp("color", option))
			plane->color = set_color(e, option_arg);
		else
			unknown_option(option, e->nbline, "plane");
		free(option);
		set_plane(e);
	}
	else
	{
		set_first_obj(e, plane);
		plane = NULL;
		dispatch(e, option);
	}
}

void		set_cylinder(t_env *e)
{
	static t_object		*cylinder;
	char				*option;
	char				*option_arg;

	if (!cylinder)
		cylinder = (t_object *)semalloc(sizeof(t_object));
	cylinder->type = CYLINDER;
	e->nbline++;
	if (get_next_line(e->fd, &option) == 1 && option[0] == ' ')
	{
		option = trim_option(e, option, &option_arg);
		if (!ft_strcmp("origin", option))
			cylinder->origin = set_vector(e, option_arg);
		else if(!ft_strcmp("normal", option))
			cylinder->normal = set_vector(e, option_arg);
		else if (!ft_strcmp("radius", option))
			cylinder->radius = ft_atoi(option_arg);
		else if (!ft_strcmp("color", option))
			cylinder->color = set_color(e, option_arg);
		else
			unknown_option(option, e->nbline, "sphere");
		free(option);
		set_cylinder(e);
	}
	else
	{
		cylinder->normal = normalize(vec_ope_min(cylinder->origin, cylinder->normal));
		set_first_obj(e, cylinder);
		cylinder = NULL;
		dispatch(e, option);
	}
}

void		set_cone(t_env *e)
{
	static t_object		*cone;
	char				*option;
	char				*option_arg;

	if (!cone)
		cone = (t_object *)semalloc(sizeof(t_object));
	cone->type = CONE;
	e->nbline++;
	if (get_next_line(e->fd, &option) == 1 && option[0] == ' ')
	{
		option = trim_option(e, option, &option_arg);
		if (!ft_strcmp("normal", option))
			cone->normal = set_vector(e, option_arg);
		else if(!ft_strcmp("origin", option))
			cone->origin = set_vector(e, option_arg);
		else if (!ft_strcmp("radius", option))
			cone->radius = ft_atoi(option_arg);
		else if (!ft_strcmp("color", option))
			cone->color = set_color(e, option_arg);
		else
			unknown_option(option, e->nbline, "cone");
		free(option);
		set_cone(e);
	}
	else
	{
		set_first_obj(e, cone);
		cone->normal = normalize(cone->normal);
		cone = NULL;
		dispatch(e, option);
	}
}