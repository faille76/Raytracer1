/*
** rt_free.c for rt free in /src/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 18:54:41 2016 Frederic ODDOU
** Last update Fri Mar 11 18:54:41 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "rtv1.h"

void			rt_free(t_rt *rt)
{
  t_objs		*tmp_objs;
  t_light		*tmp_light;

  tmp_objs = rt->list;
  tmp_light = rt->light;
  while (rt->list != NULL)
    {
      rt->list = rt->list->next;
      bunny_free(tmp_objs);
      tmp_objs = rt->list;
    }
  if (tmp_objs != NULL)
    bunny_free(tmp_objs);
  while (rt->light != NULL)
    {
      rt->light = rt->light->next;
      bunny_free(tmp_light);
      tmp_light = rt->light;
    }
  if (tmp_light != NULL)
    bunny_free(tmp_light);
}
