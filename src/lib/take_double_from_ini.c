/*
** take_double_from_ini.c for take_double_from_ini in /src/lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar  4 12:36:16 2016 Frederic ODDOU
** Last update Fri Mar  4 12:36:16 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

double			take_double_from_ini(t_bunny_ini *ini,
					     char *name,
					     char *type,
					     int pos)
{
  const char		*str;

  if ((str = bunny_ini_get_field(ini, name, type, pos)) == NULL)
    return (0);
  else
    return (my_atoi((char *)str));
}
