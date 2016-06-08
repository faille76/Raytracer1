/*
** my_strdup.c for strdup in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb  2 18:49:49 2016 Frederic ODDOU
** Last update Tue Feb  2 18:49:49 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include <lapin.h>
#include "lib.h"

char		*my_strdup(char *str)
{
  int		i;
  char		*new;

  i = 0;
  if ((new = bunny_malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
