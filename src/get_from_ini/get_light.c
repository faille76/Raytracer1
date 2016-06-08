/*
** get_plan.c for get plan in /src/get_from_ini/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar  4 12:38:21 2016 Frederic ODDOU
** Last update Fri Mar  4 12:38:21 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"
#include "get_ini.h"

t_light		*get_light_ini(t_bunny_ini *ini,
			       t_light *light,
			       char *name)
{
  t_light	*elem;

  if ((elem = bunny_malloc(sizeof(t_light))) == NULL)
    return (NULL);
  elem->x = take_double_from_ini(ini, name, "pos_x", 0);
  elem->y = take_double_from_ini(ini, name, "pos_y", 0);
  elem->z = take_double_from_ini(ini, name, "pos_z", 0);
  elem->b_r = take_double_from_ini(ini, name, "color", 0);
  elem->b_g = take_double_from_ini(ini, name, "color", 1);
  elem->b_b = take_double_from_ini(ini, name, "color", 2);
  elem->next = light;
  return (elem);
}

void		get_light(t_bunny_ini *ini, t_rt *rt)
{
  const char	*str;

  rt->nb_light = 0;
  while ((str = bunny_ini_get_field(ini, "list", "light", rt->nb_light))
	 != NULL)
    {
      rt->light = get_light_ini(ini, rt->light, (char *)str);
      rt->nb_light++;
    }
}
