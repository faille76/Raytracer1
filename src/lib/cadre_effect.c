/*
** cadre_effect.c for cadre effect in /src/lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Mar 12 17:46:48 2016 Frederic ODDOU
** Last update Sat Mar 12 17:46:48 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

void			cadre_effect(t_bunny_pixelarray *pix)
{

  t_bunny_position	pos;
  t_color		color;

  color.full = BLACK;
  pos.x = 0;
  pos.y = 0;
  while (pos.x < WIDTH)
    {
      pos.y = 0;
      while (pos.y < HEIGHT)
	{
	  if (pos.x % 2 == (pos.y % 2 ? 1 : 0))
	    tekpixel(pix, &pos, &color);
	  pos.y++;
	}
      pos.x++;
    }
}
