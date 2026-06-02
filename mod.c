#include "monty.h"

/**
 * mod_stack - computes remainder of division
 * @stack: stack
 * @line_number: current line number
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,
			"L%u: can't mod, stack too short\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;

	free(temp);
}
