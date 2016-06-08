/*
** antialiasing.c for anti in /src/lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar  4 13:26:09 2016 Frederic ODDOU
** Last update Fri Mar  4 13:26:09 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"

t_color		average_color(t_color a, t_color b, t_color c)
{
  t_color	color;

  color.argb[RED_CMP] = (a.argb[RED_CMP] + b.argb[RED_CMP]
			 + c.argb[RED_CMP]) / 3.0;
  color.argb[GREEN_CMP] = (a.argb[GREEN_CMP] + b.argb[GREEN_CMP]
			   + c.argb[GREEN_CMP]) / 3.0;
  color.argb[BLUE_CMP] = (a.argb[BLUE_CMP] + b.argb[BLUE_CMP]
			  + c.argb[BLUE_CMP]) / 3.0;
  color.argb[ALPHA_CMP] = (a.argb[ALPHA_CMP] + b.argb[ALPHA_CMP]
			   + c.argb[ALPHA_CMP]) / 3.0;
  return (color);
}

t_color			transform_color(t_bunny_pixelarray *pix,
					t_bunny_position *pos)
{
  t_bunny_position      left;
  t_bunny_position      bottom;

  left.x = pos->x + 1;
  left.y = pos->y;
  bottom.x = pos->x;
  bottom.y = pos->y + 1;
  return (average_color(getpixel(pix, pos),
			getpixel(pix, &left),
			getpixel(pix, &bottom)));
}

void			antialiasing(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		moy;
  int			width;
  int			height;

  width = (pix->clipable).clip_width;
  height = (pix->clipable).clip_height;
  pos.x = 0;
  pos.y = 0;
  while (pos.y < height)
    {
      pos.x = 0;
      while (pos.x < width)
	{
	  if (pos.x + 1 < width && pos.y + 1 < height)
	    {
	      moy = transform_color(pix, &pos);
	      tekpixel(pix, &pos, &moy);
	    }
	  pos.x += 1;
	}
      pos.y += 1;
    }
}
