#include "monty.h"

/**
 * is_number - checks if string is an integer
 * @str: string
 *
 * Return: 1 if integer, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i++;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}

/**
 * execute_opcode - executes opcode
 * @opcode: opcode
 * @arg: argument
 * @line_number: line number
 * @stack: stack
 * @file: file pointer
 *
 * Return: 0
 */
int execute_opcode(char *opcode, char *arg,
	unsigned int line_number,
	stack_t **stack, FILE *file)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (!is_number(arg))
		{
			fprintf(stderr,
				"L%u: usage: push integer\n",
				line_number);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}

		push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap_stack(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add_stack(stack, line_number);
	}
	else
	{
		fprintf(stderr,
			"L%u: unknown instruction %s\n",
			line_number, opcode);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (0);
}

/**
 * main - Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[256];
	char *opcode;
	char *arg;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr,
			"Error: Can't open file %s\n",
			argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;

		opcode = strtok(line, " \t\n");

		if (opcode == NULL)
			continue;

		arg = strtok(NULL, " \t\n");

		execute_opcode(opcode, arg,
			line_number, &stack, file);
	}

	fclose(file);
	free_stack(stack);

	return (0);
}
