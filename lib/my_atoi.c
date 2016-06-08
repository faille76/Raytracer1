/*
** my_atoi.c for atoi in /lib/fonctions/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb  2 13:25:19 2016 Frederic ODDOU
** Last update Tue Feb  2 13:25:19 2016 Frederic ODDOU
*/

#include <stdlib.h>

float	my_atoi_float(char *str, float nbr)
{
  int	i;
  int	pow;

  i = 0;
  pow = 1;
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      nbr = (nbr * 10) + (str[i] - '0');
      pow *= 10;
      i++;
    }
  return (nbr / pow);
}

float	my_atoi(char *str)
{
  int	i;
  float	nbr;
  int	neg;

  i = 0;
  nbr = 0;
  neg = 0;
  if (str == NULL)
    return (0);
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    {
      if (str[i] == '-')
	neg++;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      nbr = (nbr * 10) + (str[i] - '0');
      i++;
    }
  if (str[i] == '.')
    nbr = my_atoi_float(&str[i + 1], nbr);
  if (neg % 2 == 1)
    nbr = -(nbr);
  return (nbr);
}
