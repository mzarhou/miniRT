/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_lightning.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:22:04 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:22:32 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

int	parse_amblightning(char **tokens, t__data *data)
{
	static int	count = 0;

	if (count++)
		return (multiple_elm("A"), 0);
	if (ft_arr_size(tokens) != 3)
		return (invalid_argements("Ambient lightning"), 0);
	data->ambient.ratio = get_ratio(tokens[1]);
	data->ambient.color = to_color(get_color(tokens[2]));
	if (errno)
		invalid_argements("Ambient lightning");
	return (0);
}
