#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *esq, *dir;
} Node;

Node* Insere(Node* root, int value);
void PreFixo(Node* root);
void InFixo(Node* root);
void PosFixo(Node* root);

int main() {
    int C, N, x, i, j;
    scanf("%d", &C);

    for (i = 1; i <= C; i++) {
        Node* root = NULL;
        scanf("%d", &N);

        for (j = 0; j < N; j++) {
            scanf("%d", &x);
            root = Insere(root, x);
        }

        printf("Case %d:\n", i);
        printf("Pre.:");
        PreFixo(root);
        printf("\nIn..:");
        InFixo(root);
        printf("\nPost:");
        PosFixo(root);
        printf("\n\n");
    }

    return 0;
}

Node* Insere(Node* root, int value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->value = value;
        root->esq = root->dir = NULL;
    } else if (value < root->value) {
        root->esq = Insere(root->esq, value);
    } else {
        root->dir = Insere(root->dir, value);
    }
    return root;
}

void PreFixo(Node* root) {
    if (root) {
        printf(" %d", root->value);
        PreFixo(root->esq);
        PreFixo(root->dir);
    }
}

void InFixo(Node* root) {
    if (root) {
        InFixo(root->esq);
        printf(" %d", root->value);
        InFixo(root->dir);
    }
}

void PosFixo(Node* root) {
    if (root) {
        PosFixo(root->esq);
        PosFixo(root->dir);
        printf(" %d", root->value);
    }
}