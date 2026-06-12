#include "monty.h"

/**
 * rotr_stack - rotates stack to the bottom
 * @stack: stack
 * @line_number: line number
 */
void rotr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;

	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
