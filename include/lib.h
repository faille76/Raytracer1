/*
** lib.h for lib in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Nov 10 16:30:09 2015 Frederic ODDOU
** Last update Sat Dec 19 01:34:18 2015 Frederic ODDOU
*/

#ifndef LIB_H_
# define LIB_H_

#include <lapin.h>
#include <stdint.h>
#include "struct.h"
#include "rtv1.h"

#define WIDTH (1920)
#define HEIGHT (1080)
#define WIDTH_MIN (380)
#define HEIGHT_MIN (216)
#define FPS (30)
#define NAME "RayTracer 1"

/*
** Pose d'un pixel a l'ecran
*/
void    		tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

/*
** Creation d'une ligne en degrade
*/
void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color);
void			tekline1(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 int *coords,
				 t_color *color);
void			tekline2(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 int *coords,
				 t_color *color);
t_color			*tekline_colorconvert(int len,
					      int coord,
					      t_color *color);

/*
** Tracer un cercle / recursif
*/
void			tekcercle_rec(t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      int rayon,
				      t_color *color);
void			teklinecercle(t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      int *ab,
				      t_color *color);
void			tekcercle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  int rayon,
				  t_color *color);
void			tekpixelcercle(t_bunny_pixelarray *pix,
				       int x,
				       int y,
				       t_color *color);
int			tekcercle_calc_d(int d,
					 int rayon,
					 int *ab);

/*
** Creation d'un t_bunny_position avec deux coordonnees
*/
t_bunny_position	*tekcoords(int x1,
				   int y1,
				   int x2,
				   int y2);

/*
** Cration d'un carré d'une certaine dimention
*/
void			tekcarre(t_bunny_pixelarray *pix,
				 t_bunny_position *pos1,
				 unsigned int col,
				 int taille);

/*
** Poser un fond ecran d'une couleur donnee en bg
*/
void			setcolor(t_option *option);

/*
** Obtenir la couleur d'une position
*/
t_color         	getpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos);

/*
** Capture des touches clavier
*/
t_bunny_response	key_commands(t_bunny_event_state state,
				     t_bunny_keysym keysym,
				     void *option_pt);

/*
** Capture de la position de la souris
*/
t_bunny_response	mouse_commands(t_bunny_event_state state,
				       t_bunny_mousebutton button,
				       void *option_pt);
int			tekmouse(t_bunny_position *start,
				 t_bunny_position *end);

/*
** Affichage de police
*/
void			tekpolice(t_option *option,
				  t_pos *pos,
				  char *str);
void			tekletter(t_option *option,
				  t_bunny_position *init,
				  t_color *color,
				  char letter);

/*
** Prendre les informations du ini et convertir en int
*/
int			take_int_from_ini(t_bunny_ini *ini,
					  char *name,
					  char *type,
					  int pos);
#define			tifi		take_int_from_ini

/*
** Prendre les informations du ini et convertir en double
*/
double			take_double_from_ini(t_bunny_ini *ini,
					     char *name,
					     char *type,
					     int pos);
#define			tdfi		take_double_from_ini

/*
** Prendre les couleurs d'un fichier ini
*/

void			take_color_from_ini(t_color *color,
					    t_bunny_ini *ini,
					    char *name,
					    char *title);
#define			tcfi		take_color_from_ini

/*
** Take nombre de params mis dans un param dans le ini
*/

int			take_nb_arg_from_ini(t_bunny_ini *ini,
					     char *name,
					     char *type);
 #define		tnafi		take_nb_arg_from_ini

/*
** My put all
*/
int			my_putchar(int c);
int			my_putstr(char *str);
int			my_strlen(char *str);
int			my_putnbr(int nbr);
int			my_getnbr(char *str);
float			my_atoi_float(char *str, float nbr);
float			my_atoi(char *str);
char			*my_strdup(char *str);
int			my_strcmp(char *s1, char *s2);

void			cpy_pix(t_bunny_pixelarray *pix1,
				t_bunny_pixelarray *pix2);

void			cadre_effect(t_bunny_pixelarray *pix);

void    		antialiasing(t_bunny_pixelarray *pix);

#endif /* !LIB_H_ */
