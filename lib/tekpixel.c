/*
** tekpixel.c for tekpixel in /lib/
**
** Made by John Doe
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Jan 31 22:55:09 2016 John Doe
** Last update Sun Jan 31 22:55:09 2016 John Doe
*/

#include <lapin.h>

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int   w;
  int	h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    (((t_color*)pix->pixels)[w * pos->y + pos->x]).full = color->full;
}
