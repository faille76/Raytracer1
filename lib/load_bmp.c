/*
** load_bmp.c for load bmp in /home/oddou_f/Librairies/lapin/lib/
**
** Made by John Doe
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Jan 31 21:51:25 2016 John Doe
** Last update Sun Jan 31 21:51:25 2016 John Doe
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <lapin.h>
#include "lib.h"
#include "bmp.h"

t_bunny_pixelarray	*bmp_create_pixelarray(int fd)
{
  char			buffer[4096];
  t_bmp_head		head;
  t_bmp_info		info;
  int			len;

  if ((len = read(fd, &head, sizeof(head))) != sizeof(head))
    return (NULL);
  if ((len = read(fd, &info, sizeof(info))) != sizeof(info))
    return (NULL);
  if ((len = head.offset - (sizeof(head) + sizeof(info))) > 0)
    {
      if (read(fd, buffer, len) > 0)
	(void)buffer;
    }
  return (bunny_new_pixelarray(info.width, info.height));
}

t_color		bmp_reverse_color(t_color color)
{
  t_color	new_color;

  new_color.argb[3] = (color.argb)[0];
  new_color.argb[2] = (color.argb)[1];
  new_color.argb[1] = (color.argb)[2];
  new_color.argb[0] = (color.argb)[3];
  return (new_color);
}

void		bmp_take_color(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       int fd)
{
  t_color	color;
  int		len;

  len = 1;
  while (len > 0)
    {
      if ((len = read(fd, color.argb, 4)) == 4)
	{
	  color = bmp_reverse_color(color);
	  tekpixel(pix, pos, &color);
	}
      pos->x += 1;
      pos->y = (pos->x >= (pix->clipable).clip_width ? pos->y - 1 : pos->y);
      pos->x = (pos->x >= (pix->clipable).clip_width ? 0 : pos->x);
    }
}


t_bunny_pixelarray	*load_bmp(const char *file)
{
  int			fd;
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((pix = bmp_create_pixelarray(fd)) == NULL)
    return (NULL);
  pos.x = 0;
  pos.y = (pix->clipable).clip_height - 1;
  bmp_take_color(pix, &pos, fd);
  close(fd);
  return (pix);
}
