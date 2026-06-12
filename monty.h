#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to previous element
 * @next: points to next element
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

void swap_stack(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub_stack(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);

void pchar_stack(stack_t **stack, unsigned int line_number);
void pstr_stack(stack_t **stack, unsigned int line_number);
void rotl_stack(stack_t **stack, unsigned int line_number);

void free_stack(stack_t *stack);
int is_number(char *str);

int execute_basic(char *opcode, char *arg,
	unsigned int line_number,
	stack_t **stack, FILE *file);

int execute_advanced(char *opcode,
	unsigned int line_number,
	stack_t **stack);

int execute_opcode(char *opcode, char *arg,
	unsigned int line_number,
	stack_t **stack, FILE *file);

#endif
