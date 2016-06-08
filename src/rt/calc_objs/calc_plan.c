/*
** calc_plan.c for calc plan in /src/rt/calc_objs/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 23:41:37 2016 Frederic ODDOU
** Last update Sat Feb 13 23:41:37 2016 Frederic ODDOU
*/

#include "rtv1.h"

void		calc_plan(t_vec vec,
			  t_kmin *k_min,
			  t_objs *obj,
			  t_vec_oeil view)
{
  double	k;

  movement(&view, obj, &vec);
  if (vec.z <= 0 || vec.z >= 0)
    {
      k = -(view.z / vec.z);
      if (k >= 0)
	rt_kmin_change(k_min, k, obj);
    }
}
