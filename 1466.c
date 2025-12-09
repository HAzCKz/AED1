#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue {
    Node **data;
    int front;
    int rear;
    int size;
} Queue;

// Funções da fila
Queue* createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (Node**)malloc(size * sizeof(Node*));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(Queue *q, Node *node) {
    q->data[q->rear++] = node;
}

Node* dequeue(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void freeQueue(Queue *q) {
    free(q->data);
    free(q);
}

// Funções da árvore
Node* insert(Node *root, int value) {
    if (!root) {
        Node *node = (Node*)malloc(sizeof(Node));
        node->value = value;
        node->left = node->right = NULL;
        return node;
    }
    if (value < root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// BFS e impressão
void bfsPrint(Node *root) {
    Queue *q = createQueue(500); // máximo 500 níveis
    enqueue(q, root);
    int first = 1;

    while (!isEmpty(q)) {
        Node *current = dequeue(q);
        if (first) { 
            printf("%d", current->value); 
            first = 0;
        } else {
            printf(" %d", current->value);
        }
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    freeQueue(q);
    printf("\n");
}

int main() {
    int C;
    scanf("%d", &C);
    for (int t = 1; t <= C; t++) {
        int N;
        scanf("%d", &N);
        Node *root = NULL;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            root = insert(root, x);
        }

        printf("Case %d:\n", t);
        bfsPrint(root);
        printf("\n"); // linha em branco após cada caso
        freeTree(root);
    }
    return 0;
}
