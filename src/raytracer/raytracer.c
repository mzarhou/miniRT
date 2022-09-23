#include "raytracer.h"
#include <stdarg.h>
#include <stdlib.h>
#include "utils.h"
#include "pair.h"

t_inter	ft_hit(t_xs xs)
{
	t_inter	inter;
	t_inter	visible_inter;
	int		i;

	visible_inter = (t_inter){-1, { .type = E_INVALID }};
	i = -1;
	while (++i < xs.count)
	{
		inter = xs.inters[i];
		if (inter.t > 0 && (visible_inter.t < 0 || inter.t < visible_inter.t))
			visible_inter = inter;
	}
	return (visible_inter);
}

t_xs	intersect(t_object object, t_ray ray)
{
	t_xs	xs;

	xs = (t_xs){0, NULL};

	ray = ray_transform(ray, inverse(object.transform));
	if (object.type == E_SPHERE)
		xs = local_sphere_intersect(object, ray);
	else if (object.type == E_PLANE)
		xs = local_plane_intersect(object, ray);
	else if (object.type == E_CYLINDER)
		xs = local_cylinder_intersect(object, ray);
	else if (object.type == E_CONE)
		xs = local_cone_intersect(object, ray);
	else {
		printf("object type undefined -> %c [intersect]\n", object.type);
	}
	return (xs);
}

t_tuple	normal_at(t_object object, t_tuple p)
{
	t_tuple normal;

	normal = vector(0, 0, 0);
	p = matrix_tuple_multiply(object.inverted_transform, p);
	if (object.type == E_SPHERE) {
		normal = local_sphere_normal(p);
	} else if (object.type == E_PLANE) {
		normal = local_plane_normal(p);
	} else if (object.type == E_CYLINDER) {
		normal = local_cylinder_normal(p);
	} else if (object.type == E_CONE) {
		normal = local_cone_normal(p);
	} else {
		printf("object type undefined -> %c [normal_at]\n", object.type);
		return (normal);
	}
	normal = matrix_tuple_multiply(object.transpose_matrix, normal);
	normal.w = 0;
	return (normalize(normal));
}
