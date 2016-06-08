/*
** take_nb_arg_from_ini.c for take_nb_arg_from_ini in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb 23 13:31:55 2016 Frederic ODDOU
** Last update Tue Feb 23 13:31:55 2016 Frederic ODDOU
*/

#include <lapin.h>

int		take_nb_arg_from_ini(t_bunny_ini *ini,
				     char *name,
				     char *type)
{
  int		i;
  const char	*str;

  i = 0;
  while ((str = bunny_ini_get_field(ini, name, type, i)) != NULL)
    i++;
  return (i);
}
