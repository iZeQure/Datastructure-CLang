#include <stdio.h>
#include <limits.h>

#define MAX_SIZE INT_MAX

int capacity = 5;
int stack[5];
int top = -1;

int isEmpty();
int atCapacity();
void push(int x);
void peek();
void pop();

void printTop();

int main() {
    peek();
    push(5);
    peek();
    push(6);
    peek();
    pop();
    peek();
    push(10);
    push(56);
    push(23);
    push(3);
    push(120);
    pop();
    pop();
    peek();
    pop();
    pop();
    peek();
    pop();
    pop();

    return 0;
}

int isEmpty() {
    return top == -1;
}

int atCapacity() {
    return top == capacity - 1;
}

void push(int x) {
    if (atCapacity()) {
        printf("Data was not pushed. Stack is at capacity <%d>\n", capacity);
        return;
    }

    stack[top++ + 1] = x;
    printf("Pushed %d to stack.\n", x);
    printTop();
}

void peek() {
    if (isEmpty()) {
        printf("Can't peek an empty stack. <%d>\n", top);
        return;
    }

    printf("Peeking at stack, watching the glorious <%d> value.\n", stack[top]);
}

void pop() {
    if (isEmpty()) {
        printf("Cannot pop from an empty stack.\n");
        return;
    }

    int topData = stack[top];
    top = top -1;
    printf("Popped <%d> from stack.\n", topData);
    printTop();
}

void printTop() {
    printf("Switching pointer to <%d>.\n", top);
}