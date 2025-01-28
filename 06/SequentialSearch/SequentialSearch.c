#include <string.h>
#include "LinkedList.h"

Node *SLL_SequentialSearch(Node *Head, int Target) {
    Node *Current = Head;
    Node *Match = NULL;

    while (Current != NULL) {
        if (Current->Data == Target) {
            Match = Current;
            break;
        } else
            Current = Current->NextNode;
    }

    return Match;
}

int SSL_ArraySequentialSearch(int DataSet[], int Length, int Target) {
    int i = 0;
    int Sequence = -1;
    for (i = 0; i < Length; i++) {
        if (DataSet[i] == Target) {
            Sequence = i;
            break;
        }
    }
    return Sequence;
}

Node *SLL_MoveToFront(Node **Head, int Target) {
    Node *Current = (*Head);
    Node *Previous = NULL;
    Node *Match = NULL;

    while (Current != NULL) {
        if (Current->Data == Target) {
            Match = Current;
            if (Previous != NULL) {
                //	자신의 앞 노드와 다음 노드를 연결
                Previous->NextNode = Current->NextNode;

                //	자신을 리스트의 가장 앞으로 옮기기
                Current->NextNode = (*Head);
                (*Head) = Current;
            }
            break;
        } else {
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}

int SLL_ArrayMoveToFront(int DataSet[], int Length, int Target) {
    int i = 0;
    int Sequence = -1;
    for (i = 0; i < Length; ++i) {
        if (DataSet[i] == Target) {
            Sequence = i;
            memmove(&DataSet[1], &DataSet[0], sizeof(DataSet[0]) * i);
            DataSet[0] = Target;
            break;
        }
    }
    return Sequence;
}

Node *SLL_Transpose(Node **Head, int Target) {
    Node *Current = (*Head);
    Node *PPrevious = NULL; //	이전 노드의 이전 노드
    Node *Previous = NULL; //	이전 노드
    Node *Match = NULL;

    while (Current != NULL) {
        if (Current->Data == Target) {
            Match = Current;
            if (Previous != NULL) {
                if (PPrevious != NULL)
                    PPrevious->NextNode = Current;
                else
                    (*Head) = Current;

                Previous->NextNode = Current->NextNode;
                Current->NextNode = Previous;
            }
            break;
        } else {
            if (Previous != NULL)
                PPrevious = Previous;

            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}

int SLL_ArrayTranspose(int DataSet[], int Length, int Target) {
    int Sequence = -1;
    int i = 0;
    for (i = 0; i < Length; i++) {
        if (DataSet[i] == Target) {
            Sequence = i;
            if (i != 0) {
                int Temp = DataSet[i];
                DataSet[i] = DataSet[i - 1];
                DataSet[i - 1] = Temp;
            } else {
                break;
            }
        }
    }
    return Sequence;
}

void SSL_FrequencyCount() {

}

int main(void) {

    // 배열 찾기
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
//    int sequence = SSL_ArraySequentialSearch(DataSet, Length, 2);
//    printf("%d", sequence);

//    SLL_ArrayMoveToFront(DataSet, Length, 6);
    SLL_ArrayTranspose(DataSet, Length, 6);
    for (int i = 0; i < Length; i++) {
        printf("%d", DataSet[i]);
    }

//    int i = 0;
//    int Count = 10;
//    Node *List = NULL;
//    Node *Current = NULL;
//    Node *NewNode = NULL;
//    Node *Match = NULL;
//
//    int InitValue[10] = {1, 2, 6, 10, 4, 9, 5, 3, 8, 7};
//
//    //  리스트 초기화
//    for (i = 0; i < Count; i++) {
//        NewNode = SLL_CreateNode(InitValue[i]);
//        SLL_AppendNode(&List, NewNode);
//    }
//
//    // 순차 탐색
//    printf("Simple Sequential Search...\n");
//
//    Match = SLL_SequentialSearch(List, 9);
//    if (Match != NULL)
//        printf("Found : %d\n", Match->Data);
//    else
//        printf("Not Found : %d\n", Match->Data);
//
//    // 전진 이동법
//    printf("Move To Front...\n");
//
//    Match = SLL_MoveToFront(&List, 4);
//    if (Match != NULL)
//        printf("Found : %d\n", Match->Data);
//    else
//        printf("Not Found : %d\n", Match->Data);
//
//    // 전위법
//    printf("Transpose...\n");
//
//    Match = SLL_Transpose(&List, 7);
//    if (Match != NULL)
//        printf("Found : %d\n", Match->Data);
//    else
//        printf("Not Found : %d\n", Match->Data);
//
//
//    //  모든 노드를 메모리에서 제거
//    printf("Destroying List...\n");
//
//    for (i = 0; i < Count; i++) {
//        Current = SLL_GetNodeAt(List, 0);
//
//        if (Current != NULL) {
//            SLL_RemoveNode(&List, Current);
//            SLL_DestroyNode(Current);
//        }
//    }

    return 0;
}
