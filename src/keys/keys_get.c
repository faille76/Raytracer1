/*
** keys_get.c for keys get in /src/rt/keys/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 11:23:28 2016 Frederic ODDOU
** Last update Tue Mar  1 11:23:28 2016 Frederic ODDOU
*/

#include <lapin.h>
#include "lib.h"
#include "struct.h"
#include "keys.h"

void		keys_get(t_option *option, t_rt *rt)
{

  if (option->keys[K_MOVE] || option->keys[K_BACK] || option->keys[K_TOP] ||
      option->keys[K_BOTTOM] || option->keys[K_V_LEFT] ||
      option->keys[K_V_RIGHT] || option->keys[K_V_UP] ||
      option->keys[K_V_DOWN] ||
      option->keys[K_V_ROTX1] || option->keys[K_V_ROTX2] ||
      option->keys[K_LEFT] || option->keys[K_RIGHT])
    rt->move = 1;
}
