/*
** tekray.c for tekray in /tcore/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 11 19:15:46 2016 Frederic ODDOU
** Last update Fri Mar 11 19:15:46 2016 Frederic ODDOU
*/

#include <lapin.h>
#include <math.h>

void		tekray(const t_bunny_position	*screen_info,
		       int			*x,
		       int			*y,
		       int			*z)
{
  *x = screen_info[1].x - (screen_info[0].x / 2);
  *y = screen_info[1].y - (screen_info[0].y / 2);
  *z = 100;
}
