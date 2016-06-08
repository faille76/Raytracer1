/*
** rt_light.c for light in /src/rt/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 21:49:29 2016 Frederic ODDOU
** Last update Sat Feb 13 21:49:29 2016 Frederic ODDOU
*/

#include	"rtv1.h"

void		calc_pt_inter(t_data		*data,
			      t_vec_oeil 	*pt,
			      t_vec 		*vec)
{
  pt->x = data->vec_oeil->x + (data->k_min->k * vec->x);
  pt->y = data->vec_oeil->y + (data->k_min->k * vec->y);
  pt->z = data->vec_oeil->z + (data->k_min->k * vec->z);
}

void		calc_vec_dir(t_light 		*light,
			     t_vec_oeil 	*pt,
			     t_vec		*vec_dir)
{
  vec_dir->x = light->x - pt->x;
  vec_dir->y = light->y - pt->y;
  vec_dir->z = light->z - pt->z;
}

t_color		rt_light(t_data 		*data,
			 t_vec			vec)
{
  double	k_tmp;
  t_vec		vec_dir;
  t_vec_oeil	view_pt;
  t_color	color;
  t_light	*tmp_light;

  color.full = 0;
  tmp_light = data->light;
  while (tmp_light != NULL)
    {
      calc_pt_inter(data, &view_pt, &vec);
      calc_vec_dir(tmp_light, &view_pt, &vec_dir);
      if (rt_shadow(data, &vec_dir, &view_pt) == 1)
	color.full += rt_brillance(data, 0, tmp_light);
      else
	{
	  rt_normal(data, view_pt, &k_tmp, &vec_dir);
	  color.full += rt_brillance(data, k_tmp, tmp_light);
	}
      tmp_light = tmp_light->next;
    }
  return (color);
}
