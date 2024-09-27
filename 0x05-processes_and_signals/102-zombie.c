#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * infinite_while - runs an infinite loop.
 * 
 * Return: 0 on success.
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

int main(void)
{
    pid_t pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid > 0)
        {
            printf("Zombie process created, PID: %d\n", pid);
        }
        else if (pid == 0)
        {
            // Child process exits immediately to become a zombie
            return (0);
        }
        else
        {
            // Fork failed
            perror("Fork failed");
            return (1);
        }
    }

    infinite_while();
    return (0);
}
