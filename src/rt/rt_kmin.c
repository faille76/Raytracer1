/*
** rt_kmin.c for rt kmin in /src/rt/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Mar 10 12:54:13 2016 Frederic ODDOU
** Last update Thu Mar 10 12:54:13 2016 Frederic ODDOU
*/

#include	<stdlib.h>
#include	"rtv1.h"

int		rt_kmin_change(t_kmin 		*elem,
			       double 		k,
			       t_objs 		*obj)
{
  if (elem->k != -1)
    {
      if (k > (double)0 && k < elem->k)
	{
	  elem->k = k;
	  elem->color = obj->color;
	  elem->obj = obj;
	}
    }
  else
    {
      elem->k = k;
      elem->color = obj->color;
      elem->obj = obj;
    }
  return (0);
}

void			rt_kmin_init(t_kmin	*k_min)
{
  k_min->k = -1;
  (k_min->color).full = 0;
  k_min->obj = NULL;
}
