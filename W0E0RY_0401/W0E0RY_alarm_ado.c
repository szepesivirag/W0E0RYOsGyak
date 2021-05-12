#include <sys/types.h>
#include <signal.h>

int main(int argc, char **argv)
{
    int pid;

    if (argc < 1)
    {
        perror("None to");
        exit(1);
    }

    pid = atoi(argv[1]);
    kill(pid, SIGALRM);
}