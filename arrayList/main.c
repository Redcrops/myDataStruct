#include <stdio.h>
#include "arrayList.h"
#define BUFFER_SIZE 5
void printBasicDataType(void *data)
{
    int num = *(int *)data;
    printf("%d\t", num);
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

    printf("tail remove\n");
    arrayListTailRemove(aList);
    arrayListPrint(aList, printBasicDataType);

    printf("head remove\n");
    arrayListHeadRemove(aList);
    arrayListPrint(aList, printBasicDataType);

    printf("aList->capacity=%d\n", aList->capacity);
    printf("aList->len=%d\n", aList->len);
    return 0;
}