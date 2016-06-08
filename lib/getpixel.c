/*
** getpixel.c for getpixel in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Mon Jan 18 13:18:15 2016 oddou_f
** Last update Mon Jan 18 13:44:23 2016 oddou_f
*/

#include <lapin.h>

t_color         getpixel(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color       color;
  int           w;
  int           h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    color.full = (((t_color*)pix->pixels)[w * pos->y + pos->x]).full;
  else
    color.full = BLACK;
  return (color);
}
