#include <ft_printf>

void attribute_plus_space(t_format *format, char *nbr)
{
  if (nbr[0] !== '-')
    tmp[0] = '+'
}

void attribute_moins(t_format *format)
{
  if ()
}

void attribute_zero(t_format *format, char *nbr, char *tmp)
{
  int zero_nbr = format->accur - ft_strlen(nbr);
  int i = -1;
  int x = 0;

  if (tmp[0] == '+')
    i++;

  while (i++ <= zero_nbr)
    tmp[i] = 0

  while (x <= ft_strlen(nbr))
  {
    tmp[i] =  nbr[x];
    i++;
    x++;
  }
  tmp[i] = '\0';
}

void ft_attribute(t_format *format, char *nbr)
{
  char *tmp =  malloc(sizeof(char) * format->accur + 1);

  if (format->moins == 1)
    attribute_moins(format);
  if (format->plus == 1 || format->space == 1)
    attribute_plus_space(format, nbr ,&tmp);
  if (format->zero == 1)
    attribute_zero(format, nbr, &tmp);
//  if (format->attribut == '#')
//    attribute_hash();
  return(tmp);
}
