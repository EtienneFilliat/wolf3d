/*
** movment.c for wolf3D in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Sat Dec 24 14:55:55 2016 Etienne
** Last update Tue Jan 10 14:28:35 2017 Etienne
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include "my.h"

/*
** Polar coordonates to Cartesian
*/
sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  float		dir;
  sfVector2f	new_pos;

  dir = direction * (M_PI / 180);
  new_pos.x = pos.x + distance * cos(dir);
  new_pos.y = pos.y + distance * sin(dir);
  return (new_pos);
}
