#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
}Node;

typedef struct Queue
{
	Node *front, *rear;
	int size;
}Queue;

Node* create_node(int d)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = d;
	n->link = NULL;
	return n;
}

Queue* create_queue(int s)
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	q->size = s;
	return q;
}

void print(Queue *q)
{
	Node *temp = q->front;
	printf("\n");
	if(temp == NULL)
		printf("NULL");
	else
	{
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
	}
}

int queue_length(Queue *q)
{
	Node *temp = q->front;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}

void enqueue(int d, Queue *q)
{
	if(q->size == queue_length(q))
	{
		printf("\nOverflow");
		return;
	}
	Node *n = create_node(d);
	if(q->rear == NULL)
		q->front = q->rear = n;
	else
	{
		q->rear->link = n;
		q->rear = n;
	}
}

void dequeue(Queue *q)
{
	Node *n = q->front;
	if(q->front == NULL)
		printf("\nUnderflow");
	else if(q->front == q->rear)
	{
		q->front = q->rear = NULL;
		free(n);
	}
	else
	{
		q->front = n->link;
		free(n);
	}
}