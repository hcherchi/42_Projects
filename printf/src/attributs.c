#include "ft_printf.h"
#include <stdio.h>

void attribute_plus_space(t_format *format, char *nbr, char *tmp)
{
  int x = 0;
  int h = 0;

  if (nbr[h] != '-')
  {
    tmp[h] = format->plus != 0 ? '+' : ' ';
    h++;
  }

  while (nbr[x])
  {
    tmp[h] = nbr[x];
    x++;
    h++;
  }
  tmp[h] = '\0';
}

void attribute_moins(t_format *format, char *nbr, char *tmp)
{
  int space_nbr = format->width - ft_strlen(nbr);
  int i = 0;
  int x = 0;

  if (tmp[0] == '+')
    i++;
  if (tmp[0] == '0')
    i++;
  if (tmp[1] == 'x' || tmp[1] == 'X' )
    i++;

  while (x <= ft_strlen(nbr))
  {
    tmp[i] =  nbr[x];
    i++;
    x++;
  }
  i--;
  x = 0;
  while (x < space_nbr)
  {
    tmp[i] = ' ';
    i++;
    x++;
  }
  tmp[i] = '\0';

}

void attribute_hash(t_format *format, char *tmp)
{
  if (format->type == 'x' || format->type == 'X')
  {
    tmp[0] = '0';
    tmp[1] = format->type == 'x' ? 'x' : 'X';
  }
  if (format->type == 'o' || format->type == 'O')
    tmp[0] = '0';

}

void attribute_zero(t_format *format, char *nbr, char *tmp)
{
  int zero_nbr = format->width - ft_strlen(nbr);
  int i = 0;
  int x = 0;

  if (tmp[0] == '+')
    i++;

  while (i < zero_nbr)
  {
    tmp[i] = '0';
    i++;
  }

  while (x <= ft_strlen(nbr))
  {
    tmp[i] =  nbr[x];
    i++;
    x++;
  }
  tmp[i] = '\0';
}

char *no_attribute(t_format *format, char *nbr, char *tmp)
{
  int zero_nbr = format->width - ft_strlen(nbr);
  int i = 0;
  int x = 0;

  if (tmp[0] == '+')
    i++;

  while (i < zero_nbr)
  {
    tmp[i] = ' ';
    i++;
  }

  while (x <= ft_strlen(nbr))
  {
    tmp[i] =  nbr[x];
    i++;
    x++;
  }
  tmp[i] = '\0';
  return(tmp);
}

char *ft_attribute(t_format *format, char *nbr)
{
  char *tmp =  malloc(sizeof(char) * (format->width + ft_strlen(nbr) + 4));

  if (format->plus == 0 && format->space == 0 && format->hash == 0 && format->moins == 0 && format->zero == 0)
    return(no_attribute(format, nbr, tmp));
  if (format->plus != 0 || format->space != 0)
    attribute_plus_space(format, nbr, tmp);

  if (format->hash != 0)
    attribute_hash(format, tmp);

  if (format->moins != 0)
    attribute_moins(format, nbr, tmp);

  if (format->zero != 0)
    attribute_zero(format, nbr, tmp);

  return(tmp);
}
