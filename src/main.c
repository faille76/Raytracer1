/*
** main.c for sub 2 in /
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Dec  5 09:06:59 2015 Frederic ODDOU
** Last update Sat Dec 19 15:06:40 2015 Frederic ODDOU
*/

#include <lapin.h>
#include <stdlib.h>
#include "lib.h"
#include "rtv1.h"
#include "keys.h"
#include "get_ini.h"

void			rt_loop(t_option *option)
{
  t_bunny_position	pos_max;

  if (option->keys[K_RETURN])
    {
      cpy_pix(option->pix, option->pix_backup);
      option->rt->move = 0;
    }
  if (option->rt->first || option->keys[K_PRINT])
    {
      pos_max.x = WIDTH;
      pos_max.y = HEIGHT;
      multi_thread(option->rt, pos_max);
      antialiasing(option->rt->pix);
      option->rt->first = 0;
      cpy_pix(option->pix_backup, option->pix);
    }
  if (option->rt->move == 1)
    {
      cadre_effect(option->rt->pix);
      pos_max.x = WIDTH_MIN;
      pos_max.y = HEIGHT_MIN;
      multi_thread(option->rt, pos_max);
      option->rt->move = 0;
    }
}

t_bunny_response	mainloop(void	*_option)
{
  t_option		*option;

  option = _option;
  option->keys = bunny_get_keyboard();
  rt_loop(option);
  keys_get(option, option->rt);
  keys_move(option, option->rt);
  keys_view(option, option->rt);
  bunny_blit(&(option->win)->buffer,
	     &(option->pix)->clipable,
	     option->blitpos);
  bunny_display(option->win);
  return (GO_ON);
}

int			init_option(t_option *option, char *file)
{
  if ((option->blitpos = bunny_malloc(sizeof(t_bunny_position *))) == NULL)
    return (1);
  option->blitpos->x = 0;
  option->blitpos->y = 0;
  option->win = bunny_start(WIDTH, HEIGHT, true, NAME);
  (option->bg).full = WHITE;
  option->pix = bunny_new_pixelarray(1920, 1080);
  option->pix_backup = bunny_new_pixelarray(1920, 1080);
  option->font = bunny_load_pixelarray("./font/font.png");
  if ((option->rt = bunny_malloc(sizeof(t_rt))) == NULL)
    return (1);
  option->rt->first = 1;
  option->rt->move = 0;
  option->rt->nb_light = 0;
  option->rt->pix = option->pix;
  get_all(option->rt, file);
  return (0);
}

int			main(int ac, char **av)
{
  t_option		option;

  if (init_option(&option, (ac > 1) ? av[1] : "scene/1.ini") != 0)
    return (EXIT_FAILURE);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(&key_commands);
  bunny_set_click_response(&mouse_commands);
  bunny_loop(option.win, FPS, &option);
  bunny_stop(option.win);
  bunny_delete_clipable(&(option.pix)->clipable);
  bunny_delete_clipable(&(option.pix_backup)->clipable);
  bunny_delete_clipable(&(option.font)->clipable);
  bunny_free(option.blitpos);
  rt_free(option.rt);
  return (EXIT_SUCCESS);
}
