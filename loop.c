#include "main.h"

/**
 * execute_command - gets the command
 * @command: pointer to the command
 */

void execute_command(char *command)
{
	pid_t childPid = fork();

	if (childPid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (childPid == 0)
	{
		char *arguments[2];

		arguments[0] = command;
		arguments[1] = NULL;
		execvp(arguments[0], arguments);
		perror("Execution failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * process_input - initialize process
 * @input: pointer to file
 */

void process_input(FILE *input)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t charactersRead;

	while ((charactersRead = getline(&line, &bufsize, input)) != -1)
	{
		if (line[charactersRead - 1] == '\n')
			line[charactersRead - 1] = '\0';
		if (strcmp(line, "exit") == 0)
			break;
		execute_command(line);
		printf("#cisfun");
		fflush(stdout);
	}
	free(line);
}
/**
 * loop - loop console
 */

void loop(void)
{
	if (isatty(STDIN_FILENO))
	{
		char *line = NULL;
		size_t bufsize = 0;
		ssize_t charactersRead;

		printf("#cisfun$");
		fflush(stdout);
		while ((charactersRead = getline(&line, &bufsize, stdin)) != -1)
		{
			if (line[charactersRead - 1] == '\n')
				line[charactersRead - 1] = '\0';
			if (strcmp(line, "exit") == 0)
				break;
			execute_command(line);
			printf("($)");
			fflush(stdout);
		}
		free(line);
		printf("\n");
	}
	else
	{
		process_input(stdin);
	}
}
