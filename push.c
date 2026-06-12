

#include "monty.h"

extern int mode;

/**
 * push - pushes an element onto the stack or queue
 * @stack: pointer to stack
 * @value: integer value
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (mode == 0)
	{
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;

		*stack = new_node;
	}
	else
	{
		if (*stack == NULL)
		{
			*stack = new_node;
			return;
		}

		temp = *stack;
		while (temp->next)
			temp = temp->next;

		temp->next = new_node;
		new_node->prev = temp;
	}
}
