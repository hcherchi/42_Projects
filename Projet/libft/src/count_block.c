#include "libft.h"

int     count_block(char *str, char c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            j++;
            while (str[i] == c)
                i++;
        }
        i++;
    }
    return (j);
}