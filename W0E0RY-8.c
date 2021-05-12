#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define SZALAK 10
#define N 1000


//Globális változók:
int count=0;
int maxT[10]={0,0,0,0,0,0,0,0,0,0};

int main() {
    int i=0;

    //Random számok generálása:

    int tomb[N];
    srand(time(NULL));

        for (i = 0; i < N; i++)
            tomb[i] = rand() % 1000 + 1;

    //Szál létrehozása:

      pthread_t threads[SZALAK];
      int szal_args[SZALAK];
      int eredmeny;
      unsigned index;

      //Szálak létrehozása 0-99-ig (Felosztása 10 szálra):
      int oegy = 0, oketto = 99;

      for (index = 0; index < SZALAK; ++index) {
        szal_args[index] = index;

        printf("\nSzal: %d", index+1);

        eredmeny = pthread_create(&threads[index], NULL, max(oegy, oketto, tomb), &szal_args[index]);
        assert(!eredmeny);
        oegy+=100;
        oketto+=100;
        count++;
      }

      //Kiiratások
        for(;i<10;i++){
            printf("\nMax: %d",maxT[i]);
            printf("\nIndexe: %d.",i+1);
        }

        printf("\n");
        printf("\nGeneralt tomb legnagyobbja:");
        max(0,10,maxT);


}

//Maximum keresõ függvény:
void max(int oegy, int oketto, int tomb[]){

    int max=0;
    int i;
    printf("\n1. index: %d",oegy);
    printf("\n2. index: %d",oketto);

    for (i = oegy; i < oketto; i++) {
        if(tomb[i] > max) {
           max  = tomb[i];
        }
    }
    maxT[count]=max;
    printf("\nKeresett maximum : %d", max);
}
