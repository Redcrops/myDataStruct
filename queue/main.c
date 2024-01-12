#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define PUSH_SIZE 5
#define POP_SIZE 3
void printBasicDataType(void *data)
{
    int num = *(int *)data;
    printf("%d\t", num);
}
int main()
{
    Queue *que = NULL;
    queueInit(&que);
    int arr[PUSH_SIZE] = {1, 2, 56, 7, 457};
    for (int idx = 0; idx < PUSH_SIZE; idx++)
    {
        queuePush(que, (void *)&arr[idx]);
    }
    queuePrint(que, printBasicDataType);
    for (int idx = 0; idx < POP_SIZE; idx++)
    {
        queuePop(que);
    }
    queuePrint(que, printBasicDataType);

    int *topNum = 0;
    quequeTop(que, (void **)&topNum);
    printf("quequeTop=%d\n", *topNum);

    queueDestroy(que);
    return 0;
}