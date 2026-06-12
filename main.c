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
	{
		if (str[1] == '\0')
			return (0);
		i++;
	}

	while (str[i])
	{
		if (!isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}

	return (1);
}

/**
 * execute_basic - executes basic opcodes
 * @opcode: opcode
 * @arg: argument
 * @line_number: current line number
 * @stack: stack
 * @file: file pointer
 *
 * Return: 1 if opcode found, 0 otherwise
 */
int execute_basic(char *opcode, char *arg,
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
		return (1);
	}
	if (strcmp(opcode, "pall") == 0)
		return (pall(stack), 1);
	if (strcmp(opcode, "pint") == 0)
		return (pint(stack, line_number), 1);
	if (strcmp(opcode, "pop") == 0)
		return (pop(stack, line_number), 1);

	return (0);
}

/**
 * execute_advanced - executes advanced opcodes
 * @opcode: opcode
 * @line_number: current line number
 * @stack: stack
 *
 * Return: 1 if opcode found, 0 otherwise
 */
int execute_advanced(char *opcode,
	unsigned int line_number,
	stack_t **stack)
{
	if (strcmp(opcode, "swap") == 0)
		return (swap_stack(stack, line_number), 1);
	if (strcmp(opcode, "add") == 0)
		return (add_stack(stack, line_number), 1);
	if (strcmp(opcode, "nop") == 0)
		return (nop(stack, line_number), 1);
	if (strcmp(opcode, "sub") == 0)
		return (sub_stack(stack, line_number), 1);
	if (strcmp(opcode, "div") == 0)
		return (div_stack(stack, line_number), 1);
	if (strcmp(opcode, "mul") == 0)
		return (mul_stack(stack, line_number), 1);
	if (strcmp(opcode, "mod") == 0)
		return (mod_stack(stack, line_number), 1);
	if (strcmp(opcode, "pchar") == 0)
		return (pchar_stack(stack, line_number), 1);
	if (strcmp(opcode, "pstr") == 0)
		return (pstr_stack(stack, line_number), 1);
	if (strcmp(opcode, "rotl") == 0)
		return (rotl_stack(stack, line_number), 1);

	return (0);
}

/**
 * execute_opcode - executes opcode
 * @opcode: opcode
 * @arg: argument
 * @line_number: current line number
 * @stack: stack
 * @file: file pointer
 *
 * Return: 0
 */
int execute_opcode(char *opcode, char *arg,
	unsigned int line_number,
	stack_t **stack, FILE *file)
{
	if (execute_basic(opcode, arg,
		line_number, stack, file))
		return (0);

	if (execute_advanced(opcode,
		line_number, stack))
		return (0);

	fprintf(stderr,
		"L%u: unknown instruction %s\n",
		line_number, opcode);
	fclose(file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
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
	char *opcode, *arg;
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

		if (opcode == NULL || opcode[0] == '#')
			continue;

		arg = strtok(NULL, " \t\n");
		execute_opcode(opcode, arg,
			line_number, &stack, file);
	}

	fclose(file);
	free_stack(stack);

	return (0);
}
