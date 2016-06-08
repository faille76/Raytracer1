/*
** keys_move.c for keys move in /src/rt/keys/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 09:36:02 2016 Frederic ODDOU
** Last update Tue Mar  1 09:36:02 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"
#include "keys.h"
#include "struct.h"

void		keys_move(t_option *option, t_rt *rt)
{
  if (option->keys[K_MOVE])
    {
      rt->vec_oeil.x += cos(D_T_R(rt->vec_oeil.z_r)) * SPEED_MOVE;
      rt->vec_oeil.y += sin(D_T_R(rt->vec_oeil.z_r)) * SPEED_MOVE;
    }
  if (option->keys[K_BACK])
    {
      rt->vec_oeil.x -= cos(D_T_R(rt->vec_oeil.z_r)) * SPEED_MOVE;
      rt->vec_oeil.y -= sin(D_T_R(rt->vec_oeil.z_r)) * SPEED_MOVE;
    }
  if (option->keys[BKS_D])
    {
      rt->vec_oeil.x -= cos(rt->vec_oeil.z_r + M_PI / 2) * SPEED_MOVE;
      rt->vec_oeil.y -= sin(rt->vec_oeil.z_r + M_PI / 2) * SPEED_MOVE;
    }
  if (option->keys[BKS_Q])
    {
      rt->vec_oeil.x += cos(rt->vec_oeil.z_r + M_PI / 2) * SPEED_MOVE;
      rt->vec_oeil.y += sin(rt->vec_oeil.z_r + M_PI / 2) * SPEED_MOVE;
    }
  if (option->keys[K_TOP])
    rt->vec_oeil.z += SPEED_FLY;
  if (option->keys[K_BOTTOM])
    rt->vec_oeil.z -= SPEED_FLY;
}
