/*
** cpy_pix.c for cpy pix in /src/lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Mar 12 17:40:56 2016 Frederic ODDOU
** Last update Sat Mar 12 17:40:56 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

void			cpy_pix(t_bunny_pixelarray *pix1,
				t_bunny_pixelarray *pix2)
{
  t_bunny_position	pos;
  t_color		color;

  pos.x = 0;
  pos.y = 0;
  while (pos.x < WIDTH)
    {
      pos.y = 0;
      while (pos.y < HEIGHT)
	{
	  color = getpixel(pix2, &pos);
	  tekpixel(pix1, &pos, &color);
	  pos.y++;
	}
      pos.x++;
    }
}
