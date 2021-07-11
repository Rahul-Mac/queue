#include "Queue.h"

int main()
{
	Queue *q = create_queue(5);
	enqueue(1, q);
	enqueue(2, q);
	enqueue(3, q);
	enqueue(4, q);
	enqueue(5, q);
	enqueue(6, q);
	print(q);
	printf("\nLength = %d", queue_length(q));
	dequeue(q);	
	dequeue(q);	
	print(q);	
	enqueue(99, q);
	enqueue(100, q);
	print(q);	
	dequeue(q);	
	dequeue(q);	
	dequeue(q);	
	print(q);	
	dequeue(q);
	dequeue(q);
	print(q);	
	dequeue(q);
}
