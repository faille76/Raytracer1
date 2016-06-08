/*
** normal_cone.c for normal cone in /src/rt/normal/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 17:12:31 2016 Frederic ODDOU
** Last update Fri Mar 11 17:12:31 2016 Frederic ODDOU
*/

#include "rtv1.h"

t_vec		normal_cone(t_vec_oeil pt, t_kmin *k)
{
  t_vec		normale;

  normale.x = pt.x - (double)k->obj->x;
  normale.y = pt.y - (double)k->obj->y;
  normale.z = (pt.z - (double)k->obj->z) * (-0.5);
  return (normale);
}
