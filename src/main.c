/*
** main.c for wolf3D in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Fri Dec 23 13:07:58 2016 Etienne
** Last update Wed Jan 11 16:08:17 2017 Etienne
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int		main(int ac, char **av)
{
  int		r_size;
  int		fd;
  char		wolf_buffer[BUFFER_SIZE];

  if (ac != 2)
    return (RETURN_FAILURE);
  if (av[1][0] == '-' && av[1][1] == 'h')
    {
      halp();
      return (RETURN_SUCCES);
    }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (RETURN_FAILURE);
  if ((r_size = read(fd, wolf_buffer, BUFFER_SIZE - 1)) == -1)
    return (RETURN_FAILURE);
  wolf_buffer[BUFFER_SIZE] = '\0';
  close(fd);
  wolf_window(wolf_buffer);
  return (RETURN_SUCCES);
}

void		halp()
{
  my_putstr("USAGE\n");
  my_putstr("\t   ./wolf3d map\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("\t   map    file representing the level you wanna play, ");
  my_putstr("containing '0' for flat area and '1' for walls.\n");
  my_putstr("\t\t  The map may also contain other essentials informations");
  my_putstr(" who will be usefull in order to have\n\t\t  a great experience");
  my_putstr(" in game.\n\n");
  my_putstr("\t\t\t\t\t\t\t\t\t\t\t\t\t\tEtienne FILLIAT {Tek 1.}\n");
}
