#include <stdio.h>
#include <malloc/_malloc.h>

typedef struct tagNode {
    int Data;
    struct tagNode *NextNode;
} Node;

int main() {

    return 0;
}

Node *SLL_CreateNode(int newData) {
    Node *NewNode = (Node *) malloc(sizeof(Node));
    NewNode->Data = newData;
    NewNode->NextNode = NULL;
    return NewNode;
}

void SLL_DestroyNode (Node* node) {
    free(node);
}
