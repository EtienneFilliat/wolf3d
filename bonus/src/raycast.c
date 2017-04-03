/*
** raycast.c for wolf3d in /home/spiki/delivery/B1/GP/wolf3d
**
** Made by Spiki
** Login   <spiki@epitech.net>
**
** Started on  Fri Jan 06 13:07:12 2017 Spiki
** Last update Thu Jan 12 16:53:34 2017 Etienne
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include "my.h"

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
  double		distance;
  double		move;
  int		nop;
  sfVector2f	new_pos;
  sfVector2i	cast;

  nop = 0;
  move = RENDER;
  distance = move;
  mapSize.x = mapSize.x;
  mapSize.y = mapSize.y;
  new_pos = move_forward(pos, direction, distance);
  cast.x = (int) new_pos.x;
  cast.y = (int) new_pos.y;
  if (cast.x < 0 || cast.x >= mapSize.x || cast.y < 0 || cast.y >= mapSize.y)
    nop = 1;
  while (map[cast.y][cast.x] != 1 && nop == 0)
    {
      distance = distance + move;
      new_pos = move_forward(pos, direction, distance);
      cast.x = (int) new_pos.x;
      cast.y = (int) new_pos.y;
    }
  distance = more_fine(pos, direction, map, distance);
  return (distance);
}

float		more_fine(sfVector2f pos, float direction, int **map,
			  float distance)
{
  double	move;
  int		nop;
  sfVector2f	new_pos;
  sfVector2i	cast;

  move = RENDER_FINE;
  new_pos = move_forward(pos, direction, distance);
  cast.x = (int) new_pos.x;
  cast.y = (int) new_pos.y;
  while (map[cast.y][cast.x] != 0)
    {
      distance = distance - move;
      new_pos = move_forward(pos, direction, distance);
      cast.x = (int) new_pos.x;
      cast.y = (int) new_pos.y;
    }
  return (distance);
}
