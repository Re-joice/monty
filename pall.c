#include "monty.h"

/**
 * pall - prints all stack values
 * @stack: pointer to stack
 */
void pall(stack_t **stack)
{
	stack_t *temp;

	temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
