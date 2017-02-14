#include "ft_printf.h"

char *l_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  converted_arg = NULL;
  if (format->type == 'd' || format->type == 'i')
    converted_arg = itoa_10(va_arg(ap, long int), format);
  else if (format->type == 'o')
    converted_arg = uitoa_base(va_arg(ap, unsigned long int), 8, 0, format);
  else if (format->type == 'u')
    converted_arg = uitoa_base(va_arg(ap, unsigned long int), 10, 0, format);
  else if (format->type == 'x')
    converted_arg = uitoa_base(va_arg(ap, unsigned long int), 16, 0, format);
  else if (format->type == 'X')
    converted_arg = uitoa_base(va_arg(ap, unsigned long int), 16, 1, format);
  else
    converted_arg = ft_strdup("cas non gere");
  return (converted_arg ? converted_arg : ft_strdup("(null)"));
}

char *ll_convert(t_format *format, va_list ap)
{
  char *converted;

  if (format->type == 'd' || format->type == 'i')
    converted = itoa_10(va_arg(ap, long long int), format);
  else if (format->type == 'o')
    converted = uitoa_base(va_arg(ap, unsigned long long int), 8, 0, format);
  else if (format->type == 'u')
    converted = uitoa_base(va_arg(ap, unsigned long long int), 10, 0, format);
  else if (format->type == 'x')
    converted = uitoa_base(va_arg(ap, unsigned long long int), 16, 0, format);
  else if (format->type == 'X')
    converted = uitoa_base(va_arg(ap, unsigned long long int), 16, 1, format);
  else
    converted = ft_strdup("cas non gere");
  return (converted ? converted : ft_strdup("(null)"));
}

char *j_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = itoa_10(va_arg(ap, intmax_t), format);
  else if (format->type == 'o')
    converted_arg = uitoa_base(va_arg(ap, uintmax_t), 8, 0, format);
  else if (format->type == 'u')
    converted_arg = uitoa_base(va_arg(ap, uintmax_t), 10, 0, format);
  else if (format->type == 'x')
    converted_arg = uitoa_base(va_arg(ap, uintmax_t), 16, 0, format);
  else if (format->type == 'X')
    converted_arg = uitoa_base(va_arg(ap, uintmax_t), 16, 1, format);
  else
    converted_arg = ft_strdup("cas non gere");
  return (converted_arg ? converted_arg : ft_strdup("(null)"));
}

char *z_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = itoa_10(va_arg(ap, ssize_t), format);
  else if (format->type == 'o')
    converted_arg = uitoa_base(va_arg(ap, size_t), 8, 0, format);
  else if (format->type == 'u')
    converted_arg = uitoa_base(va_arg(ap, size_t), 10, 0, format);
  else if (format->type == 'x')
    converted_arg = uitoa_base(va_arg(ap, size_t), 16, 0, format);
  else if (format->type == 'X')
    converted_arg = uitoa_base(va_arg(ap, size_t), 16, 1, format);
  else
    converted_arg = ft_strdup("cas non gere");
  return (converted_arg ? converted_arg : ft_strdup("(null)"));
}
