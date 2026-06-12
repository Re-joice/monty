#include "monty.h"

/**
 * pstr_stack - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: line number
 */
void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
