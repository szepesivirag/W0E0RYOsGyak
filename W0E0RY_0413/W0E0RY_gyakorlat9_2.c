  
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define TMP "/tmp/W0E0RY"

int main(void)
{
    mkfifo(TMP, 0666);
    int pid = fork();
    if (pid < 0)
        exit(2);

    int fileD;
    if (pid == 0)
    {
        fileD = open(TMP, O_WRONLY);

        char szInput[] = "Input";
        write(fileD, szInput, sizeof(szInput));
    } else if (pid > 0 )
    {
        fileD = open(TMP, O_RDONLY);

        char szBuffer[128];
        read(fileD, szBuffer, sizeof(szBuffer));
        printf("%s\n", szBuffer);
        close(fileD);
    }

    return 0;
}