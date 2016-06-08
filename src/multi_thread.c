/*
** multi_thread.c for multi thread in /src/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Mar  5 07:27:34 2016 Frederic ODDOU
** Last update Sat Mar  5 07:27:34 2016 Frederic ODDOU
*/

#include <lapin.h>
#include <pthread.h>
#include "rtv1.h"
#include "struct.h"

void		free_data(t_data data[4])
{
  int		i;

  i = 0;
  while (i < 4)
    {
      bunny_free(data[i].fptr_objs);
      i++;
    }
}

t_fptr_objs	*init_fptr_objs()
{
  t_fptr_objs	*fptr_objs;

  if ((fptr_objs = bunny_malloc(5 * sizeof(t_fptr_objs))) == NULL)
    return (NULL);
  fptr_objs[0].id = SPHERE_VAL;
  fptr_objs[0].calc = &calc_sphere;
  fptr_objs[0].norm = &normal_sphere;
  fptr_objs[1].id = CONE_VAL;
  fptr_objs[1].calc = &calc_cone;
  fptr_objs[1].norm = &normal_cone;
  fptr_objs[2].id = CYLINDRE_VAL;
  fptr_objs[2].calc = &calc_cylindre;
  fptr_objs[2].norm = &normal_cylindre;
  fptr_objs[3].id = PLAN_VAL;
  fptr_objs[3].calc = &calc_plan;
  fptr_objs[3].norm = &normal_plan;
  fptr_objs[4].id = PARABOL_VAL;
  fptr_objs[4].calc = &calc_parabol;
  fptr_objs[4].norm = &normal_parabol;
  return (fptr_objs);
}

t_data		create_data(t_rt *rt,
			    int ymin,
			    int ymax)
{
  t_data	data;

  data.fptr_objs = init_fptr_objs();
  data.pix = rt->pix;
  data.obj = &rt->list;
  data.vec_oeil = &rt->vec_oeil;
  data.ymin = ymin;
  data.ymax = ymax;
  data.light = rt->light;
  data.nb_light = rt->nb_light;
  return (data);
}

void		multi_thread(t_rt *rt,
			     t_bunny_position pos_max)
{
  pthread_t	ta;
  pthread_t	tb;
  pthread_t	tc;
  pthread_t	td;
  t_data	data[4];

  data[0] = create_data(rt, 0, pos_max.y / 4);
  data[0].taille = pos_max;
  data[1] = create_data(rt, pos_max.y / 4, pos_max.y / 2);
  data[1].taille = pos_max;
  data[2] = create_data(rt, pos_max.y / 2, pos_max.y / 2 + pos_max.y / 4);
  data[2].taille = pos_max;
  data[3] = create_data(rt, pos_max.y / 2 + pos_max.y / 4, pos_max.y);
  data[3].taille = pos_max;
  pthread_create(&ta, NULL, rt_exec, (void*)(&data[0]));
  pthread_create(&tb, NULL, rt_exec, (void*)(&data[1]));
  pthread_create(&tc, NULL, rt_exec, (void*)(&data[2]));
  pthread_create(&td, NULL, rt_exec, (void*)(&data[3]));
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);
  pthread_join(tc, NULL);
  pthread_join(td, NULL);
  free_data(data);
}
