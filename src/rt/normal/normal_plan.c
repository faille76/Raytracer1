/*
** normal_plan.c for normal plan in /src/rt/normal/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 17:10:10 2016 Frederic ODDOU
** Last update Fri Mar 11 17:10:10 2016 Frederic ODDOU
*/

#include "rtv1.h"

t_vec		normal_plan(t_vec_oeil 		pt,
			    t_kmin 		*k)
{
  t_vec		normale;

  (void)pt;
  normale.x = 0.0;
  normale.y = 0.0;
  normale.z = 100.0;
  rotation_x(&normale.y, &normale.z, D_R(k->obj->x_r));
  rotation_y(&normale.x, &normale.z, D_R(k->obj->y_r));
  rotation_z(&normale.x, &normale.y, D_R(k->obj->z_r));
  normale.z = normale.z - (double)k->obj->z;
  return (normale);
}
