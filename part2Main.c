#include <stdio.h> //allows the use of input/output functions like: printf, scanf, etc.
#include <stdlib.h> // allows use of exit(), etc.
// #include <ctype.h>

// Stack functions
extern void push(int);
extern int pop();
extern int isEmpty(void);

// Heap functions
extern void addHeap(int);
extern int heapDelete(void);
extern int heapSize(void);

// tells compiler that this function exists later
void printXML(int index);

int main(int argc, char * argv[]){ //main function where the program begins
    int value; // variable to store each number read from the input

    /* read input and add to heap */
    // while loop used to keep reading integers from input until their is no more input (EOF has been reached)
    while (scanf("%d", &value) != EOF) { // store each input into the variable 'value'
    fprintf(stderr, "READING INPUT: %d\n", value); // print the value to stderr
        addHeap(value); // add the value into the heap
    }

    /* print heap as XML */
    printXML(0); // start printing the heap from index 0
    printf("\n"); // move to the next line after printing XML

    /* delete max and print descending */
    // keep printing elements until heap is empty
    while (heapSize() > 0) {
        int x = heapDelete(); // removes the biggest integer in the heap and stores it into x.
        printf("%d\n", x); // print it (gives decending order)
        push(x); // push the value onto the stacl
    }

    /* pop stack and print ascending */
    // keep popping until stack is empty
    while (!isEmpty()) { // while stack isn't empty:
        printf("%d\n", pop()); // pop value from stack and print it this gives ascending order, since stacks follows LIFO
    }

    return 0; // end program
}

// function to print heap as XML format:
void printXML(int index){
    extern int heap[]; // tells compiler that heap array is defined in another file
    if (index >= heapSize()) return; // if index is outside heap size, stop

	// otherwise: print the first XML tag with the index value passed in the printXML() parameter
    printf("<node id=\"%d\">", heap[index]);
	
	// calculate left and right child indices
    int left = 2 * index + 1; // left child index
    int right = 2 * index + 2; // right child index

    if (left < heapSize()) printXML(left); // recursivley print left subtree if it exists
    if (right < heapSize()) printXML(right); // recursivley print right subtree if it exists

    printf("</node>"); // print the closing XML tag for the first ever index value passed in the printXML() method
}
