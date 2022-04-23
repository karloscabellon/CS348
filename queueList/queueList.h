typedef struct node* nodeptr;

typedef struct node{
	int element;
	nodeptr next;
}NODE;

typedef struct{
	nodeptr front;
	int count;
	int MAX;
	nodeptr rear;
}HEAD;

typedef HEAD* Queue;

Queue createQueue();
void display(Queue q);
void enqueue(Queue q, int num);
void dequeue(Queue q);
int isEmpty(Queue q);
int isFull(Queue q);
void clear(Queue q);
int front(Queue q);
int rear(Queue q);
