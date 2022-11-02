#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

typedef struct Graph
{
    int **adjMatrix;
    int len;
} Graph;

void initialise(Graph *, int);
void create_graph(Graph *);
void DFS(Graph *, int);
void BFS(Graph *, int);
void display(Graph *);

int main()
{
    int len;
    printf("Enter the number of nodes:\n");
    scanf("%d", &len);
    Graph graph;
    initialise(&graph, len);
    int choice, start;
    do
    {
        printf("\nMain Menu\n\n");
        printf("1) Create Graph\n2) Depth First Traversal\n");
        printf("3) Breadth First Traversal\n4) Display\n5) Exit\n->: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            create_graph(&graph);
            break;
        case 2:
            printf("Enter starting node: ");
            scanf("%d", &start);
            DFS(&graph, start);
            break;
        case 3:
            printf("Enter starting node: ");
            scanf("%d", &start);
            BFS(&graph, start);
            break;
        case 4:
            display(&graph);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice >= 1 && choice <= 4);
    return 0;
}

void initialise(Graph *graph, int len)
{
    graph->len = len;
    graph->adjMatrix = (int **)calloc(len, sizeof(int *));
    for (int i = 0; i < len; i++)
        graph->adjMatrix[i] = (int *)calloc(len,sizeof(int));
}

void create_graph(Graph *graph)
{
    printf("--:Enter the nodes connected by adjMatrix edge:-- \n\n");
    char ch;
    int i, j;
    do
    {
        do
        {
            printf("Node from which the edge originates: ");
            scanf("%d", &i);
            if (i >= graph->len)
                printf("Invalid index entered!\n\n");
        } while (i >= graph->len);
        do
        {
            printf("Node at which the edge terminates: ");
            scanf("%d", &j);
            if (j >= graph->len)
                printf("Invalid index entered!\n\n");
        } while (j >= graph->len);
        graph->adjMatrix[i][j] = 1;
        printf("\nEnter \'Y\' to further create graph: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void DFS(Graph *graph, int start)
{
    if (start >= graph->len)
    {
        printf("Invalid Location!\n");
        return;
    }
    int *visited = (int *)calloc(graph->len, sizeof(int));
    int i;
    printf("%d->", start);
    visited[start] = 1;
    Stack *stack = NULL;
    push(&stack, start);
    while (!isEmpty_stack(stack))
    {
        start = top(stack);
        for (i = 0; i < graph->len; i++)
        {
            if (graph->adjMatrix[start][i] == 1 && visited[i] == 0)
            {
                push(&stack, i);
                printf("%d->", i);
                visited[i] = 1;
                break;
            }
        }
        if (i == graph->len)
            pop(&stack);
    }
    free(visited);
    printf("\b\b \n");
}

void BFS(Graph *graph, int start)
{
    if (start >= graph->len)
    {
        printf("Invalid Location!\n");
        return;
    }
    int *visited = (int *)calloc(graph->len, sizeof(int));
    Queue queue = {NULL, NULL};
    enqueue(&queue, start);
    visited[start] = 1;
    while (!isEmpty(&queue))
    {
        start = dequeue(&queue);
        printf("%d->", start);
        for (int i = 0; i < graph->len; i++)
        {
            if (graph->adjMatrix[start][i] == 1 && visited[i] == 0)
            {
                enqueue(&queue, i);
                visited[i] = 1;
            }
        }
    }
    free(visited);
    printf("\b\b \n");
}

void display(Graph *graph)
{
    printf(" ");
    for (int i = 0; i < graph->len; i++)
        printf("%d ", i);
    printf("\n ");
    for (int i = 0; i < graph->len; i++)
        printf("- ");
    printf("\n");
    for (int i = 0; i < graph->len; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < graph->len; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
