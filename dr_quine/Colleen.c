#include <stdio.h>

/* This is a lonely comment */

void copy(void) {
char *toPrint = "#include <stdio.h>%c%c/* This is a lonely comment */%c%cvoid copy(void) {%cchar *toPrint = %c%s%c;%cprintf(toPrint, 10, 10, 10, 10, 10, 34, toPrint, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main(void) {%ccopy();%c/* This is the main comment */%creturn (0);%c}%c";
printf(toPrint, 10, 10, 10, 10, 10, 34, toPrint, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main(void) {
copy();
/* This is the main comment */
return (0);
}
