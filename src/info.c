/*
** info.c for wolf3D in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Sat Dec 24 13:21:28 2016 Etienne
** Last update Mon Jan  9 20:46:30 2017 Etienne
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int		line_finder(char *wf_buff)
{
  int		y;
  int		i;

  y = 0;
  i = 0;
  while (wf_buff[i] != '\0')
    {
      if (wf_buff[i] == '\n')
	y = y + 1;
      i = i + 1;
    }
  return (y);
}

int		col_finder(char *wf_buff)
{
  int		i;

  i = 0;
  while (wf_buff[i] != '\n')
    i = i + 1;
  return (i);
}

sfVector2i	get_info(t_entity *entity)
{
  sfVector2i	map_info;

  map_info.y = line_finder(entity->wolf_buffer);
  map_info.x = col_finder(entity->wolf_buffer);
  return (map_info);
}

int		**tab_int(char *buffer, sfVector2i mapSize)
{
  int		**z_coord;
  int           i;
  int		x;
  int		y;

  x = 0;
  y = 0;
  i = 0;
  z_coord = malloc(sizeof(int *) * mapSize.y + 1);
  while (x <= mapSize.y - 1)
    {
      z_coord[x] = malloc(sizeof(int) * mapSize.x);
      while (y <= mapSize.x - 1)
	{
	  z_coord[x][y] = buffer[i] - 48;
	  y++;
          i++;
	}
      y = 0;
      x++;
      i++;
    }
  return (z_coord);
}
