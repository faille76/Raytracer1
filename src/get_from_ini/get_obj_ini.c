/*
** get_obj_ini.c for get_obj_ini in /src/get_from_ini/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar  4 12:55:14 2016 Frederic ODDOU
** Last update Fri Mar  4 12:55:14 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

t_objs		*get_obj_ini(t_bunny_ini *ini,
			     t_objs *list,
			     char *name,
			     int val)
{
  t_objs	*elem;

  if ((elem = bunny_malloc(sizeof(t_objs))) == NULL)
    return (NULL);
  elem->forme = val;
  elem->x = take_double_from_ini(ini, name, "pos_x", 0);
  elem->y = take_double_from_ini(ini, name, "pos_y", 0);
  elem->z = take_double_from_ini(ini, name, "pos_z", 0);
  elem->ray = take_double_from_ini(ini, name, "rayon", 0);
  elem->x_r = take_double_from_ini(ini, name, "rot_x", 0);
  elem->y_r = take_double_from_ini(ini, name, "rot_y", 0);
  elem->z_r = take_double_from_ini(ini, name, "rot_z", 0);
  elem->bri = take_double_from_ini(ini, name, "brillance", 0);
  take_color_from_ini(&elem->color, ini, name, "color");
  elem->next = list;
  return (elem);
}
