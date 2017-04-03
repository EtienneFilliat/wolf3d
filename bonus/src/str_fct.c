/*
** str_fct.c for wolf3D in /home/etienne/delivery/B1/GP/wolf3D
**
** Made by Etienne
** Login   <etienne@epitech.net>
**
** Started on  Fri Dec 23 13:25:03 2016 Etienne
** Last update Fri Dec 23 13:38:48 2016 Etienne
*/

#include <unistd.h>
#include "my.h"

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
