#include "monty.h"

/**
 * sub_stack - subtracts the top element from the second top element
 * @stack: pointer to stack
 * @line_number: line number
 */
void sub_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,
			"L%u: can't sub, stack too short\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;

	free(temp);
}
