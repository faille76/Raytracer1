/*
** normal_parabol.c for normal parabol in /src/rt/normal/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 17:13:02 2016 Frederic ODDOU
** Last update Wed Jun  8 22:22:16 2016 oddou_f
*/

#include "rtv1.h"

t_vec		normal_parabol(t_vec_oeil pt, t_kmin *k)
{
  t_vec		normale;

  (void)k;
  normale.x = -pt.x;
  normale.y = -pt.y;
  normale.z = -pt.z;
  return (normale);
}
