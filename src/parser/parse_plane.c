#include "parser_.h"

void	parsePlane(char **tokens, t__data *data)
{
	t_object	*object;

	if (ft_arr_size(tokens) != 4)
		invalid_argements("plane");
	object = malloc(sizeof(t_object));
	object->position = get_position_point(tokens[1]);
	object->color = get_color(tokens[3]);
	object->type = E_PLANE;
	object->plane.orientation = get_orientation_vect3(tokens[2]);
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("plane");
	}
}
