/*
** my_getnbr.c for getnbr in /lib/fonctions/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb  2 13:23:21 2016 Frederic ODDOU
** Last update Tue Feb  2 13:23:21 2016 Frederic ODDOU
*/

#include <stdlib.h>

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 0;
  if (str == NULL)
    return (0);
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i++;
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      nbr = (nbr * 10) + (str[i] - '0');
      i++;
    }
  return (nbr);
}
