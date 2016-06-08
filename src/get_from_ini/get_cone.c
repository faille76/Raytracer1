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

t_objs		*get_cone(t_bunny_ini *ini, t_objs *list)
{
  const char	*str;
  int		i;

  i = 0;
  while ((str = bunny_ini_get_field(ini, "list", "cone", i)) != NULL)
    {
      list = get_obj_ini(ini, list, (char *)str, CONE_VAL);
      i++;
    }
  return (list);
}
