/*
** rt_normal.c for normal in /src/rt/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 21:50:11 2016 Frederic ODDOU
** Last update Sat Feb 13 21:50:11 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include <math.h>
#include "rtv1.h"

void		rt_calc_normal(t_vec	*vec)
{
  double	norme;

  norme = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
  vec->x /= norme;
  vec->y /= norme;
  vec->z /= norme;
}

void		rt_normal(t_data 	*data,
			  t_vec_oeil	pt,
			  double	*k_tmp,
			  t_vec		*vec_dir)
{
  t_vec		normale;

  normale = data->fptr_objs[data->k_min->obj->forme].norm(pt, data->k_min);
  rt_calc_normal(&normale);
  rt_calc_normal(vec_dir);
  *k_tmp = (normale.x * vec_dir->x) + (normale.y * vec_dir->y)
      + (normale.z * vec_dir->z);
  if (*k_tmp < 0)
    *k_tmp = 0;
}
