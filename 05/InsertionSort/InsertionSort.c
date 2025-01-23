#include <stdio.h>
#include <string.h>
#include "../../01/DoublyLinkedList/DoublyLInkedLIst.h"

void InsertionSortArray(int DataSet[], int Length) {
    int i = 0;
    int j = 0;
    int value = 0;

    for (i = 1; i < Length; i++) {
        if (DataSet[i - 1] <= DataSet[i])
            continue;

        value = DataSet[i];

        for (j = 0; j < i; j++) {
            if (DataSet[j] > value) {
                memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
                DataSet[j] = value;
                break;
            }
        }
    }
}

void InsertionSortList(Node **Head, int Length) {
    if (Head == NULL || *Head == NULL || Length < 2) {
        return; // 빈 리스트 또는 정렬할 필요가 없는 경우
    }

    Node *Current = (*Head)->NextNode; // 두 번째 노드부터 시작

    for (int i = 1; i < Length; i++) {
        if (Current == NULL) {
            break; // 리스트 끝에 도달한 경우
        }

        if (Current->Data >= Current->PrevNode->Data) {
            Current = Current->NextNode; // 정렬된 경우 다음 노드로 이동
            continue;
        }

        Node *value = Current; // 삽입 대상 노드
        Current = Current->NextNode; // 다음 노드로 미리 이동

        // `value`를 정렬된 부분으로 삽입
        Node *FlagNode = *Head;

        while (FlagNode != value) {
            if (FlagNode->Data > value->Data) {
                // 연결 끊기
                if (value->PrevNode != NULL) {
                    value->PrevNode->NextNode = value->NextNode;
                }
                if (value->NextNode != NULL) {
                    value->NextNode->PrevNode = value->PrevNode;
                }

                // 연결 삽입
                if (FlagNode->PrevNode != NULL) {
                    FlagNode->PrevNode->NextNode = value;
                } else {
                    *Head = value; // 새로운 Head로 갱신
                }
                value->PrevNode = FlagNode->PrevNode;
                value->NextNode = FlagNode;
                FlagNode->PrevNode = value;

                break;
            }
            FlagNode = FlagNode->NextNode;
        }
    }
}


int main(void) {
    int Count = 0;
    int i = 0;
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;

    //  노드 5개 추가
    NewNode = DLL_CreateNode(6);
    DLL_AppendNode(&List, NewNode);
    NewNode = DLL_CreateNode(2);
    DLL_AppendNode(&List, NewNode);
    NewNode = DLL_CreateNode(4);
    DLL_AppendNode(&List, NewNode);
    NewNode = DLL_CreateNode(1);
    DLL_AppendNode(&List, NewNode);
    NewNode = DLL_CreateNode(3);
    DLL_AppendNode(&List, NewNode);
    NewNode = DLL_CreateNode(5);
    DLL_AppendNode(&List, NewNode);

    Count = DLL_GetNodeCount(List);
    InsertionSortList(&List, Count);
    //  리스트 출력
    for (i = 0; i < Count; i++) {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
    printf("\n");

    return 0;
}
