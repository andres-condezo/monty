#ifndef _MONTY_H_
#define _MONTY_H_

/*____ INCLUDES ____*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


/*____ STRUCTURES ____*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct var_s - contain the main variables of the Monty interpreter.
 * @queue: flag to determine if in stack vs queue mode.
 * @stack_len: length of the stack.
 */
typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;


/*____ MACROS ____*/

#define STACK 0
#define QUEUE 1

/*____ GLOBAL VARIABLES ____*/
extern var_t var;


/*____ PROTOTYPES ____*/

stack_t *add_node(stack_t **stack, const int n);
void get_operation(char *op, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void free_stack(int status, void *arg);
void fs_close(int status, void *arg);
void free_line_ptr(int status, void *arg);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H_ */
