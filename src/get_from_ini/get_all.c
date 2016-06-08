/*
** get_all.c for get all in /src/get_from_ini/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Mar  3 22:35:27 2016 Frederic ODDOU
** Last update Thu Mar  3 22:35:27 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"
#include "get_ini.h"

void			get_all(t_rt *rt, char *file)
{
  t_bunny_ini		*ini;

  rt->list = NULL;
  rt->light = NULL;
  if ((ini = bunny_load_ini(file)) == NULL)
    return;
  get_view(rt, ini);
  get_light(ini, rt);
  rt->list = get_plan(ini, rt->list);
  rt->list = get_cone(ini, rt->list);
  rt->list = get_sphere(ini, rt->list);
  rt->list = get_cylindre(ini, rt->list);
  rt->list = get_parabol(ini, rt->list);
  bunny_delete_ini(ini);
}
