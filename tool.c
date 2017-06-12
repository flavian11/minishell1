/*
** tool.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Mon Jan  2 20:39:30 2017 Flavian Feugueur
** Last update Sun Jan 22 15:18:56 2017 Flavian Feugueur
*/

#include "minishell.h"

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (i == n)
    i--;
  return (s1[i] - s2[i]);
}
