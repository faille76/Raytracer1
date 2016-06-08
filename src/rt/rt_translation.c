/*
** translation.c for translation in /src/rt/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 21:51:07 2016 Frederic ODDOU
** Last update Sat Feb 13 21:51:07 2016 Frederic ODDOU
*/

#include	<math.h>
#include	"rtv1.h"

void		translation(t_vec_oeil		*view,
			    t_objs		*forme)
{
  view->x = view->x - forme->x;
  view->y = view->y - forme->y;
  view->z = view->z - forme->z;
}

void		rotation_x(double		*y,
			   double 		*z,
			   double 		angle)
{
  double	tmp_y;

  tmp_y = *y;
  *y = ((*y) * cos(angle)) + ((*z) * -(sin(angle)));
  *z = (tmp_y * sin(angle)) + ((*z) * cos(angle));
}

void		rotation_y(double		*x,
			   double		*z,
			   double		angle)
{
  double	tmp_x;

  tmp_x = *x;
  *x = ((*x) * cos(angle)) + ((*z) * sin(angle));
  *z = (-(sin(angle)) * tmp_x) + (cos(angle) * (*z));
}

void		rotation_z(double		*x,
			   double		*y,
			   double		angle)
{
  double	tmp_x;

  tmp_x = *x;
  *x = ((*x) * cos(angle)) + ((*y) * -(sin(angle)));
  *y = (tmp_x * sin(angle)) + ((*y) * cos(angle));
}

void		movement(t_vec_oeil		*view,
			 t_objs			*forme,
			 t_vec			*vec)
{
  rotation_x(&(vec->y), &(vec->z), D_R(forme->x_r));
  rotation_x(&(view->y), &(view->z), D_R(forme->x_r));
  rotation_y(&(vec->x), &(vec->z), D_R(forme->y_r));
  rotation_y(&(view->x), &(view->z), D_R(forme->y_r));
  rotation_z(&(vec->x), &(vec->y), D_R(forme->z_r));
  rotation_z(&(view->x), &(view->y), D_R(forme->z_r));
  translation(view, forme);
}
