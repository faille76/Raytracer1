/*
** tekcercle.c for tekcercle in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Dec  4 16:45:13 2015 Frederic ODDOU
** Last update Mon Dec  7 22:01:27 2015 Frederic ODDOU
*/

#include <lapin.h>
#include <stdlib.h>
#include "lib.h"

void			tekpixelcercle(t_bunny_pixelarray *pix,
				       int x,
				       int y,
				       t_color *color)
{
  t_bunny_position 	ptmp;

  ptmp.x = x;
  ptmp.y = y;
  tekpixel(pix, &ptmp, color);
}

void			tekcercle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  int rayon,
				  t_color *color)
{
  int			x;
  int			y;
  int			m;

  x = 0;
  y = rayon;
  m = 5 - 4 * rayon;
  while (x <= y)
    {
      tekpixelcercle(pix, (x + pos[0].x), (y + pos[0].y), color);
      tekpixelcercle(pix, (-x + pos[0].x), (-y + pos[0].y), color);
      tekpixelcercle(pix, (-x + pos[0].x), (y + pos[0].y), color);
      tekpixelcercle(pix, (y + pos[0].x), (-x + pos[0].y), color);
      tekpixelcercle(pix, (y + pos[0].x), (x + pos[0].y), color);
      tekpixelcercle(pix, (-y + pos[0].x), (x + pos[0].y), color);
      tekpixelcercle(pix, (x + pos[0].x), (-y + pos[0].y), color);
      tekpixelcercle(pix, (-y + pos[0].x), (-x + pos[0].y), color);
      if (m > 0)
	{
	  y -= 1;
	  m -= 8 * y;
	}
      x++;
      m += 8 * x + 4;
    }
}

void			teklinecercle(t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      int *ab,
				      t_color *color)
{
  t_bunny_position	*l1;
  t_bunny_position	*l2;
  t_bunny_position	*l3;
  t_bunny_position	*l4;

  l1 = tekcoords(pos[0].x + ab[1], pos[0].y - ab[0],
		 pos[0].x + ab[1], pos[0].y + ab[0]);
  l2 = tekcoords(pos[0].x + ab[0], pos[0].y - ab[1],
		 pos[0].x + ab[0], pos[0].y + ab[1]);
  l3 = tekcoords(pos[0].x - ab[1], pos[0].y - ab[0],
		 pos[0].x - ab[1], pos[0].y + ab[0]);
  l4 = tekcoords(pos[0].x - ab[0], pos[0].y - ab[1],
		 pos[0].x - ab[0], pos[0].y + ab[1]);
  tekline(pix, l1, color);
  tekline(pix, l2, color);
  tekline(pix, l3, color);
  tekline(pix, l4, color);
  bunny_free(l1);
  bunny_free(l2);
  bunny_free(l3);
  bunny_free(l4);
}

int			tekcercle_calc_d(int d, int rayon, int *ab)
{
  d = (d < 2 * (rayon - 1)) ? (2 * ab[0] - 1) :
      (2 * (ab[0] - ((d < 2 * (rayon - 1)) ? ab[1] : (ab[1] - 1)) - 1));
  return (d);
}

void			tekcercle_rec(t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      int rayon,
				      t_color *color)
{
  int			d;
  int			ab[2];

  d = rayon - 1;
  ab[0] = rayon - 1;
  ab[1] = 0;
  while (ab[0] >= ab[1])
    {
      teklinecercle(pix, pos, ab, color);
      if (d >= 2 * ab[1])
	{
	  d -= 2 * ab[1] - 1;
	  ab[1] += 1;
	}
      else
	{
	  ab[1] += (d < 2 * (rayon - 1)) ? 0 : 1;
	  d += tekcercle_calc_d(d, rayon, ab);
	  ab[0] -= 1;
	}
    }
}
