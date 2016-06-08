/*
** rt_brillance.c for brillance in /src/rt/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Feb 13 21:48:44 2016 Frederic ODDOU
** Last update Sat Feb 13 21:48:44 2016 Frederic ODDOU
*/

#include	"rtv1.h"

void		check_seuil(t_color 	*seuil,
			    t_color 	*color)
{
  if (color->argb[RED_CMP] < seuil->argb[RED_CMP])
    color->argb[RED_CMP] = seuil->argb[RED_CMP];
  if (color->argb[GREEN_CMP] < seuil->argb[GREEN_CMP])
    color->argb[GREEN_CMP] = seuil->argb[GREEN_CMP];
  if (color->argb[BLUE_CMP] < seuil->argb[BLUE_CMP])
    color->argb[BLUE_CMP] = seuil->argb[BLUE_CMP];
}

void		calc_seuil(t_color 	*seuil,
			   t_color 	*color)
{
  seuil->argb[RED_CMP] = color->argb[RED_CMP] * 0.25;
  seuil->argb[GREEN_CMP] = color->argb[GREEN_CMP] * 0.25;
  seuil->argb[BLUE_CMP] = color->argb[BLUE_CMP] * 0.25;
}

unsigned int	rt_brillance(t_data 	*data,
			     double 	k_tmp,
			     t_light 	*light)
{
  t_color	color;
  t_color	seuil;
  t_kmin	*k;

  k = data->k_min;
  color.argb[RED_CMP] = k->color.argb[RED_CMP] * (1 - k->obj->bri)
      + (light->b_r * k->obj->bri);
  color.argb[GREEN_CMP] = k->color.argb[GREEN_CMP] * (1 - k->obj->bri)
      + (light->b_g * k->obj->bri);
  color.argb[BLUE_CMP] = k->color.argb[BLUE_CMP] * (1 - k->obj->bri)
      + (light->b_b * k->obj->bri);
  calc_seuil(&seuil, &color);
  color.argb[RED_CMP] *= k_tmp;
  color.argb[GREEN_CMP] *= k_tmp;
  color.argb[BLUE_CMP] *= k_tmp;
  check_seuil(&seuil, &color);
  color.argb[RED_CMP] /= data->nb_light;
  color.argb[GREEN_CMP] /= data->nb_light;
  color.argb[BLUE_CMP] /= data->nb_light;
  return (color.full);
}
