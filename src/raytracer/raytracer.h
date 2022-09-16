#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "tuple.h"
# include "canvas.h"
# include "parser_.h"
# include "pair.h"
# include <stdio.h>
# include "list.h"
# include "lst_utils.h"
# include "params.h"
# include "algebra.h"
# include "matrix.h"
# include "params.h"

# define WIDTH 480
# define HEIGHT 480

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_vcamera
{
	t_tuple	origin;
	t_tuple	up;
	t_tuple	right;
	t_tuple	forward;
	float	h;
	float	w;
	float	ar;
}	t_vcamera;

typedef struct s_inter_info
{
	t_color	color;
	t_tuple	point;
	t_tuple	normal;
	float	t;
}	t_info;

typedef struct s_scene t_scene;
struct s_scene
{

};

void		init_info(t_info *info);
void		render(t__data *data);
void		ft_solve_sphere(const t_ray ray, t_object sph_obj, t_info *info);
t_vcamera	ft_setup_camera(const t_camera camera);
void		print_camera(t_vcamera c);
t_ray		ft_setray(const t_vcamera camera, t_pair pair);
void		ft_solve_plane(t_ray ray, t_object obj, t_info *info);
void		ft_look_inters(t_list *head, t_ray ray, t_info *info);
void		ft_shading(t__data *data, t_info *info);
// t_info		ft_lightning(t_light light);

void		cylinder_intersect(t_object obj, t_ray ray, t_info *info);
t_cylinder	ft_cylinder();

t_ray		ray_transform(t_ray ray, t_matrix transformation_matrix);
t_tuple		ft_position(t_ray r, float t);

#endif
