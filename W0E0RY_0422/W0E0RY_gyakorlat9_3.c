#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

//int kill(pid_t pid, int sig);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Hasznalat: ./W0E0RY_gyakorlat9_3 PID\n");
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);
    kill(pid, SIGALRM);
    return 0;
}
