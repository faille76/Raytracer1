/*
** normal_cylindre.c for normal cylindre in /src/rt/normal/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 17:11:16 2016 Frederic ODDOU
** Last update Fri Mar 11 17:11:16 2016 Frederic ODDOU
*/

#include "rtv1.h"

t_vec		normal_cylindre(t_vec_oeil pt, t_kmin *k)
{
  t_vec		normale;

  normale.x = pt.x - (double)k->obj->x;
  normale.y = pt.y - (double)k->obj->y;
  normale.z = -k->obj->ray;
  return (normale);
}
