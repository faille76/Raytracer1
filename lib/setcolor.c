/*
** setcolor.c for set bg in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Mon Dec  7 22:19:19 2015 Frederic ODDOU
** Last update Tue Dec 15 17:32:05 2015 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

void			setcolor(t_option *option)
{
  t_bunny_position	pos;
  int			x;
  int			y;

  y = 0;
  while (y < HEIGHT)
    {
      x = 0;
      while (x < WIDTH)
	{
	  pos.x = x;
	  pos.y = y;
	  tekpixel(option->pix, &pos, &option->bg);
      	  x++;
	}
      y++;
    }
}
