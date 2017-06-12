/*
** old_set_env.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Wed Jan 18 15:53:45 2017 Flavian Feugueur
** Last update Sun Jan 22 15:19:04 2017 Flavian Feugueur
*/

#include "minishell.h"

static int	find_envp(char **envp, char *path_env)
{
  int	i;
  int	n;

  i = n = 0;
  while (envp[i][n] != '=')
    n++;
  while (my_strncmp(path_env, envp[i], n) != 0 && envp[i] != NULL)
    {
      i++;
      if (envp[i] == NULL)
	return (-1);
      n = 0;
      while (envp[i][n] != '=')
	n++;
    }
  return (i);
}

void	old_set_env(char **envp, char *str, char *cmd, char *path_env)
{
  int	i;
  int	x;
  int	y;
  char	*tmp;

  i = y = 0;
  x = find_envp(envp, path_env);
  tmp = envp[x];
  envp[x] = malloc(sizeof(char) * my_strlen(cmd));
  while (tmp[y] != '=' && tmp[y] != '\0')
    {
      envp[x][y] = tmp[y];
      y++;
    }
  envp[x][y++] = '=';
  while (str[i] != '\0')
    envp[x][y++] = str[i++];
  free(path_env);
  free(str);
}
