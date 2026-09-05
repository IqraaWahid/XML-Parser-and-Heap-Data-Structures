int heap[100]; // array to store heal elements (max heap)
static int size=0; // the current size of the heap array

//swap two integers, a and b, using pointers
void swap(int *a, int *b){
	int temp = *a; // temp temporarily stores pointer a
	*a = *b; // pointer a now equals pointer b
	*b = temp; // pointer b noq equals the temp variable which stored pointer a
}

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete(){
	if (size == 0) return -1; // if heap is empty, exit function

    int max = heap[0]; // root of the tree is maximum
    heap[0] = heap[size - 1]; // make the last element the root
    size--; //reduce the size of the heap by one

    int i = 0;// start heapify down from root

	// heapify down
	// While loop stops when:
		// The node has no children (left >= size and right >= size)
		// or the node is larger than both its left and right children (proper max heap structure followed)
    while (1) {
        int left = 2 * i + 1; // left child index
        int right = 2 * i + 2; // right child index
        int largest = i; // let the current largest be the current node
		
		// check if left child exists and if left element is greater than the current node element
        if (left < size && heap[left] > heap[largest])
            largest = left; // if true, let largest be the left element
		
		//check if the right child exists and if the right element is greater than the current node element
        if (right < size && heap[right] > heap[largest])
            largest = right; // if yes, let the largest be the right element
		
		//if the current node is the largest, stop
        if (largest == i) break;

		// otherwise, swap current node with the larger child
        swap(&heap[i], &heap[largest]);
        i = largest; // update the current node to the largest
    }

    return max; //return the maximum element, which will be heap[0] 

}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add){
	heap[size] = thing2add; // insert value to the end of the heap
    int i = size; // let i store the size of the heap initially
    size++; // increase heap size by 1

	//heapify up since new value added at the bottom of the heap
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]); //swap with parents
        i = (i - 1) / 2; // move up to parent index
    }
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize(){
  return size;
}
