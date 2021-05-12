#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int Arr[2];
    if (pipe(Arr) < 0)
    {
        perror("HIBA");
        exit(1);
    }

    int pid = fork();
    if (pid < 0)
        exit(2);

    if (pid == 0)
    {
        write(Arr[1], "W0E0RY", 128);
    } else if (pid > 0)
    {
        wait(NULL);

        char szBuffer[128];
        read(Arr[0], szBuffer, sizeof(szBuffer));
        printf("%s\n", szBuffer);
    }

    return 0;
}