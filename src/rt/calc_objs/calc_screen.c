/*
** calc_screen.c for calc screen in /src/rt/calc_objs/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Mar 10 13:03:39 2016 Frederic ODDOU
** Last update Thu Mar 10 13:03:39 2016 Frederic ODDOU
*/

#include <math.h>
#include "rtv1.h"

t_vec		calc_screen(t_data 		*data,
			    t_bunny_position	pos)
{
  t_vec		vec;

  vec.x = (double)(data->taille.x / 2.0) / tan((25 * M_PI) / 180);
  vec.y = (double)(data->taille.x / 2.0) - (double)pos.x;
  vec.z = (double)(data->taille.y / 2.0) - (double)pos.y;
  rotation_x(&(vec.y), &(vec.z), D_R(data->vec_oeil->x_r));
  rotation_y(&(vec.x), &(vec.z), D_R(data->vec_oeil->y_r));
  rotation_z(&(vec.x), &(vec.y), D_R(data->vec_oeil->z_r));
  return (vec);
}
