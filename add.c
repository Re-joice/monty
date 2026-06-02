#include "monty.h"

/**
 * add_stack - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: current line number
 */
void add_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,
			"L%u: can't add, stack too short\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	(*stack)->prev = NULL;

	free(temp);
}
