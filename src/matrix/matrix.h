#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include "tuple.h"
# include <stdint.h>
# include <math.h>
# include <stdarg.h>

# define IDENTITY_MATRIX (t_matrix){{ \
	1, 0, 0, 0, \
	0, 1, 0, 0, \
	0, 0, 1, 0, \
	0, 0, 0, 1  \
}}

typedef union u_matrix t_matrix;
union u_matrix
{
	struct
	{
		double	r0_c0;
		double	r0_c1;
		double	r0_c2;
		double	r0_c3;

		double	r1_c0;
		double	r1_c1;
		double	r1_c2;
		double	r1_c3;

		double	r2_c0;
		double	r2_c1;
		double	r2_c2;
		double	r2_c3;

		double	r3_c0;
		double	r3_c1;
		double	r3_c2;
		double	r3_c3;
	};
	double raw[4][4];
};

t_tuple		get_col(t_matrix t, uint8_t col);
t_tuple		get_row(t_matrix t, uint8_t row);
t_matrix	matrix_multiply(t_matrix mt1, t_matrix mt2);
bool		matrix_equal(t_matrix mt1, t_matrix mt2);
void		print_matrix(t_matrix mt);
t_tuple		matrix_tuple_multiply(t_matrix mt, t_tuple t);
t_matrix	ft_transpose(t_matrix mt);
t_matrix	inverse(t_matrix mtx);

t_matrix	translate(double x, double y, double z);
t_matrix	scale(double x, double y, double z);
t_matrix	rotate_x(double radians);
t_matrix	rotate_y(double radians);
t_matrix	rotate_z(double radians);
t_matrix	transforms(int count, ...);
#endif
