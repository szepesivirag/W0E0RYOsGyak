#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void Alarm(int sig);

int main(void)
{
    if (signal(SIGALRM, Alarm) == SIG_ERR)
    {
        printf("Nincs handler beallitva jelre!!\n");
        return 1;
    }

    pause();
    return 0;
}

void Alarm(int sig)
{
    printf("\nNincs blokkolodas!\n W0E0RY");
    exit(1);
}
