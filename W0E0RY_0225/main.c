#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fPointer = fopen("information.txt", "w+");
    fprintf(fPointer, "Szepesi Gl�ria - W0E0RY - Programtervez� Informatikus- OS BSc");
    fclose(fPointer);
    return 0;
}
