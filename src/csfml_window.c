/*
** csfml_window.c for wolf3D in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Sat Dec 24 13:02:36 2016 Etienne
** Last update Wed Jan 11 16:12:55 2017 Etienne
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int		wolf_window(char *wolf_buffer)
{
  t_entity		*entity;
  sfEvent		event;

  entity = malloc(sizeof(t_entity));
  entity->wolf_buffer = wolf_buffer;
  entity->window = create_window("Wolf3d", SCREEN_WIDTH, SCREEN_HEIGHT);
  entity->sprite = sfSprite_create();
  entity->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  entity->framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
  entity->mapSize = get_info(entity);
  entity->map = tab_int(entity->wolf_buffer, entity->mapSize);
  aff_window(entity, event);
  free (entity);
  return (RETURN_SUCCES);
}

void		aff_window(t_entity *entity, sfEvent event)
{
  t_player	player;

  player = init_pos(entity);
  while (sfRenderWindow_isOpen(entity->window))
    {
      while (sfRenderWindow_pollEvent(entity->window, &event))
	{
	  if (event.key.code == sfKeyEscape || event.type == sfEvtClosed)
	    sfRenderWindow_close(entity->window);
	}
      event_handeler(entity, &player, &event);
      cast_them_all(&player, entity, entity->mapSize);
      sfTexture_updateFromPixels(entity->texture, entity->framebuffer->pixels,
				 SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
      sfRenderWindow_clear(entity->window, sfBlack);
      sfRenderWindow_drawSprite(entity->window, entity->sprite, NULL);
      sfRenderWindow_display(entity->window);
    }
}

void	event_handeler(t_entity *entity, t_player *player, sfEvent *event)
{
  if (MUL_KEY(sfKeyA) == sfTrue)
    player->direction =  player->direction - STEP_DIR;
  if (MUL_KEY(sfKeyE) == sfTrue)
    player->direction =  player->direction + STEP_DIR;
  if (MUL_KEY(sfKeyQ) == sfTrue)
    player->pos =  checker(move_forward(player->pos, player->direction - 90,
					STEP_STRAF), entity->map, player->pos);
  if (MUL_KEY(sfKeyD) == sfTrue)
    player->pos =  checker(move_forward(player->pos, player->direction + 90,
					STEP_STRAF), entity->map, player->pos);
  if (MUL_KEY(sfKeyZ) == sfTrue)
    player->pos =  checker(move_forward(player->pos, player->direction,
					STEP_MOVE), entity->map, player->pos);
  if (MUL_KEY(sfKeyS) == sfTrue)
    player->pos =  checker(move_forward(player->pos, player->direction - 180,
					STEP_MOVE), entity->map, player->pos);
}

sfVector2f	checker(sfVector2f pos, int **map, sfVector2f last_pos)
{
  sfVector2i	cast;

  cast.x = (int) pos.x;
  cast.y = (int) pos.y;
  if (map[cast.y][cast.x] != 1)
    return (pos);
  else
    return (last_pos);
}
