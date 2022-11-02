typedef int Node;
#define NULLpt -999

typedef struct QueNode
{
    int data;
    struct QueNode *link;
} QueNode;

typedef struct Queue
{
    QueNode *front;
    QueNode *rear;
} Queue;

int isEmpty(Queue *que)
{
    if (que->front == NULL)
        return 1;
    return 0;
}

void enqueue(Queue *que, int data)
{
    QueNode *temp = (QueNode *)malloc(sizeof(QueNode));
    temp->data = data;
    temp->link = NULL;

    if (isEmpty(que))
    {
        que->front = que->rear = temp;
        return;
    }

    que->rear->link = temp;
    que->rear = que->rear->link;
}

int dequeue(Queue *que)
{
    if (isEmpty(que))
        return NULLpt;

    QueNode *temp = que->front;
    que->front = que->front->link;

    if (que->front == NULL)
        que->rear = NULL;

    int n = temp->data;
    free(temp);
    return n;
}

int peek(Queue *que)
{
    if (isEmpty(que))
        return NULLpt;
    return que->front->data;
}