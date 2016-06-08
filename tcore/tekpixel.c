/*
** tekpixel.c for tekpixel in /tcore/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 19:15:27 2016 Frederic ODDOU
** Last update Fri Mar 11 19:15:27 2016 Frederic ODDOU
*/

#include <lapin.h>

void    tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 t_color		*color)
{
  int   w;
  int	h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    (((t_color*)pix->pixels)[w * pos->y + pos->x]).full = color->full;
}
