/*
** my_set_line.c for set line in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Nov 13 09:30:54 2015 Frederic ODDOU
** Last update Mon Dec  7 22:13:03 2015 Frederic ODDOU
*/

#include <lapin.h>
#include <stdio.h>
#include "lib.h"

t_color		*tekline_colorconvert(int len, int coord, t_color *color)
{
  int		i;
  float		aug[3];
  t_color	*col;

  i = 1;
  aug[0] = 0;
  aug[1] = 0;
  aug[2] = 0;
  if ((col = bunny_malloc(sizeof(*col))) == NULL)
    return (NULL);
  while (i <= len)
    {
      aug[0] += ((float)color[1].argb[0] - (float)color[0].argb[0])
	  / (float)coord;
      aug[1] += ((float)color[1].argb[1] - (float)color[0].argb[1])
	  / (float)coord;
      aug[2] += ((float)color[1].argb[2] - (float)color[0].argb[2])
	  / (float)coord;
      col->argb[0] = color[0].argb[0] + (int)aug[0];
      col->argb[1] = color[0].argb[1] + (int)aug[1];
      col->argb[2] = color[0].argb[2] + (int)aug[2];
      i++;
    }
  return (col);
}

void		tekline1(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 int *coords,
			 t_color *color)
{
  int		i;
  int		cumul;
  t_color	*col;

  i = 1;
  cumul = coords[4] / 2;
  while (i <= coords[4])
    {
      pos[0].x += coords[2];
      cumul += coords[5];
      if (cumul >= coords[4])
	{
	  cumul -= coords[4];
	  pos[0].y += coords[3];
	}
      col = tekline_colorconvert(i, coords[4], color);
      tekpixel(pix, pos, col);
      bunny_free(col);
      i++;
    }
}

void		tekline2(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 int *coords,
			 t_color *color)
{
  int		i;
  int		cumul;
  t_color	*col;

  cumul = coords[5] / 2;
  i = 1;
  while (i <= coords[5])
    {
      pos[0].y += coords[3];
      cumul += coords[4];
      if (cumul >= coords[5])
	{
	  cumul -= coords[5];
	  pos[0].x += coords[2];
	}
      col = tekline_colorconvert(i, coords[5], color);
      tekpixel(pix, pos, col);
      bunny_free(col);
      i++;
    }
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color)
{
  int			coords[6];

  coords[0] = pos[1].x - pos[0].x;
  coords[1] = pos[1].y - pos[0].y;
  coords[2] = (coords[0] > 0) ? 1 : -1;
  coords[3] = (coords[1] > 0) ? 1 : -1;
  coords[4] = (coords[0] < 0) ? -(coords[0]) : coords[0];
  coords[5] = (coords[1] < 0) ? -(coords[1]) : coords[1];
  tekpixel(pix, pos, color);
  if (coords[4] > coords[5])
    tekline1(pix, pos, coords, color);
  else
    tekline2(pix, pos, coords, color);
}
