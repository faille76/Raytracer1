/*
** treat.c for treat in /src/rt/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 21:52:56 2016 Frederic ODDOU
** Last update Sat Feb 13 21:52:56 2016 Frederic ODDOU
*/

#include	<lapin.h>
#include	<stdlib.h>
#include	"lib.h"
#include	"rtv1.h"

t_color			rt_exec_pix(t_bunny_position	pos,
				    t_data 		*data)
{
  t_vec			vec;
  t_objs		*tmp;

  tmp = *(data->obj);
  vec = calc_screen(data, pos);
  while (tmp != NULL)
    {
      data->fptr_objs[tmp->forme].calc(vec, data->k_min, tmp, *data->vec_oeil);
      tmp = tmp->next;
    }
  if (data->k_min->obj == NULL)
    return (data->k_min->color);
  return (rt_light(data, vec));
}

void 			*rt_exec(void			*data_pt)
{
  t_data		*data;
  t_kmin		k_min;
  t_bunny_position	pos;
  t_color		color;

  data = (t_data*)data_pt;
  pos.y = data->ymin;
  while (pos.y < data->ymax)
    {
      pos.x = 0;
      while (pos.x < data->taille.x)
	{
	  rt_kmin_init(&k_min);
	  data->k_min = &k_min;
	  color = rt_exec_pix(pos, data);
	  tekpixel(data->pix, &pos, &color);
	  pos.x++;
	}
      pos.y++;
    }
  return (NULL);
}
