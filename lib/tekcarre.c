/*
** tekcarre.c for aff carre in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Mon Dec 28 21:08:38 2015 Frederic ODDOU
** Last update Mon Dec 28 21:08:38 2015 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

void			tekcarre(t_bunny_pixelarray *pix,
				 t_bunny_position *pos1,
				 unsigned int col,
				 int taille)
{
  t_bunny_position	pos2;
  t_color		color;
  int			y;
  int			i;
  int			ix;

  color.full = col;
  y = pos1->y;
  i = 0;
  while (y < pos1->y + taille)
    {
      ix = 0;
      while (ix < taille)
	{
	  pos2.x = pos1->x + ix;
	  pos2.y = pos1->y + i;
	  tekpixel(pix, &pos2, &color);
	  ix++;
	}
      i++;
      y++;
    }
}
