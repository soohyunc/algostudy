/*
 * http://hackerslab.eu/blog/2016/11/괄호-묶음-점검하기/
 */

#include<stdio.h>
#include<stdlib.h>

#define true  1
#define false 0

struct node {
	char data;
	struct node *next;
};

void push(struct node** ref, int item) {
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	if (new_node == NULL) {
		return;
	}

	new_node->data = item;
	new_node->next = *ref;
	*ref = new_node;
}

char pop(struct node** ref) {
	char ret;
	struct node *top;

	top = *ref;
	ret = top->data;
	*ref = top->next;
	free(top);

	return ret;
}

int isMatched(char a, char b) {
	if (a == '{' && b == '}')
		return true;
	else if (a == '(' && b == ')')
		return true;
	else if (a == '[' && b == ']')
		return true;
	else
		return false;
}

int hasBalancedBrackets(char* str)
{
	struct node *stack = NULL;

	for (int i = 0; str[i] != '\0'; i++) {

		// push
		if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
			push(&stack, str[i]);
		}

		// pop
		if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
			// w/o pair
			if (stack == NULL)
				return false;
			// with pair
			else if (!isMatched(pop(&stack), str[i]))
				return false;
		}
	}

	if (stack == NULL)
		return true;
	else
		return false;
}

int main()
{
	//char exp[100] = "(h[e{lo}!]~()()()(";
	//char exp[100] = "{()}[]";
	char exp[100] = "[](){}<>";
	if (hasBalancedBrackets(exp))
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
