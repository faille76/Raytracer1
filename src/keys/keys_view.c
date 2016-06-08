/*
** keys_view.c for keys view in /src/rt/keys/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 09:35:03 2016 Frederic ODDOU
** Last update Tue Mar  1 09:35:03 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"
#include "keys.h"
#include "struct.h"

void		keys_view(t_option *option, t_rt *rt)
{
  if (option->keys[K_V_RIGHT])
    rt->vec_oeil.z_r -= SPEED_VIEW;
  if (option->keys[K_V_LEFT])
    rt->vec_oeil.z_r += SPEED_VIEW;
  if (option->keys[K_V_UP])
    rt->vec_oeil.y_r -= SPEED_VIEW;
  if (option->keys[K_V_DOWN])
    rt->vec_oeil.y_r += SPEED_VIEW;
  if (option->keys[K_V_ROTX1])
    rt->vec_oeil.x_r -= SPEED_VIEW;
  if (option->keys[K_V_ROTX2])
    rt->vec_oeil.x_r += SPEED_VIEW;
}
