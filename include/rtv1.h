/*
** rtv1.h for rt in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar  4 18:58:18 2016 Frederic ODDOU
** Last update Fri Mar  4 18:58:18 2016 Frederic ODDOU
*/

#ifndef		RTV1_H_
# define	RTV1_H_

#include <lapin.h>
#include "struct.h"

# define	D_R(nb)		((M_PI * (double)nb) / 180.0)

/*
** rt_brillance.c
*/
void		check_seuil(t_color		*seuil,
			    t_color		*color);
void		calc_seuil(t_color 		*seuil,
			   t_color 		*color);
void		calc_normal(double 		*cos,
			    t_vec 		*normale,
			    t_vec 		*vec_dir);
unsigned int	rt_brillance(t_data 		*data,
			     double 		cos,
			     t_light 		*light);

/*
** rt_light.c
*/
void		calc_pt_inter(t_data 		*data,
			      t_vec_oeil 	*pt,
			      t_vec 		*vec);
void		calc_vec_dir(t_light 		*light,
			     t_vec_oeil 	*pt,
			     t_vec 		*vec_dir);
t_color		rt_light(t_data 		*data,
			 t_vec			vec);

/*
** fichiers dans /src/rt/normal/
*/
t_vec		normal_cylindre(t_vec_oeil 	pt,
				t_kmin 		*k);
t_vec		normal_sphere(t_vec_oeil	pt,
			      t_kmin 		*k);
t_vec		normal_cone(t_vec_oeil 		pt,
			    t_kmin 		*k);
t_vec		normal_plan(t_vec_oeil 		pt,
			    t_kmin 		*k);
t_vec		normal_parabol(t_vec_oeil 	pt,
			       t_kmin 		*k);

/*
** rt_normal.c
*/
void		rt_calc_normal(t_vec		*vec);
void		rt_normal(t_data 		*data,
			  t_vec_oeil		pt,
			  double		*k_tmp,
			  t_vec			*vec_dir);

/*
** rt_shadow.c
*/
int		rt_shadow(t_data 		*data,
			  t_vec 		*dir,
			  t_vec_oeil		*pt);

/*
** translation.c
*/
void		translation(t_vec_oeil		*view,
			    t_objs		*forme);
void		rotation_x(double 		*y,
			   double 		*z,
			   double 		angle);
void		rotation_y(double 		*y,
			   double 		*z,
			   double 		angle);
void		rotation_z(double 		*y,
			   double 		*z,
			   double 		angle);
void		movement(t_vec_oeil 		*view,
			 t_objs 		*forme,
			 t_vec 			*vec);

/*
** Calculs des objets dans /calc_objs/
*/
void		calc_cone(t_vec 		vec,
			  t_kmin 		*kist,
			  t_objs 		*cone,
			  t_vec_oeil 		view);
void		calc_cylindre(t_vec 		vec,
			      t_kmin 		*kist,
			      t_objs 		*cy,
			      t_vec_oeil 	view);
void		calc_plan(t_vec 		vec,
			  t_kmin 		*kist,
			  t_objs 		*plan,
			  t_vec_oeil 		view);
void		calc_sphere(t_vec 		vec,
			    t_kmin 		*kist,
			    t_objs 		*ball,
			    t_vec_oeil 		view);
void		calc_parabol(t_vec 		vec,
			     t_kmin 		*k_min,
			     t_objs 		*obj,
			     t_vec_oeil 	view);
t_vec		calc_screen(t_data 		*data,
			    t_bunny_position	pos);

/*
** rt_kmin.c
*/
int		rt_kmin_change(t_kmin 		*elem,
			       double 		k,
			       t_objs 		*obj);
void		rt_kmin_init(t_kmin 		*k_min);

/*
** rt_exec.c
*/
t_color		rt_exec_pix(t_bunny_position 	pos,
			    t_data 		*data);
void 		*rt_exec(void 			*data_pt);

/*
** mutli_thread.c
*/
t_data		create_data(t_rt 		*rt,
			    int 		ymin,
			    int 		ymax);
void		multi_thread(t_rt 		*rt,
			     t_bunny_position 	pos_max);

void		rt_free(t_rt 			*rt);


#endif		/* !RTV1_H_ */
