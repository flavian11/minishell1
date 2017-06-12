/*
** my_str_to_word_tab.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Tue Jan  3 14:52:14 2017 Flavian Feugueur
** Last update Sun Jan 22 21:40:29 2017 Flavian Feugueur
*/

#include "minishell.h"

int	count_word(char *str)
{
  int	nb;
  int	i;

  i = 1;
  nb = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' && str[i - 1] != ' ')
	nb++;
      i++;
    }
  return (nb);
}

int	count_letter(char *str, int i)
{
  int	nb;

  nb = 0;
  while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
    {
      nb++;
      i++;
    }
  return (nb);
}

char	**my_str_to_word_tab(char *str)
{
  char	**res;
  int	i;
  int	i_str;
  int	letter;
  int	let2;

  i = letter = i_str = 0;
  res = malloc(sizeof(char *) * (count_word(str) + 1));
  while (i < count_word(str))
    {
      let2 = count_letter(str, i_str);
      res[i] = malloc(sizeof(char) * let2 + 1);
      letter = 0;
      while (letter < let2)
	{
	  res[i][letter] = str[i_str++];
	  letter++;
	}
      res[i][letter] = '\0';
      i++;
      while (str[i_str] == ' ')
	i_str++;
    }
  res[i] = NULL;
  return (res);
}
