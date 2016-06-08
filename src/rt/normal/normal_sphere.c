/*
** normal_sphere.c for normal sphere in /src/rt/normal/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 17:10:44 2016 Frederic ODDOU
** Last update Fri Mar 11 17:10:44 2016 Frederic ODDOU
*/

#include "rtv1.h"

t_vec		normal_sphere(t_vec_oeil pt, t_kmin *k)
{
  t_vec		normale;

  normale.x = pt.x - (double)k->obj->x;
  normale.y = pt.y - (double)k->obj->y;
  normale.z = pt.z - (double)k->obj->z;
  return (normale);
}
