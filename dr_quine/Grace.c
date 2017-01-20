#include <stdio.h>

/* This is a lonely comment */

#define copy(void) int main() { FILE *fd = fopen("Grace_kid.c", "w+"); char *toPrint = "#include <stdio.h>%c%c/* This is a lonely comment */%c%c#define copy(void) int main() { FILE *fd = fopen(%cGrace_kid.c%c, %cw+%c); char *toPrint = %c%s%c; fprintf(fd, toPrint, 10, 10, 10, 10, 34, 34, 34, 34, 34, toPrint, 34, 10, 10, 10); }%c%ccopy();%c"; fprintf(fd, toPrint, 10, 10, 10, 10, 34, 34, 34, 34, 34, toPrint, 34, 10, 10, 10); }

copy();
