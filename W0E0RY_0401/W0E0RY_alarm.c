#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void do_none();
void do_int();

int main(void)
{
    unsigned sec = 1;
    signal(SIGINT, do_int);

    for (int i = 1; i < 8 ;i++)
    {
        alarm(sec);
        signal(SIGALRM, do_none);
        printf("%d wait till?\n", i);
        pause();
    }
}

void do_nothing() { }

void do_int()
{
    printf("int jott");
    signal(SIGINT, SIG_IGN);
}