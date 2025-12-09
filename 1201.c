#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int conteudo;
    struct node *esq, *dir;
} Node;

// Protótipos das funções
Node* Insere(Node* root, int x);
Node* removeNode(Node* root);
Node* Remove(Node* root, int x);
int Existe(Node* root, int x);
void InFixo(Node* root, int *first);
void PreFixo(Node* root, int *first);
void PosFixo(Node* root, int *first);

int main() {
    Node* root = NULL;
    char op[15];
    int x;

    while (scanf("%s", op) != EOF) {
        if (strcmp(op, "I") == 0) {
            scanf("%d", &x);
            root = Insere(root, x);
        } else if (strcmp(op, "R") == 0) {
            scanf("%d", &x);
            root = Remove(root, x);
        } else if (strcmp(op, "P") == 0) {
            scanf("%d", &x);
            if (Existe(root, x))
                printf("%d existe\n", x);
            else
                printf("%d nao existe\n", x);
        } else if (strcmp(op, "INFIXA") == 0) {
            int first = 1;
            InFixo(root, &first);
            printf("\n");
        } else if (strcmp(op, "PREFIXA") == 0) {
            int first = 1;
            PreFixo(root, &first);
            printf("\n");
        } else if (strcmp(op, "POSFIXA") == 0) {
            int first = 1;
            PosFixo(root, &first);
            printf("\n");
        }
    }
    return 0;
}

// ================= Funções da árvore =================

Node* Insere(Node* root, int x) {
    if (root == NULL) {
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->conteudo = x;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (x < root->conteudo)
        root->esq = Insere(root->esq, x);
    else if (x > root->conteudo)
        root->dir = Insere(root->dir, x);
    return root;
}

Node* removeNode(Node* root) {
    if (root->esq == NULL) {
        Node* r = root->dir;
        free(root);
        return r;
    } else if (root->dir == NULL) {
        Node* l = root->esq;
        free(root);
        return l;
    } else {
        Node* p = root->esq;
        Node* pai = root;
        while (p->dir != NULL) {
            pai = p;
            p = p->dir;
        }
        root->conteudo = p->conteudo;
        if (pai == root)
            pai->esq = p->esq;
        else
            pai->dir = p->esq;
        free(p);
        return root;
    }
}

Node* Remove(Node* root, int x) {
    if (root == NULL) return NULL;
    if (x < root->conteudo)
        root->esq = Remove(root->esq, x);
    else if (x > root->conteudo)
        root->dir = Remove(root->dir, x);
    else
        root = removeNode(root);
    return root;
}

int Existe(Node* root, int x) {
    while (root != NULL) {
        if (x == root->conteudo) return 1;
        else if (x < root->conteudo) root = root->esq;
        else root = root->dir;
    }
    return 0;
}

void InFixo(Node* root, int *first) {
    if (!root) return;
    InFixo(root->esq, first);
    if (*first) { printf("%d", root->conteudo); *first = 0; }
    else printf(" %d", root->conteudo);
    InFixo(root->dir, first);
}

void PreFixo(Node* root, int *first) {
    if (!root) return;
    if (*first) { printf("%d", root->conteudo); *first = 0; }
    else printf(" %d", root->conteudo);
    PreFixo(root->esq, first);
    PreFixo(root->dir, first);
}

void PosFixo(Node* root, int *first) {
    if (!root) return;
    PosFixo(root->esq, first);
    PosFixo(root->dir, first);
    if (*first) { printf("%d", root->conteudo); *first = 0; }
    else printf(" %d", root->conteudo);
}
