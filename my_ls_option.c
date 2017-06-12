/*
** my_ls_option.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Fri Jan 13 16:30:00 2017 Flavian Feugueur
** Last update Sun Jan 22 15:15:32 2017 Flavian Feugueur
*/

#include "minishell.h"

static int	find_envp(char **envp)
{
  int	i;

  i = 0;
  while (my_strncmp(envp[i], "LS_OPTIONS", 10) && envp[i] != NULL)
    i++;
  return (i);
}

static int	nb_of_arg(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i] != '=' && str[i] != '\0')
    i++;
  i++;
  while (str[i] != '=' && str[i] != '\0')
    {
      if (str[i] == ' ')
	nb++;
      i++;
    }
  return (nb);
}

static char	**init_str(char **str, char **envp, int y, int i)
{
  int	x;
  int	iy;

  iy = 0;
  x = find_envp(envp);
  while (envp[x][y] != '\0' && envp[x][y] != '=')
    {
      str[i] = malloc(sizeof(char) * my_strlen(envp[x]));
      while (envp[x][y] != '=' && envp[x][y] != ' ' && envp[x][y] != '\0')
	{
	  str[i][iy] = envp[x][y];
	  iy++;
	  y++;
	}
      str[i][iy] = '\0';
      if (envp[x][y] == ' ')
	y++;
      iy = 0;
      i++;
    }
  str[i] = NULL;
  return (str);
}

char	**my_ls_option(char **envp, char **str)
{
  int	x;
  int	i;
  char	**tmp;

  i = 0;
  tmp = my_tabcp(str);
  x = find_envp(envp);
  str = malloc(sizeof(char *) * (my_tablen(tmp) + nb_of_arg(envp[x]) + 1));
  while (tmp[i] != NULL)
    {
      str[i] = malloc(sizeof(char) * my_strlen(tmp[i]));
      str[i] = my_strcp(tmp[i]);
      i++;
    }
  str = init_str(str, envp, 11, i);
  return (str);
}
