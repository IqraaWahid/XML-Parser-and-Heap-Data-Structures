#include <stdio.h> // standard library for input/output functions
#include <stdlib.h> //standard library for exit(), etc. functions
#include <ctype.h> // provides character handeliong functions like: isalpha()
#include <string.h> // provides string functions lie: strcmp() and strdup()

// functions implemented in stringStack.c for the stack:
extern char *  pop(); //removes the top string from the stack and returns it
extern void push(char *); // pushes a string onto the top of the stack
extern int isEmpty(); // returns 1 if stack is empty, else 0


int main(int argc, char * argv[])
{
  int ch; //stores each character read from the input
  char tag[100]; //array to store the current tag name being read
  int i; // initializing index variable for storing tag names
  
  //Read input character by character until end of file (EOF) has been reached
  while ((ch = getchar()) != EOF) {
	//skip any characters that are not letters, <, >, or /. This allows the while to not run for certain inputs like: spaces, punctuations, etc.
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue; //skip the loop body if condition above is true
      
    if(ch == '<'){ //indicates start of a tag
		ch = getchar(); //move to the next character after '<'
		
		int isEndTag = 0; // initially setting isEndTag to zero, and then updated value depending on whether it is an endTag or not
		
		//check if end tag
		if(ch == '/'){ // if the next character is '/', then this is an end tag
			isEndTag=1; // isEndTag = 1 now
			ch = getchar(); // move to the next character after '/'
		}
		
		//read tag name now which is a sequence of alphabetical characters
		i = 0; // setting index of tag array to zero, and starting at the beginning of 'tag' array
		while (isalpha(ch)){ // while the character is an alphabet:
			tag[i++] = ch; // add each character into the tag array, simultaneously increasing the tag array
			ch = getchar(); // store next character into variable 'ch'
		}
		tag[i] = '\0'; //terminates the string
		
		//skips all characters until closing, '>' found
		while (ch!= '>' && ch != EOF){ // 
			ch = getchar();
		}
		
		//process tag depending on whether its start tag or end tag
		if(!isEndTag){
			// start-tag:
				//push tag onto the stack
			push(strdup(tag)); //so each tag pushed into the stack has its own seperate memory by using 'strdup', so even if the tag array is overwritten with new elements later, the old enteries of the stack won't change
		}
		else{ // else if end-tag has been reached
			//end tag --> pop and compare
			//pop the top tag from the stack (stack follows LIFO) and compare it with this end tag
			char * topTag = pop(); //So topTag now contains the most recently pushed start tag, which should match the current end tag.
			
			if (topTag == NULL){ // if stack is empty, pop() returns null
				printf("Invalid XML\n"); //since there is an end tag with no matching start tag, the XML is invalid
				exit(0); //program terminates
			}
			
			//compare the popped start-tag with the current end tag
			// strcmp function returns 0 is the strings are the same 
			if(strcmp(topTag, tag) != 0){ // if the popped start-tag and the current end tag are not the same
				printf("Invalid XML\n"); // XML is invalid
				exit(0); //exit program
			}
		}
	}
  }
  
  //after processing all input, check if the stack is empty 
  if(isEmpty()){ // if stack is empty
	  printf("Valid XML\n"); // All tags matches correctly
  }
  
  // if the stack is NOT empty
  else{
	  printf("Invalid XML\n"); //there are unmtached start tags, XML is invalid
  }
  
  exit(0); //exit the program
}
