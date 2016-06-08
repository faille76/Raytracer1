/*
** get_view.c for get view in /src/get_from_ini/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Mar  3 22:29:51 2016 Frederic ODDOU
** Last update Thu Mar  3 22:29:51 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

void	get_view(t_rt *rt, t_bunny_ini *ini)
{
  rt->vec_oeil.x = take_double_from_ini(ini, "view", "pos_x", 0);
  rt->vec_oeil.y = take_double_from_ini(ini, "view", "pos_y", 0);
  rt->vec_oeil.z = take_double_from_ini(ini, "view", "pos_z", 0);
  rt->vec_oeil.x_r = take_double_from_ini(ini, "view", "rot_x", 0);
  rt->vec_oeil.y_r = take_double_from_ini(ini, "view", "rot_y", 0);
  rt->vec_oeil.z_r = take_double_from_ini(ini, "view", "rot_z", 0);
}
