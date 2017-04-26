/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/04/26 17:27:49 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color     *compute_color_cylinder(t_env *e, t_vector poi, t_object cylinder)
{
    t_color     *color;

    color = malloc(200);
    (void)poi;
	(void)cylinder;
	(void)e;
	color->r = 0;
	color->g = 0;
	color->b = 200;
	return (color);
}

double      intersect_cylinder(t_ray ray, t_object cylinder)
{
    double          a;
    double          b;
    double          c;
    float		    det;
    float           t0;
    float           t1;
    a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
    b = 2 * (cylinder.origin.x * ray.direction.x) + 2 * (cylinder.origin.z * ray.direction.z);
   c = ray.origin.x * ray.origin.x + ray.origin.y * ray.origin.y + 
        cylinder.origin.x * cylinder.origin.x +
        cylinder.origin.y * cylinder.origin.y - 
        cylinder.radius * cylinder.radius - 
        2 * (ray.origin.x * cylinder.origin.x
			+ ray.origin.y * cylinder.origin.y);
   // c = pow(cylinder.origin.x, 2) + pow(cylinder.origin.z, 2) - 1/*pow(cylinder.radius, 2)*/;
    det = b * b - 4 * a * c;
    t0 = 0;t1 = 0;
    if (det >= 0)
    {
        det = sqrt(det);
        t0 = (-b - det) / (2 * a);
        t1 = (-b + det) / (2 * a);
        ft_putchar('\n');
        ft_putnbr(t0);
        if (t0 > t1 && t1 > 0)
            return t1;
        else
         return (t0);
    }
    
  //  ft_putnbr(t0);
    //ft_putchar('T');
   // ft_putnbr(t1);
   // ft_putchar('\n');
   /* y0 = cylinder.direction.y + t0 * ray.direction.y;
    y1 = cylinder.direction.y + t1 * ray.direction.y;
    f++;
    ft_putchar('\n');
    ft_putnbr(f);
    if(y0 < -1)
    {
        if(y1 < -1)
            return(DIST_MAX);
         temp = t0 + (t1 -t0) * (y0 + 1) / (y0 - y1);
         if(temp <= 0)
            return(DIST_MAX);
         return (temp);
       
    }
    if(y0 >= -1 && y0 <= 1)
    {
        if(t0 <= 0)
          return (DIST_MAX);
        return (t0); 
    }
    if(y0 > 1)
    {
        if(y1 > 1)
          return (DIST_MAX);
         temp = t0 + (t1 -t0) * (y0 + 1) / (y0 - y1);
         if(temp <= 0)
            return(DIST_MAX);
         return (temp);
    }
    return (DIST_MAX);*/
    return DIST_MAX;
}