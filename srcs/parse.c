/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:20:10 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/09 21:14:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** @todo : take a .rt file as parameter and parse the content into the t_env
*/

t_env	*parse(t_env *e)
{
	t_object	*tmp;

	e->obj = (t_object *)semalloc(sizeof(t_object));
	tmp = e->obj;

	tmp->type = SPHERE;
	tmp->origin = c_vector(0, 0, 300);
	tmp->radius = 20;
	tmp->color = c_color(250, 100, 20);
	tmp->next = (t_object *)semalloc(sizeof(t_object));
	tmp = tmp->next;

	/*tmp->type = PLANE;
	tmp->origin = c_vector(1, 1, 0);
	tmp->direction = c_vector(1, 0, 0);
	tmp->color = c_color(30, 210, 80);
	tmp->next = (t_object *)semalloc(sizeof(t_object));
	tmp = tmp->next;*/
	
	tmp->type = SPHERE;
	tmp->origin = c_vector(-10, -10, 120);
	tmp->radius = 10;
	tmp->color = c_color(10, 160, 20);
	tmp->next = (t_object *)semalloc(sizeof(t_object));
	tmp = tmp->next;

	tmp->type = SPHERE;
	tmp->origin = c_vector(26, -23, 100);
	tmp->radius = 20;
	tmp->color = c_color(255, 255, 51);
	tmp->next = (t_object *)semalloc(sizeof(t_object));
	tmp = tmp->next;

	tmp->type = SPHERE;
	tmp->origin = c_vector(0, 0, 500);
	tmp->radius = 50;
	tmp->color = c_color(100, 50, 180);
	tmp->next = (t_object *)semalloc(sizeof(t_object));
	tmp = tmp->next;

	tmp->type = SPHERE;
	tmp->origin = c_vector(40, 30, 400);
	tmp->radius = 10;
	tmp->color = c_color(140, 25, 58);
	tmp->next = NULL;

	e->camera = c_vector(0, 0, -1);
	e->light = c_vector(800, -800, 1500);
	return (e);
}
