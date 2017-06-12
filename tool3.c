/*
** tool3.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Fri Jan 20 13:24:58 2017 Flavian Feugueur
** Last update Sun Jan 22 21:42:05 2017 Flavian Feugueur
*/

#include "minishell.h"

char	**my_tabcp(char **str)
{
  int	i;
  char	**tmp;

  i = 0;
  tmp = malloc(sizeof(char*) * (my_tablen(str) + 1));
  while (str[i] != NULL)
    {
      tmp[i] = my_strcp(str[i]);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}

void	replace_tab(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
}
