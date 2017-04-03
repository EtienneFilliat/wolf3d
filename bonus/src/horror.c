/*
** horror.c for wolf3d in /home/spiki/delivery/B1/GP/test/wolf3d/bonus/src
**
** Made by Spiki
** Login   <spiki@epitech.net>
**
** Started on  Fri Jan 13 13:27:26 2017 Spiki
** Last update Fri Jan 13 15:51:36 2017 Etienne
*/

#include <SFML/Graphics/RenderWindow.h>
#include "my.h"

void		horror_draw(t_entity *ent, t_mode *mode)
{
  sfVector2i	from;
  sfVector2i	to;
  sfColor	blur_l;
  sfColor	blur_r;

  from.x = mode->col;
  to.x = mode->col;
  from.y = (int) (SCREEN_HEIGHT / 2) - (mode->wall_height / 2);
  blur_l = WAL_COLOR_L;
  blur_r = WAL_COLOR_R;
  blur_l = get_the_fog(mode, blur_l);
  blur_r = get_the_fog(mode, blur_r);
  to.x = mode->col;
  to.y = 0,
  my_draw_line(ent->framebuffer, to, from, sfBlack);
  to.y = (int) (SCREEN_HEIGHT / 2) + (mode ->wall_height / 2);
  if (mode->color == 1)
    my_draw_line(ent->framebuffer, from, to, blur_l);
  else if (mode->color == 2)
    my_draw_line(ent->framebuffer, from, to, blur_r);
  from.y = SCREEN_HEIGHT;
  my_draw_line(ent->framebuffer, to, from, sfBlack);
  }

sfColor		get_the_fog(t_mode *mode, sfColor color)
{
  color.a = 255 - (70 * mode->dist);
  if (mode->dist > 3)
    color.a = 0;
  return (color);
}
