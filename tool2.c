/*
** tool2.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Wed Jan 11 15:56:45 2017 Flavian Feugueur
** Last update Sun Jan 22 15:18:37 2017 Flavian Feugueur
*/

#include "minishell.h"

int	my_tablen(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

int	my_get_nb(char *str)
{
  int	nb;
  int	i;

  i = nb = 0;
  while (str[i] != '\0')
    {
      nb = nb * 10;
      nb = nb + str[i] - '0';
      i++;
    }
  return (nb);
}

void	ctrlc()
{
  my_putstr("\nlolilolsh$>");
}

char	*my_strcp(char *s)
{
  int	i;
  char	*res;

  i = 0;
  res = malloc(sizeof(char) * my_strlen(s) + 1);
  res[my_strlen(s)] = '\0';
  while (s[i] != '\0')
    {
      res[i] = s[i];
      i++;
    }
  return (res);
}

int	check_setenv(char *str)
{
  int	i;

  i = 6;
  while (str[i] == ' ' && str[i] != '\0')
    {
      i++;
      if (str[i] == '\0')
	return (0);
    }
  return (1);
}
