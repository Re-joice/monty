#include "monty.h"

/**
 * mul_stack - multiplies top two stack elements
 * @stack: stack
 * @line_number: current line number
 */
void mul_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,
			"L%u: can't mul, stack too short\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;

	free(temp);
}
