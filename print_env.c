/*
** print_env.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Tue Jan  3 16:52:52 2017 Flavian Feugueur
** Last update Sun Jan 22 15:18:24 2017 Flavian Feugueur
*/

#include "minishell.h"

void   print_env(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      my_putstr(envp[i]);
      my_putstr("\n");
      i++;
    }
}
