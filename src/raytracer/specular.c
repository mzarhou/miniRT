#include "raytracer.h"

static t_tuple	ft_reflect(t_shader *shader, t_info *info)
{
	t_tuple	reflect;
	float	d;

	d = ft_cos(shader->light_vect, info->normal);
	reflect = multiply_tuple(info->normal, 2 * d);
	reflect = subst_tuple(reflect, shader->light_vect);
	reflect = normalize(reflect);
	return (reflect);
}

static float	ft_scaler(t_tuple reflect, t_tuple view)
{
	float	scaler;
	float	specular_strenght;
	float	n;

	specular_strenght = 0.5;
	n = 128;
	scaler = pow(ft_cos(reflect, view), n);
	return (specular_strenght * scaler);
}

t_color	ft_specular(t_shader *shader, t_info *info, t_tuple view)
{
	t_color	specular;
	t_tuple	reflect;
	float	ratio;

	reflect = ft_reflect(shader, info);
	ratio = ft_scaler(reflect, view);
	specular = ft_merge_color(info->color, shader->light_color, ratio);
	return (specular);
}
