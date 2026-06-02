#include "monty.h"

/**
 * swap_stack - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,
			"L%u: can't swap, stack too short\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next = second->next;

	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}
