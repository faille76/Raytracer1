/*
** take_int_from_ini.c for take int from ini in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Feb  4 16:08:29 2016 Frederic ODDOU
** Last update Thu Feb  4 16:08:29 2016 Frederic ODDOU
*/

#include <lapin.h>
#include <stdlib.h>
#include "lib.h"

int			take_int_from_ini(t_bunny_ini *ini,
					  char *name,
					  char *type,
					  int pos)
{
  const char		*str;

  if ((str = bunny_ini_get_field(ini, name, type, pos)) == NULL)
    return (0);
  else
    return (my_getnbr((char *)str));
}
