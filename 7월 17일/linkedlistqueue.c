#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
 
typedef struct Node {
    int data;
    Node *next;
} Node;
 
typedef struct Queue {
    Node *rear;
    Node *front;
    int count;
} Queue;
 
void InitQueue(Queue *qu){
    qu->rear = NULL;
    qu->front = NULL;
    qu->count = 0;
}
bool IsEmpty(Queue *qu) {
    if (qu->front == NULL) return true;
    return false;
}
void Enqueue(Queue *qu, int a) {
    Node *now = (Node *)malloc(sizeof(Node));
    now->data = a;
    now->next = NULL;
 
    if (IsEmpty(qu)) {
        qu->front = now;
    }
    else {
        qu->rear->next = now;
    }
    qu->rear = now;
    qu->count++;
}
 
int Dequeue(Queue *qu) {
    if (IsEmpty(qu)) return -999;
    Node *now;
    int re = 0;
    
    now = qu->front;
    re = now->data;
    qu->front = now->next;
    
    free(now);
    qu->count--;
 
    return re;
}
 
int main() {
    Queue queue;
 
    InitQueue(&queue);
    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    printf("%d ", Dequeue(&queue));
    printf("%d ", Dequeue(&queue));
 
    return 0;
}
