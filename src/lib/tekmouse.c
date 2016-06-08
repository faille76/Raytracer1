/*
** tekmouse.c for tekmouse in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Feb  4 23:36:11 2016 Frederic ODDOU
** Last update Thu Feb  4 23:36:11 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

int			tekmouse(t_bunny_position *start,
				 t_bunny_position *end)
{
  t_bunny_position	pos;
  t_bunny_position	*mouse;

  pos.x = start->x;
  mouse = (t_bunny_position *)bunny_get_mouse_position();
  while (pos.x < end->x)
    {
      pos.y = start->y;
      while (pos.y < end->y)
	{
	  if (pos.x == mouse->x && pos.y == mouse->y)
	    return (0);
	  pos.y += 1;
	}
      pos.x += 1;
    }
  return (1);
}
