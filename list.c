#include <stdio.h>
#include <malloc/_malloc.h>

typedef struct tagNode {
    int Data;
    struct tagNode *NextNode;
} Node;

// 함수 선언
Node *SLL_CreateNode(int newData);

void SLL_DestroyNode(Node *node);

int main() {
    Node *Node1 = SLL_CreateNode(10);
    return 0;
}

Node *SLL_CreateNode(int newData) {
    Node *NewNode = (Node *) malloc(sizeof(Node));
    NewNode->Data = newData;
    NewNode->NextNode = NULL;
    return NewNode;
}

void SLL_DestroyNode(Node *node) {
    free(node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
    //  헤드 노드가 NULL이라면 새로운 노드가 Head
    if ( *Head == NULL )
    {
        *Head = NewNode;
    }
    else
    {
        //  테일을 찾아 NewNode를 연결한다.
        Node* Tail = (*Head);
        while ( Tail->NextNode != NULL )
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

//  노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while ( Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}