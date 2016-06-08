/*
** my_putnbr.c for putnbr in /lib/fonctions/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb  2 13:26:06 2016 Frederic ODDOU
** Last update Tue Feb  2 13:26:06 2016 Frederic ODDOU
*/

#include "lib.h"

int	my_putnbr(int nbr)
{
  int	pow;
  int	i;

  pow = 1;
  i = 0;
  if (nbr == -2147483648)
    i += my_putstr("-2147483648");
  else
    {
      if (nbr < 0)
	{
	  i += my_putchar('-');
	  nbr = -(nbr);
	}
      while ((nbr / pow) >= 10)
	pow *= 10;
      while (pow > 0)
	{
	  i += my_putchar(((nbr / pow) % 10) + '0');
	  pow /= 10;
	}
    }
  return (i);
}
