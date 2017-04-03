/*
** struct.h for wolf3D in /home/etienne/delivery/B1/GP/wolf3D/include
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Fri Dec 23 13:46:41 2016 Etienne
** Last update Wed Jan 11 16:07:21 2017 Etienne
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>

/*
** Auto-grader
*/
typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

/*
** A trier et free
*/
typedef struct		s_entity
{
  t_my_framebuffer	*framebuffer;
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  char			*wolf_buffer;
  sfVector2i		mapSize;
  int			**map;
}			t_entity;

typedef struct		s_player
{
  sfVector2f		pos;
  float			direction;
}			t_player;

typedef struct		s_draw_this
{
  int		x;
  int		y;
  int		delt_x;
  int		delt_y;
  int		x_incr;
  int		y_incr;
  int		cumul;
}			t_draw_this;


#endif /* !STRUCT_H_ */
