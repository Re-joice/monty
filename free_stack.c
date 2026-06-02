#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: stack head
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
