/*
** mouse_commands.c for mouse commands in src/
**
** Made by John Doe
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Jan 31 21:45:45 2016 John Doe
** Last update Sun Jan 31 21:45:45 2016 John Doe
*/

#include <lapin.h>

t_bunny_response	mouse_commands(t_bunny_event_state state,
				       t_bunny_mousebutton button,
				       void *option_pt)
{
  (void)state;
  (void)button;
  (void)option_pt;
  return (GO_ON);
}
