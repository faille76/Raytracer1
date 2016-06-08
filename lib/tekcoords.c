/*
** tekcoords.c for tek coords in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Dec  6 01:13:53 2015 Frederic ODDOU
** Last update Mon Dec  7 21:42:34 2015 Frederic ODDOU
*/

#include <lapin.h>
#include <stdlib.h>

t_bunny_position	*tekcoords(int x1, int y1, int x2, int y2)
{
  t_bunny_position 	*ptmp;

  if ((ptmp = bunny_malloc(2 * sizeof(*ptmp))) == NULL)
    return (NULL);
  ptmp[0].x = x1;
  ptmp[0].y = y1;
  ptmp[1].x = x2;
  ptmp[1].y = y2;
  return (ptmp);
}
