/*
** keys.h for keys in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 09:38:23 2016 Frederic ODDOU
** Last update Tue Mar  1 09:38:23 2016 Frederic ODDOU
*/

#ifndef KEYS_H_
# define KEYS_H_

#include <lapin.h>
#include <math.h>

#define SPEED_VIEW	2
#define SPEED_ROT	5
#define SPEED_MOVE	45
#define SPEED_FLY	30

#define K_MOVE		BKS_Z
#define K_BACK		BKS_S
#define K_TOP		BKS_P
#define K_BOTTOM	BKS_M
#define K_LEFT		BKS_Q
#define K_RIGHT		BKS_D
#define K_V_LEFT	BKS_LEFT
#define K_V_RIGHT	BKS_RIGHT
#define K_V_UP		BKS_UP
#define K_V_DOWN	BKS_DOWN
#define K_V_ROTX1	BKS_C
#define K_V_ROTX2	BKS_W
#define K_QUIT		BKS_ESCAPE
#define K_RETURN	BKS_BACKSPACE
#define K_PRINT		BKS_SPACE

#define	D_T_R(nb)	((nb / 180) * M_PI)

void		keys_view(t_option *option, t_rt *rt);
void		keys_move(t_option *option, t_rt *rt);
void		keys_get(t_option *option, t_rt *rt);

#endif /* !KEYS_H_ */
