/*
** rt_shadow.c for shadow in /src/rt/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 21:50:48 2016 Frederic ODDOU
** Last update Sat Feb 13 21:50:48 2016 Frederic ODDOU
*/

#include	<stdlib.h>
#include	"rtv1.h"

int		rt_shadow(t_data 	*data,
			  t_vec 	*dir,
			  t_vec_oeil 	*pt)
{
  t_objs	*tmp;
  t_kmin	k_min;

  tmp = *data->obj;
  rt_kmin_init(&k_min);
  while (tmp != NULL)
    {
      if (tmp != data->k_min->obj)
	data->fptr_objs[tmp->forme].calc(*dir, &k_min, tmp, *pt);
      tmp = tmp->next;
    }
  if (k_min.k != -1 && k_min.k >= 0 && k_min.k <= 1)
    return (1);
  return (0);
}
