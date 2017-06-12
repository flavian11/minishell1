/*
** my_exec.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Mon Jan  9 21:32:24 2017 Flavian Feugueur
** Last update Sun Jan 22 20:04:53 2017 Flavian Feugueur
*/

#include "minishell.h"

static int	find_path(char **envp)
{
  int	i;

  i = 0;
  while (my_strncmp(envp[i], "PATH=", 5) != 0)
    {
      if (envp[i] == NULL)
	return (-1);
      i++;
    }
  return (i);
}

static char	*my_new_path(char *cmd, char **str, char **envp, int n)
{
  int	y;
  int	i;
  int	x;
  int	nb_p;

  i = nb_p = 0;
  if ((x = find_path(envp)) == -1)
    my_putstr("Command not found\n");
  if ((str[0] = malloc(sizeof(char) * my_strlen(cmd) + my_strlen(envp[x]) + 1))
      == NULL)
    return (NULL);
  y = 5;
  while (envp[x][y] != '\0' && nb_p < n)
    if (envp[x][y++] == ':')
      nb_p++;
  if (envp[x][y] == '\0')
    return (NULL);
  while (envp[x][y] != '\0' && envp[x][y] != ':')
    str[0][i++] = envp[x][y++];
  str[0][i++] = '/';
  y = 0;
  while (cmd[y] != '\0' && cmd[y] != '\n')
    str[0][i++] = cmd[y++];
  str[0][i] = '\0';
  return (str[0]);
}

void	my_exec(char *cmd, char **str, char **envp)
{
  int	n;
  char	*tmp;

  n = 0;
  tmp = my_strcp(str[0]);
  if (my_strncmp(cmd, "ls", 2) == 0)
    str = my_ls_option(envp, str);
  while (access(str[0], X_OK) == -1)
    {
      if (cmd[0] == '/' || cmd[0] == '.')
	{
	  my_putstr(str[0]);
	  my_putstr(": Command not found.\n");
	  n = -1;
	  break;
	}
      if ((str[0] = my_new_path(tmp, str, envp, n++)) == NULL)
	{
	  my_putstr(tmp);
	  my_putstr(": Command not found.\n");
	  n = -1;
	  break;
	}
    }
  (n != -1) ? execve(str[0], str, envp) : 0;
}
