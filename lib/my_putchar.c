/*
** my_putchar.c for putchar in /lib/fonctions/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb  2 13:20:34 2016 Frederic ODDOU
** Last update Tue Feb  2 13:20:34 2016 Frederic ODDOU
*/

#include <unistd.h>

int	my_putchar(int c)
{
  return (write(1, &c, 1));
}
