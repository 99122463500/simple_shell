#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024

/**
 * main - Simple UNIX command line interpreter.
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[MAX_BUFFER];
    pid_t child_pid;
    int status;

    while (1)
    {
        // Display prompt
        printf("$ ");

        // Read command from user
        if (fgets(buffer, MAX_BUFFER, stdin) == NULL)
        {
            if (feof(stdin))
            {
                printf("\n"); // Print a new line on Ctrl+D (EOF)
                exit(0);
            }
            perror("Error reading command");
            exit(EXIT_FAILURE);
        }

        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Fork a child process
        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) // Child process
        {
            // Execute the command using execvp
            if (execvp(buffer, NULL) == -1)
            {
                perror("Command not found");
                exit(EXIT_FAILURE);
            }
        }
        else // Parent process
        {
            // Wait for the child process to complete
            waitpid(child_pid, &status, 0);

            if (WIFEXITED(status))
            {
                // Child process exited normally
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
            else
            {
                // Child process exited abnormally
                printf("Child process exited abnormally\n");
            }
        }
    }

    return 0;
}

