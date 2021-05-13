#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fPointer = fopen("information.txt", "w+");
    fprintf(fPointer, "Szepesi Glória - W0E0RY - Programtervezõ Informatikus- OS BSc");
    fclose(fPointer);
    return 0;
}
