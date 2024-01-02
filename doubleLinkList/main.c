#include "doubleList.h"
#include <stdio.h>
#define BUFFER_SIZE 3

void printBasicDataType(void *val)
{
    int num = *(int *)val;
    printf("%d\t", num);
}

int main()
{
    DoubleList *doubleList = NULL;
    doubleListInit(&doubleList);

    printf("head insert 10\n");
    int num1 = 10;
    doubleListHeadInsert(doubleList, &num1);
    doubleListPrint(doubleList, printBasicDataType);

    printf("head insert 8\n");
    int num2 = 8;
    doubleListHeadInsert(doubleList, &num2);
    doubleListPrint(doubleList, printBasicDataType);

    printf("tail insert 6\n");
    int num3 = 6;
    doubleListTailInsert(doubleList, &num3);
    doubleListPrint(doubleList, printBasicDataType);

    printf("pos2 insert 2\n");
    int num4 = 2;
    doubleListPosInsert(doubleList, 2, &num4);
    doubleListPrint(doubleList, printBasicDataType);

    //  printf("pos2 remove \n");
    // doubleListPosRemove(doubleList, 2);
    // doubleListPrint(doubleList, printBasicDataType);

    // printf("head remove \n");
    // doubleListHeadRemove(doubleList);
    // doubleListPrint(doubleList, printBasicDataType);

    // printf("tail remove \n");
    // doubleListTailRemove(doubleList);
    // doubleListPrint(doubleList, printBasicDataType);

    printf("tail insert 2,1,2\n");
    int num[BUFFER_SIZE] = {2, 1, 2};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleListTailInsert(doubleList, (void *)&num[idx]);
    }
    doubleListPrint(doubleList, printBasicDataType);

    printf("val remove 2 \n");
    int num5 = 2;
    doubleListValRemove(doubleList, &num5);
    doubleListPrint(doubleList, printBasicDataType);

    doubleListRuin(doubleList);
}
