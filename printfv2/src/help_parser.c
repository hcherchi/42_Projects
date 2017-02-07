#include "ft_printf.h"

int   fill_width(const char *input, int count, t_format *format)
{
  char *nbr;
  int save;
  int value;

  save = count;
  while (ft_isdigit(input[count]))
    count++;
  if (count - save)
  {
    nbr = ft_strsub(input, save, count - save);
    value = ft_atoi(nbr);
    if (ft_strlen(nbr))
      format->width = value;
    free(nbr);
  }
  return (count - save);
}

int   fill_accur(const char *input, int count, t_format *format)
{
  char *nbr;
  int save;
  int value;

  if (input[count] == '.')
  {
    count++;
    save = count;

    while (ft_isdigit(input[count]) || input[count] == '-')
      count++;
    nbr = ft_strsub(input, save, count - save);
    value = ft_atoi(nbr);
    format->accur = value > 0 ? value : 0;
    free(nbr);
    return (count - save + 1);
  }
  return (0);
}

int   fill_flag(const char *input, int count, t_format *format)
{
  int save;

  save = count;
  while (input[count] && ft_strchr("hjlz", input[count]))
  {
    if (!format->flag)
    {
      if (ft_strchr("hl", input[count]) && input[count + 1] == input[count])
      {
        format->flag = ft_toupper(input[count]);
        count += 2;
      }
      else
      {
        format->flag = input[count];
        count++;
      }
    }
    else
      count++;
  }
  return (count - save);
}

int   fill_attribut(const char *input, int count, t_format *format)
{
  int save;

  save = count;
  while (input[count] && ft_strchr("# 0-+", input[count]))
  {
    if (input[count] == '#')
      format->hash = 1;
    else if (input[count] == ' ')
      format->space = 1;
    else if (input[count] == '0')
      format->zero = 1;
    else if (input[count] == '-')
      format->moins = 1;
    else if (input[count] == '+')
      format->plus = 1;
    count++;
  }
  return (count - save);
}

int   fill_type(const char *input, int count, t_format *format)
{
  if (input[count] && ft_strchr("sSpdDioOuUxXcC%", input[count]))
  {
    format->type = input[count];
    return (1);
  }
  else
    return (0);
}
