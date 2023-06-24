#include "monty.h"
#include <string.h>

/* Stack opcodes */
const instruction_t opcodes[] = {
	{"push", f_push},
	{"pall", f_pall},
	{"pint", f_pint},
	{"pop", f_pop},
	{"swap", f_swap},
	{"add", f_add},
	{"nop", f_nop},
	{NULL, NULL}};

/**
 * execute - executes the instructions in the file
 * @content: content of the file
 * @stack: stack head
 * @counter: current line number
 * @file: file to execute
 * Return: 0
 *
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char *opcode = strtok(content, " \t\n");
	char *arg = strtok(NULL, " \t\n");
	void (*func)(stack_t **, unsigned int) = NULL;
	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			func = opcodes[i].fct;
			break;
		}
	}

	if (!func)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	globalVar.arg = arg;
	func(stack, counter);
	return (0);
}*/

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;


	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	globalVar.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
