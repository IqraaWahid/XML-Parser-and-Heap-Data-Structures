#include <stdio.h>

/**
 *  The functions in this module implement a Stack data structure
 *  of char pointers (aka "strings").
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 strings can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
static int top = 0; // top is always the next empty spot
static char * stack[100];

/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */

char *  pop(){
	if (top == 0){ //if stack is empty:
		fprintf(stderr, "Error: stack is empty\n"); //printing error message into stderr
		return (char *) 0;  //returns NULL
	}
	//otherwise: if stack isn't empty
	top--; // remove the top string on the stack, by moving top down, this makes top point to an empty space (removing the previously top element). Although the previously top element still exists in memory until overwrited by a push() methods called in the future
	return stack[top]; // return the top string on the stack 
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(char * thing2push){
	if(top>=100){ // if top>=100 (meaning no more space left in the stack since the stack array allows max 100 elements)
		fprintf(stderr, "Error: stack is full\n"); //prints an error message into stderr
		return; // exits the push function
	}
	
	//otherwise, if their is space still left in the stack
	stack [top] = thing2push; // add item in the stack array, at the empty spot and top of the stack which is at index: top
	top++; // move top value one up, so it points at the next empty spot in the stack
	
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty(){
	if (top == 0){ // if stack is empty
	  return 1;
	}
	return 0;  //otherwise if stack is not empty
}
