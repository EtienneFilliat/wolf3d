/*
** my_draw_line.c for wolf3D in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Fri Dec 30 18:56:07 2016 Etienne
** Last update Sun Jan 15 14:53:04 2017 Etienne
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

void		my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  int		i;
  t_draw_this	*draw;

  if ((draw = malloc(sizeof(t_draw_this))) == NULL)
    exit (EXIT_FAIL);
  if (from.x > to.x)
    swap_value(&from, &to);
  else if (from.y > to.y)
    swap_value(&from, &to);
  draw->x = from.x;
  draw->y = from.y;
  draw->delt_x = to.x - from.x;
  draw->delt_y = to.y - from.y;
  draw->x_incr = (draw->delt_x > 0) ? 1 : -1;
  draw->y_incr = (draw->delt_y > 0) ? 1 : -1;
  draw->delt_x = abs(draw->delt_x);
  draw->delt_y = abs(draw->delt_y);
  my_put_pixel(framebuffer, draw->x, draw->y, color);
  i = 0;
  if (draw->delt_x > draw->delt_y)
    draw_x_sup_y(draw, i, color, framebuffer);
  else
    draw_y_sup_x(draw, i, color, framebuffer);
  free (draw);
}

void	draw_x_sup_y(t_draw_this *draw, int i, sfColor color,
		     t_my_framebuffer *f_buf)
{
  draw->cumul = draw->delt_x / 2;
  i = 1;
  while (i <= draw->delt_x)
    {
      draw->x += draw->x_incr;
      draw->cumul += draw->delt_y;
      if (draw->cumul >= draw->delt_x)
	{
	  draw->cumul -= draw->delt_x;
	  draw->y += draw->y_incr;
	}
      my_put_pixel(f_buf, draw->x, draw->y, color);
      i += 1;
    }
}

void	draw_y_sup_x(t_draw_this *draw, int i, sfColor color,
		     t_my_framebuffer *f_buf)
{
  draw->cumul = draw->delt_y / 2;
  i = 1;
  while (i <= draw->delt_y)
    {
      draw->y += draw->y_incr;
      draw->cumul += draw->delt_x;
      if (draw->cumul >= draw->delt_y)
	{
	  draw->cumul -= draw->delt_y;
	  draw->x += draw->x_incr;
	}
      my_put_pixel(f_buf, draw->x, draw->y, color);
      i += 1;
    }
}

void		swap_value(sfVector2i *from, sfVector2i *to)
{
  int		tmp;

  tmp = from->x;
  from->x = to->x;
  to->x = tmp;
  tmp = from->y;
  from->y = to->y;
  to->y = tmp;
}
