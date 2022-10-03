#include "parser_.h"

void	ft_set_material(t_object *object, char **tokens, int index)
{
	object->material.difuse = 0.5;
	object->material.specular = 0.6;
	object->material.shininess = 32;
	if (tokens[index] == NULL)
		return ;
	object->material.difuse = ft_stod(tokens[index++]);
	if (tokens[index] == NULL)
		return ;
	object->material.specular = ft_stod(tokens[index++]);
	if (tokens[index] == NULL)
		return ;
	object->material.shininess = ft_stod(tokens[index++]);
}

int	parseSphere(char **tokens, t__data *data)
{
	int			size;
	t_object*	object;

	size = ft_arr_size(tokens);
	if (size < 4 || size > 7)
		return (invalid_argements("sphere"), 0);
	object = malloc(sizeof(t_object));
	if (!object)
		return (errno = 1, 0);
	object->position = get_position_point(tokens[1]);
	object->color = to_color(get_color(tokens[3]));
	object->type = E_SPHERE;
	object->sphere.diameter = ft_stod(tokens[2]);
	ft_set_material(object, tokens, 4);
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
		invalid_argements("sphere");
	return (0);
}
