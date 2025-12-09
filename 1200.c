#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char conteudo;
    struct Node *esq;
    struct Node *dir;
} Node;

Node* CriaNode(char conteudo) {
    Node* nova = (Node*)malloc(sizeof(Node));
    nova->conteudo = conteudo;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

Node* Insere(Node* root, char conteudo) {
    if (root == NULL) {
        return CriaNode(conteudo);
    }
    
    if (conteudo < root->conteudo) {
        root->esq = Insere(root->esq, conteudo);
    } else if (conteudo > root->conteudo) {
        root->dir = Insere(root->dir, conteudo);
    }
    
    return root;
}


int search(Node* root, char conteudo) {
    if (root == NULL) return 0;
    if (root->conteudo == conteudo) return 1;
    
    if (conteudo < root->conteudo) {
        return search(root->esq, conteudo);
    } else {
        return search(root->dir, conteudo);
    }
}


void InFixa(Node* root, int *first) {
    if (root == NULL) return;
    
    InFixa(root->esq, first);
    
    if (!(*first)) printf(" ");
    printf("%c", root->conteudo);
    *first = 0; 
    
    InFixa(root->dir, first);
}

void PreFixa(Node* root, int *first) {
    if (root == NULL) return;
    
    if (!(*first)) printf(" ");
    printf("%c", root->conteudo);
    *first = 0;
    
    PreFixa(root->esq, first);
    PreFixa(root->dir, first);
}

void postOrder(Node* root, int *first) {
    if (root == NULL) return;
    
    postOrder(root->esq, first);
    postOrder(root->dir, first);
    
    if (!(*first)) printf(" ");
    printf("%c", root->conteudo);
    *first = 0;
}

int main() {
    Node* root = NULL;
    char command[20];
    char letter;
    
    while (scanf("%s", command) != EOF) {
        
        if (strcmp(command, "I") == 0) {
            scanf(" %c", &letter); 
            root = Insere(root, letter);
            
        } else if (strcmp(command, "INFIXA") == 0) {
            int first = 1; 
            InFixa(root, &first);
            printf("\n");
            
        } else if (strcmp(command, "PREFIXA") == 0) {
            int first = 1;
            PreFixa(root, &first);
            printf("\n");
            
        } else if (strcmp(command, "POSFIXA") == 0) {
            int first = 1;
            postOrder(root, &first);
            printf("\n");
            
        } else if (strcmp(command, "P") == 0) {
            scanf(" %c", &letter);
            if (search(root, letter)) {
                printf("%c existe\n", letter);
            } else {
                printf("%c nao existe\n", letter);
            }
        }
    }
    
    return 0;
}