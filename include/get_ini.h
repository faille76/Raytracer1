/*
** get_ini.h for keys in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 09:38:23 2016 Frederic ODDOU
** Last update Tue Mar  1 09:38:23 2016 Frederic ODDOU
*/

#ifndef GET_INI_H_
# define GET_INI_H_

#include <lapin.h>
#include "lib.h"
#include "rtv1.h"

void		get_all(t_rt *rt, char *file);
void		get_view(t_rt *rt, t_bunny_ini *ini);
t_objs		*get_plan(t_bunny_ini *ini, t_objs *list);
t_objs		*get_cone(t_bunny_ini *ini, t_objs *list);
t_objs		*get_sphere(t_bunny_ini *ini, t_objs *list);
t_objs		*get_cylindre(t_bunny_ini *ini, t_objs *list);
t_objs		*get_parabol(t_bunny_ini *ini, t_objs *list);
t_objs		*get_obj_ini(t_bunny_ini *ini,
			     t_objs *list,
			     char *name,
			     int val);
void		get_light(t_bunny_ini *ini, t_rt *rt);
t_light		*get_light_ini(t_bunny_ini *ini,
			       t_light *light,
			       char *name);

#endif /* !GET_INI_H_ */
