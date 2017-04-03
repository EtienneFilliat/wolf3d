/*
** my.h for wolf3D in /home/etienne/delivery/B1/GP/wolf3D/include
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Fri Dec 23 13:08:55 2016 Etienne
** Last update Thu Jan 12 16:33:28 2017 Etienne
*/

#ifndef MY_H_
# define MY_H_

# include "struct.h"
# define RETURN_FAILURE	84
# define RETURN_SUCCES	0
# define EXIT_FAIL	84
# define BUFFER_SIZE	5000
/*
** Csfml functions and defines
*/
# define SCREEN_WIDTH	1280
# define SCREEN_HEIGHT	720
# define FOV		60
# define STEP		0.002
# define START_X	1.5
# define START_y	1.5
# define START_DIREC	0
# define STEP_DIR	2
# define STEP_STRAF	0.05
# define STEP_MOVE	0.08
# define RENDER		0.1
# define RENDER_FINE	0.001
# define SKY_COLOR	(sfColor) {84, 158, 220, 255}
# define WAL_COLOR_L	(sfColor) {62, 63, 67, 255}
# define WAL_COLOR_R	(sfColor) {106, 108, 125, 255}
# define GND_COLOR	(sfColor) {26, 27, 41, 255}
# define MUL_KEY(X)	sfKeyboard_isKeyPressed(X)
int			wolf_window(char *wolf_buffer);
void			aff_window(t_entity *entity, sfEvent event);
void			cast_them_all(t_player *player, t_entity *entity,
				      sfVector2i mapSize);
void			draw(t_entity *entity, int x, int wall_height,
			     int color);
void			event_handeler(t_entity *entity, t_player *player,
				       sfEvent *event);
float			more_fine(sfVector2f pos, float direction, int **map,
				  float distance);
int			get_color(t_player *player, float distance,
				  float direction);
sfVector2f		checker(sfVector2f pos, int **map, sfVector2f last_pos);
t_player		init_pos(t_entity *entity);
sfUint8*		create_pixel_buffer(int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
sfRenderWindow		*create_window(char *name, int width, int height);
/*
** Auto-grader
*/
void		my_put_pixel(t_my_framebuffer *f_buffer, int x, int y,
			     sfColor color);
void		my_draw_line(t_my_framebuffer *f_buffer, sfVector2i from,
			     sfVector2i to, sfColor color);
void		draw_x_sup_y(t_draw_this *draw, int i, sfColor color,
		       t_my_framebuffer *f_buf);
void		draw_y_sup_x(t_draw_this *draw, int i, sfColor color,
		       t_my_framebuffer *f_buf);
sfVector2f	move_forward(sfVector2f pos, float direction, float distance);
float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize);
/*
**                       *To do*
*/
int		**tab_int(char *buffer, sfVector2i mapSize);
int		my_getnbr(char *wf_buff);
int		col_finder(char *wf_buff);
int		line_finder(char *wf_buff);
int		my_strlen();
int		**get_tab(t_entity *entity);
void		halp();
void		my_putstr(char *str);
sfVector2i	get_info(t_entity *entity);
void		filling(t_entity *entity, int **tab);
void		swap_value(sfVector2i *from, sfVector2i *to);

#endif /* !MY_H_ */
