/*
** my_csfml_fct.c for wolf3D in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Sat Dec 24 13:07:33 2016 Etienne
** Last update Fri Jan  6 14:26:28 2017 Etienne
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

sfUint8*		create_pixel_buffer(int width, int height)
{
  int			i;
  sfUint8		*pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
    exit (EXIT_FAIL);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i++;
    }
  return (pixels);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*buffer;

  buffer = malloc(sizeof(t_my_framebuffer));
  if (buffer == NULL)
    exit (EXIT_FAIL);
  (*buffer).pixels = create_pixel_buffer(width, height);
  (*buffer).width = width;
  (*buffer).height = height;
  return (buffer);
}
