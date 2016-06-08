/*
** lib.h for lib in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Nov 10 16:30:09 2015 Frederic ODDOU
** Last update Sat Dec 19 01:34:18 2015 Frederic ODDOU
*/

#ifndef STURCT_H_
# define STURCT_H_

#include <lapin.h>
#include <stdint.h>

typedef	struct	s_objs
{
  double	x;
  double	y;
  double	z;
  double	ray;
  double	x_r;
  double	y_r;
  double	z_r;
  double	bri;
  int		forme;
  t_color	color;
  struct s_objs	*next;
}		t_objs;

typedef	struct	s_kmin
{
  long double	k;
  t_color	color;
  struct s_objs	*obj;
}		t_kmin;

typedef	struct	s_vec
{
  double	x;
  double	y;
  double	z;
}		t_vec;

typedef	struct	s_delta
{
  double	a;
  double	b;
  double	c;
  double	delta;
}		t_delta;

typedef	struct		s_light
{
  double		x;
  double		y;
  double		z;
  double		b_r;
  double		b_g;
  double		b_b;
  struct s_light	*next;
}			t_light;

typedef struct		s_vec_oeil
{
  double	x;
  double	y;
  double	z;
  double	x_r;
  double	y_r;
  double	z_r;
}			t_vec_oeil;

typedef struct	s_fptr_objs
{
  int		id;
  void		(*calc)(t_vec vec, t_kmin *k_min, t_objs *obj, t_vec_oeil view);
  t_vec		(*norm)(t_vec_oeil pt, t_kmin *k);
}		t_fptr_objs;

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_objs		**obj;
  int			ymin;
  int			ymax;
  t_kmin		*k_min;
  t_vec_oeil		*vec_oeil;
  t_light		*light;
  int			nb_light;
  t_bunny_position	taille;
  t_fptr_objs		*fptr_objs;
}			t_data;


typedef struct		s_rt
{
  t_bunny_pixelarray	*pix;
  t_vec_oeil		vec_oeil;
  t_objs		*list;
  t_light		*light;
  int			nb_light;
  short			move;
  short			first;
}			t_rt;

typedef struct		s_option
{
  t_bunny_position	*blitpos;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pix_backup;
  t_bunny_pixelarray	*font;
  t_color		bg;
  t_rt			*rt;
  const bool		*keys;
  const t_bunny_position*mouse;
}			t_option;

/*
** Structure permettant de lier une position et une couleur
** Utile pour l'écriture par exemple
*/
typedef struct		s_pos
{
  t_bunny_position	pos;
  t_color		color;
}			t_pos;

typedef enum			e_forme
{
  SPHERE_VAL			= 0,
  CONE_VAL			= 1,
  CYLINDRE_VAL			= 2,
  PLAN_VAL			= 3,
  PARABOL_VAL			= 4
}				t_forme;

#endif /* !STURCT_H_ */
