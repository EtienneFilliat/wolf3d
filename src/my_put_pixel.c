/*
** my_put_pixel.c for wireframe in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Fri Dec 09 14:36:25 2016 Etienne
** Last update Tue Jan 24 15:23:07 2017 etienne.filliat
*/

#include <SFML/Graphics/RenderWindow.h>
#include "my.h"

void		my_put_pixel(t_my_framebuffer *f_buffer, int x, int y,
			     sfColor color)
{
  int		test;

  test = 0;
  if (x < 0 || x >= f_buffer->width)
    test = 1;
  if (y < 0 || y >= f_buffer->height)
    test = 1;
  if (test == 0)
    {
      (*f_buffer).pixels[(f_buffer->width * y + x) * 4] = color.r;
      (*f_buffer).pixels[(f_buffer->width * y + x) * 4 + 1] = color.g;
      (*f_buffer).pixels[(f_buffer->width * y + x) * 4 + 2] = color.b;
      (*f_buffer).pixels[(f_buffer->width * y + x) * 4 + 3] = color.a;
    }
}
