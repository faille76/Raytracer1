/*
** key_commands.c for key commands in /src/
**
** Made by John Doe
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Jan 31 21:39:46 2016 John Doe
** Last update Sun Jan 31 21:39:46 2016 John Doe
*/

#include <lapin.h>

t_bunny_response	key_commands(t_bunny_event_state state,
				      t_bunny_keysym keysym,
				      void *option_pt)
{
  (void)option_pt;
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
