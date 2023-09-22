#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS "\n\t\a\b"

extern char **op_token;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*INTERPRETER*/
void set_operror(int error_code);
int check_mode(stack_t *stack);
unsigned int token_arr_len(void);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
void free_tokens(void);
int run_monty(FILE *script_fd);

/*CUSTOM LIBRARY FUNCTIONS*/
char **strtow(char *str, char *delims);
char *get_int(int n);

/*ERRORS*/
int malloc_error(void);
int no_interror(unsigned int lnumber);
int usage_error(void);
int f_open_error(char *filename);
int unknown_operror(char *opcode, unsigned int lnumber);
int no_interror(unsigned int lnumber);
int pop_error(unsigned int lnumber);
int pint_error(unsigned int lnumber);
int short_stack_error(unsigned int lnumber, char *op);
int div_error(unsigned int lnumber);
int pchar_error(unsigned int lnumber, char *message);

/*FUNCTIONS*/
void push(stack_t **top, unsigned int lnumber);
void pall(stack_t **top, unsigned int lnumber);
void pint(stack_t **stack, unsigned int lnumber);
void pop(stack_t **stack, unsigned int lnumber);
void swap(stack_t **stack, unsigned int lnumber);
void add(stack_t **stack, unsigned int lnumber);
void nop(stack_t **stack, unsigned int lnumber);
void sub(stack_t **stack, unsigned int lnumber);
void my_div(stack_t **stack, unsigned int lnumber);
void mul(stack_t **stack, unsigned int lnumber);
void mod(stack_t **stack, unsigned int lnumber);
void pchar(stack_t **stack, unsigned int lnumber);
void pstr(stack_t **stack, unsigned int lnumber);
void rotl(stack_t **stack, unsigned int lnumber);
void rotr(stack_t **stack, unsigned int lnumber);
void stack(stack_t **stack, unsigned int lnumber);
void queue(stack_t **stack, unsigned int lnumber);

#endif /*MAIN_H*/
