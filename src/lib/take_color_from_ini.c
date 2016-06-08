/*
** take_color_from_ini.c for take color from ini in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Feb  4 23:48:57 2016 Frederic ODDOU
** Last update Thu Feb  4 23:48:57 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

void			take_color_from_ini(t_color *color,
					    t_bunny_ini *ini,
					    char *name,
					    char *title)
{
  color->argb[0] = take_int_from_ini(ini, name, title, 0);
  color->argb[1] = take_int_from_ini(ini, name, title, 1);
  color->argb[2] = take_int_from_ini(ini, name, title, 2);
}
