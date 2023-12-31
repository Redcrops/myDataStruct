#include <stdio.h>
#include "arrayList.h"
#define BUFFER_SIZE 3
void printBasicDataType(void *data)
{
    int num = *(int *)data;
    printf("%d\t", num);
}
int compareFunc(void *num1, void *num2)
{
    return *(int *)num1 == *(int *)num2 ? 1 : 0;
}
int main()
{
    arrayList *aList = NULL;
    arrayListInit(&aList);

    printf("head insert 10\n");
    int num1 = 10;
    arrayListHeadInsert(aList, &num1);
    arrayListPrint(aList, printBasicDataType);

    printf("head insert 8\n");
    int num2 = 8;
    arrayListHeadInsert(aList, &num2);
    arrayListPrint(aList, printBasicDataType);

    printf("tail insert 6\n");
    int num3 = 6;
    arrayListTailInsert(aList, &num3);
    arrayListPrint(aList, printBasicDataType);

    printf("pos2 insert 5\n");
    int num4 = 5;
    arrayListPosInsert(aList, 2, &num4);
    arrayListPrint(aList, printBasicDataType);

    printf("insert 1,5,5\n");
    int array[BUFFER_SIZE] = {1, 2, 3};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        arrayListTailInsert(aList, &array[idx]);
    }
    arrayListPrint(aList, printBasicDataType);
    printf("aList->capacity=%d\n", aList->capacity);
    for (int idx = 0; idx < 4; idx++)
    {
        arrayListHeadRemove(aList);
        arrayListPrint(aList, printBasicDataType);
        printf("aList->len=%d\n", aList->len);
        printf("aList->capacity=%d\n", aList->capacity);
    }
    // printf("val remove 5\n");
    // int status = arrayListValRemove(aList, &num4, compareFunc);
    // arrayListPrint(aList, printBasicDataType);
    // printf("status=%d\n", status);

    // printf("pos4 insert 5\n");
    // arrayListPosInsert(aList, 4, &array[1]);
    // arrayListPrint(aList, printBasicDataType);

    // printf("pos0 delete\n");
    // arrayListPosRemove(aList, 0);
    // arrayListPrint(aList, printBasicDataType);

    // printf("tail remove\n");
    // arrayListTailRemove(aList);
    // arrayListPrint(aList, printBasicDataType);

    // printf("head remove\n");
    // arrayListHeadRemove(aList);
    // arrayListPrint(aList, printBasicDataType);
    // arrayListRuin(aList);
    return 0;
}