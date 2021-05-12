#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void InterruptHandler(int sig);
void QuitHandler(int sig);

unsigned int Interrupts = 0;

int main(void)
{
    if (signal(SIGINT, InterruptHandler) == SIG_ERR)
    {
        printf("No handler sign!\n");
        return 0;
    }

    if (signal(SIGQUIT, QuitHandler) == SIG_ERR)
    {
        printf("No handler sign!\n");
        return 0;
    }

    while(Interrupts < 2)
    {
        printf("Watiting\n");
        sleep(1);
    }

    printf("Second sign!");
    return 0;
}

void InterruptHandler(int sig)
{
    printf("SIGINT signal: %d\n", sig);
    Interrupts++;
}

void QuitHandler(int sig)
{
    printf("SIGQUIT signal: %d\n", sig);
}