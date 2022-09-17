#include "raytracer.h"

void	ft_look_inters(t_list *head, t_ray ray, t_info *info)
{
	t_object	obj;

	while (head)
	{
		obj = lst_object(head);
		if (obj.type == E_SPHERE)
			ft_solve_sphere(ray, obj, info);
		else if (obj.type == E_CYLINDER)
			cylinder_intersect(obj, ray, info);
		else if (obj.type == E_PLANE)
			ft_solve_plane(ray, obj, info);
		head = head->next;
	}
}


static void	per_pixel(const t_pair pair, t_canvas canvas, t_vcamera vcamera, t__data *data)
{
	t_ray		ray;
	t_info		info;
	t_tuple		viewDir;

	init_info(&info);
	ray = ft_setray(vcamera, pair);
	ft_look_inters(data->objects, ray, &info);
	viewDir = normalize(subst_tuple(vcamera.origin, info.point));
	if (info.t > 0)
		ft_shading(data, &info, viewDir);
	ft_write_pixel(canvas, pair.x, pair.y, info.color);
}

void	render(t__data *data)
{
	t_canvas	canvas;
	t_pair		pair;
	t_vcamera	vcamera;

	(void)data;
	pair = (t_pair){{0, 0}};
	canvas = ft_canvas(WIDTH, HEIGHT);
	vcamera = ft_setup_camera(data->camera);
	print_camera(vcamera);
	while (pair.y < HEIGHT)
	{
		pair.x = 0;
		while (pair.x < WIDTH)
		{
			per_pixel(pair, canvas, vcamera, data);
			pair.x++;
		}
		pair.y++;
	}
	ft_show_canvas(canvas);
	mlx_loop(canvas.mlx_ptr);
}
