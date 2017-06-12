/*
** my_exit.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Tue Jan 17 16:43:24 2017 Flavian Feugueur
** Last update Sun Jan 22 15:14:51 2017 Flavian Feugueur
*/

#include "minishell.h"

int	loop_exit(char **str, int i, int res)
{
  int	nb;

  if (my_strncmp(str[i], "+", 1) == 0)
    {
      nb = my_get_nb(str[i + 1]);
      res = res + nb;
    }
  if (my_strncmp(str[i], "-", 1) == 0)
    {
      nb = my_get_nb(str[i + 1]);
      res = res - nb;
    }
  if (my_strncmp(str[i], "*", 1) == 0)
    {
      nb = my_get_nb(str[i + 1]);
      res = res * nb;
    }
  if (my_strncmp(str[i], "/", 1) == 0)
    {
      nb = my_get_nb(str[i + 1]);
      res = res / nb;
    }
  return (res);
}

int	my_exit(char **str)
{
  int	res;
  int	i;

  res = 0;
  i = 1;
  my_putstr("exit\n");
  if (str[i] != NULL)
    res = my_get_nb(str[i]);
  else
    return (0);
  while (str[i] != NULL)
    {
      res = loop_exit(str, i, res);
      i++;
    }
  return (res);
}
