#include "main.h"

int main(int argc, char **argv)
{
    (void)argc, (void)argv;
    char *buf = NULL, *token, *path;
    size_t count = 0;
    ssize_t nread;
    pid_t child_pid;
    int i, status;
    char **array;

    while (1)
    {
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "KShell$ ", 9);
        }

        nread = getline(&buf, &count, stdin);

        if (nread ==  -1)
        {
            exit(-1);
        }

        token = strtok(buf, " \n");

        array = malloc(sizeof(char*) * 1024);
        i = 0;

        while (token)
        {
            array[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }

        array[i] = NULL;

        path = get_file_path(array[0]); /* Get the absolute path using the function */

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Failed to create.");
            exit (41);
        }

        if (child_pid == 0)
        {
            if (execve(path, array, NULL) == -1) /* Replace the first argument with that executable file */
            {
                perror("Failed to execute");
                exit(97);
            }
        }
        else
    {
            wait(&status);
        }
    }
    free(path);
    free(buf);
    return (0);
}
