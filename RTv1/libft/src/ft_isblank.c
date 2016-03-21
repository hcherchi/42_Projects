#include "libft.h"

int     ft_isblank(char c)
{
    return ((c == ' ' || c == '\n' || c == '\v' ||
            c == '\t' || c == '\r' || c == '\f'));
}