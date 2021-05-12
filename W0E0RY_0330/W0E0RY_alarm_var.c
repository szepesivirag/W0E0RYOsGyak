#include <unistd.h>
#include <signal.h>

void do_none();

int main(void)
{
    signal(SIGALRM, do_none);
    printf("%d wait till?\n");
    pause();
    printf("Alarm \n");
}

void do_none() {}