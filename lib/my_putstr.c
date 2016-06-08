/*
** my_putstr.c for put str in /lib/fonctions/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb  2 13:21:15 2016 Frederic ODDOU
** Last update Tue Feb  2 13:21:15 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include "lib.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}
