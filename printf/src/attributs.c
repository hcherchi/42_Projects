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
  if (format->hash == 0 && format->moins == 0 && format->zero == 0)
    tmp[h] = '\0';
}

void attribute_moins(t_format *format, char *nbr, char *tmp)
{
  int zero_nbr = format->width - ft_strlen(nbr);
  int i = 0;
  int x = 0;

  if ((format->type == 'x' || format->type == 'X') && format->hash != 0)
    zero_nbr -= 2;
  if ((format->type == 'o' || format->type == 'O') && format->hash != 0)
    zero_nbr -= 1;

  if (tmp[i] == '+')
    i++;
  if (tmp[i] == '0')
    i++;
  if (tmp[i] == 'x' || tmp[i] == 'X')
    i++;


  while (x <= ft_strlen(nbr))
  {
    tmp[i] =  nbr[x];
    i++;
    x++;
  }
i--;
  x = 0;
  while (x < zero_nbr)
  {
    tmp[i] = ' ';
    i++;
    x++;
  }
  tmp[i] = '\0';

}

void attribute_hash(t_format *format, char *tmp, char *nbr)
{
  int x = 0;
  int h = 0;
  int zero_nbr = format->width - ft_strlen(nbr);

  if (format->type == 'x' || format->type == 'X')
    zero_nbr -= 2;
  if (format->type == 'o' || format->type == 'O')
    zero_nbr -= 1;

  while (h < zero_nbr && format->moins == 0)
  {
    tmp[h] = ' ';
    h++;
  }

  if ((format->type == 'x' || format->type == 'X' || format->type == 'p') && nbr[0] !='0' )
  {
    tmp[h] = '0';
    tmp[h + 1] = ft_strchr("xp", format->type) ? 'x' : 'X';
    h+=2;
  }
  if (format->type == 'o' || format->type == 'O')
  {
    tmp[h] = '0';
    h++;
  }
  while (nbr[x])
  {
    tmp[h] = nbr[x];
    x++;
    h++;
  }
  if (format->moins == 0 && format->zero == 0)
    tmp[h] = '\0';
}

void attribute_zero(t_format *format, char *nbr, char *tmp)
{
  int zero_nbr = format->width - ft_strlen(nbr);
  int i = 0;
  int x = 0;

  if (format->type == 'x' || format->type == 'X' || format->type == 'p')
  {
    tmp[i] = '0';
    tmp[i + 1] = ft_strchr("xp", format->type) ? 'x' : 'X';
    i+=2;
  }
  if (format->type == 'o' || format->type == 'O')
  {
    tmp[i] = '0';
    i++;
  }

  if (tmp[0] == '+')
    i++;
  if (nbr[0] == '-')
  {
    tmp[0]= '-';
    zero_nbr++;
    i++;
    x++;
  }
  while (i < zero_nbr)
  {
    tmp[i] = '0';
    i++;
  }

  while (x <= ft_strlen(nbr))
  {
    tmp[i] = nbr[x];
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
    attribute_hash(format, tmp, nbr);
  if (format->moins != 0)
    attribute_moins(format, nbr, tmp);
  if (format->zero != 0)
    attribute_zero(format, nbr, tmp);

  return(tmp);
}
