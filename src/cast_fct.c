/*
** cast_fct.c for wolf3d in /home/spiki/delivery/B1/GP/test/wolf3d/src
**
** Made by Spiki
** Login   <spiki@epitech.net>
**
** Started on  Mon Jan 09 16:57:52 2017 Spiki
** Last update Fri Jan 13 13:30:29 2017 Etienne
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "my.h"

void		cast_them_all(t_player *player, t_entity *entity,
			      sfVector2i mapSize)
{
  float		direction;
  float		distance;
  int		color;
  int		x;
  int		wall_height;
  float		step;

  x = 0;
  step = (float) FOV / SCREEN_WIDTH;
  direction = player->direction - (FOV / 2);
  while (x < SCREEN_WIDTH)
    {
      distance = raycast(player->pos, direction, entity->map, mapSize);
      color = get_color(player, distance, direction);
      distance = distance * cos((direction - player->direction) *
				(M_PI / 180));
      wall_height = (int) SCREEN_WIDTH / distance;
      direction = direction + step;
      draw(entity, x, wall_height, color);
      x++;
    }
}

int		get_color(t_player *player, float distance, float direction)
{
  sfVector2f	in_w;
  sfVector2f	out_w;
  sfVector2i	delta_w;

  in_w = move_forward(player->pos, direction, distance + RENDER_FINE);
  out_w = move_forward(player->pos, direction, distance);
  delta_w.x = (int) out_w.x - in_w.x;
  delta_w.y = (int) out_w.y - in_w.y;
  if (delta_w.y == -1 && delta_w.x == 0)
    return (1);
  else if (delta_w.y == 1 && delta_w.x == 0)
    return (2);
  else if (delta_w.x == -1 && delta_w.y == 0)
    return (2);
  else if (delta_w.x == 1 && delta_w.y ==  0)
    return (1);
  return (1);
}

void		draw(t_entity *ent, int x, int wall_height, int color)
{
  sfVector2i	from_wall_top;
  sfVector2i	to_wall_bottom;
  sfVector2i	to_sky;
  sfVector2i	to_ground;

  from_wall_top.x = x;
  to_wall_bottom.x = x;
  to_sky.x = x;
  to_ground.x = x;
  from_wall_top.y = (int) (SCREEN_HEIGHT / 2) - (wall_height / 2);
  to_wall_bottom.y = (int) (SCREEN_HEIGHT / 2) + (wall_height / 2);
  to_sky.y = 0;
  to_ground.y = SCREEN_HEIGHT;
  my_draw_line(ent->framebuffer, to_sky, from_wall_top, SKY_COLOR);
  if (color == 1)
    my_draw_line(ent->framebuffer, from_wall_top, to_wall_bottom, WAL_COLOR_L);
  else if (color == 2)
    my_draw_line(ent->framebuffer, from_wall_top, to_wall_bottom, WAL_COLOR_R);
  my_draw_line(ent->framebuffer, to_wall_bottom, to_ground, GND_COLOR);
}

t_player	init_pos(t_entity *entity)
{
  t_player	player;

  player.pos.x = START_X;
  player.pos.y = START_y;
  player.direction = START_DIREC;
  cast_them_all(&player, entity, entity->mapSize);
  return (player);
}
