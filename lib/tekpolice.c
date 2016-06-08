/*
** tekpolice.c for tekpolice in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Feb  2 16:43:15 2016 Frederic ODDOU
** Last update Tue Feb  2 16:43:15 2016 Frederic ODDOU
*/

#include <lapin.h>
#include <lib.h>

void			tekletter(t_option *option,
				  t_bunny_position *init,
				  t_color *color,
				  char letter)
{
  t_color		get;
  t_bunny_position	pos;
  int			iw;
  int			ih;

  if (option->font == NULL)
    return ;
  iw = letter * 5;
  while (iw < (option->font->clipable).clip_width &&
	 iw < (letter + 1) * 5)
    {
      ih = 0;
      while (ih < (option->font->clipable).clip_height)
	{
	  pos.x = iw;
	  pos.y = ih;
	  get = getpixel(option->font, &pos);
  	  pos.x += init->x - letter * 5;
  	  pos.y += init->y;
	  if (get.full != 0)
	    tekpixel(option->pix, &pos, color);
	  ih++;
	}
      iw++;
    }
}

void			tekpolice(t_option *option,
				  t_pos *init,
				  char *str)
{
  int			i;
  t_bunny_position	pos;

  if (option->font == NULL)
    return ;
  i = 0;
  pos.x = init->pos.x;
  pos.y = init->pos.y;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  pos.x = init->pos.x;
	  pos.y += 8;
	}
      else
	{
	  tekletter(option, &pos, &init->color, str[i]);
	  pos.x += 6;
	}
      i++;
    }
}
