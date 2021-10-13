#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct N {
    int data;
    struct Node *next;
} Node;

typedef struct Q {
    int count;
    Node *front;
    Node *rear;
} Queue;

void initialize(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int x);
void dequeue(Queue *q);

int main() {
    Queue *q;
    q = malloc( sizeof (Queue) );
    initialize(q);

    enqueue(q, 200);
    enqueue(q, 250);
    enqueue(q, 300);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    return 0;
}

void initialize(Queue *q) {
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
//    if (size > INT_MAX) return;
//
//    struct Queue* q = (struct Queue*) malloc( sizeof (struct Queue));
//    q->front = -1;
//    q->rear = -1;
//    q->data = (int *) malloc( size * sizeof ( int ));
}

int isEmpty(Queue *q) {
    return (q->rear == NULL);
}

void enqueue(Queue *q, int x) {
    // Define temporary Node.
    Node *temp;

    // Allocate size of temporary Node.
    temp = malloc( sizeof (Node) );
    temp->data = x;
    temp->next = NULL;

    // Check if the Queue is empty.
    if (isEmpty(q)) {
        q->front = q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }

    q->count++;
    printf("Enqueued <%d> in node <%d>.\n", x, q->count);
}

void dequeue(Queue *q) {
    // Set temporary Node.
    Node *temp;

    // Get Node data.
    int nodeData = q->front->data;
    temp = q->front;
    q->front = q->front->next;
    q->count--;

    // Release the temporary from memory.
    free(temp);

    printf("Dequeued <%d> from node.\n", nodeData);
}
