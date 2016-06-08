/*
** calc_parabol.c for calc parabol in /src/rt/calc_objs/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 23:40:43 2016 Frederic ODDOU
** Last update Sat Feb 13 23:40:43 2016 Frederic ODDOU
*/

#include <math.h>
#include "rtv1.h"

void		calc_parabol(t_vec vec,
			     t_kmin *k_min,
			     t_objs *obj,
			     t_vec_oeil view)
{
  t_delta	delta;
  double	k[2];

  movement(&view, obj, &vec);
  delta.a = pow(vec.x, 2) + pow(vec.y, 2);
  delta.b = 2.0 * ((view.x * vec.x) + (view.y * vec.y) - (obj->ray * vec.z));
  delta.c = (pow(view.x, 2) + pow(view.y, 2) - (obj->ray * view.z));
  delta.delta = pow(delta.b, 2) - 4 * delta.a * delta.c;
  if (delta.delta > 0)
    {
      k[0] = (-delta.b - sqrt(delta.delta)) / (2 * delta.a);
      k[1] = (-delta.b + sqrt(delta.delta)) / (2 * delta.a);
      if (k[0] <= k[1] && k[0] >= 0)
	rt_kmin_change(k_min, k[0], obj);
      else if (k[1] >= 0)
	rt_kmin_change(k_min, k[1], obj);
    }
}
