#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
int i = 5;
char *exec;
char *filename;
char *toPrint;
char *script;
FILE *fd;
asprintf(&exec,"./Sully_%d",i);
if (ac > 0 && !strcmp(av[0], exec)) { i = i - 1; }
asprintf(&filename,"Sully_%d.c",i);
asprintf(&script,"gcc -Wall -Wextra -Werror -o Sully_%d Sully_%d.c && ./Sully_%d", i, i, i);
fd = fopen(filename, "w+");
toPrint = "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c%cint main(int ac, char **av)%c{%cint i = %d;%cchar *exec;%cchar *filename;%cchar *toPrint;%cchar *script;%cFILE *fd;%casprintf(&exec,%c./Sully_%c%c%c,i);%cif (ac > 0 && !strcmp(av[0], exec)) { i = i - 1; }%casprintf(&filename,%cSully_%c%c.c%c,i);%casprintf(&script,%cgcc -Wall -Wextra -Werror -o Sully_%c%c Sully_%c%c.c && ./Sully_%c%c%c, i, i, i);%cfd = fopen(filename, %cw+%c);%ctoPrint = %c%s%c;%cfprintf(fd, toPrint, 10, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 10, 10, 34, 37, 'd', 34, 10, 10, 34, 37, 'd', 34, 10, 34, 37, 'd', 37, 'd', 37, 'd', 34, 10, 34, 34, 10, 34, toPrint, 34, 10, 10, 10, 10, 10);%cfclose(fd);%cif (i != 0) { system(script); }%c}%c";
fprintf(fd, toPrint, 10, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 10, 10, 34, 37, 'd', 34, 10, 10, 34, 37, 'd', 34, 10, 34, 37, 'd', 37, 'd', 37, 'd', 34, 10, 34, 34, 10, 34, toPrint, 34, 10, 10, 10, 10, 10);
fclose(fd);
if (i != 0) { system(script); }
}
