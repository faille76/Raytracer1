/*
** bmp.h for bmp in /home/oddou_f/Librairies/lapin/include/
**
** Made by John Doe
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Jan 31 22:38:01 2016 John Doe
** Last update Sun Jan 31 22:38:01 2016 John Doe
*/

#ifndef BMP_H_
# define BMP_H_

typedef struct		s_bmp_head
{
  unsigned short int	type;
  unsigned int		size;
  unsigned short int	reserved1;
  unsigned short int	reserved2;
  uint32_t		offset;
} __attribute__((packed)) t_bmp_head;

typedef struct		s_bmp_info
{
  unsigned int		size;
  int			width;
  int			height;
  unsigned short int	planes;
  unsigned short int	bits;
  unsigned int		compression;
  unsigned int		imagesize;
  int			xresolution;
  int			yresolution;
  unsigned int		ncolours;
  unsigned int		importantcolours;
} 			t_bmp_info;

t_bunny_pixelarray	*load_bmp(const char *file);
void			bmp_take_color(t_bunny_pixelarray *pix,
				       t_bunny_position *pos,
				       int fd);
t_color			bmp_reverse_color(t_color color);
t_bunny_pixelarray	*bmp_create_pixelarray(int fd);

#endif /* !BMP_H_ */
