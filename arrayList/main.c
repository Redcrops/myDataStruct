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

    int num1 = 10;
    arrayListHeadInsert(aList, &num1);
    arrayListPrint(aList, printBasicDataType);

    int num2 = 8;
    arrayListHeadInsert(aList, &num2);
    arrayListPrint(aList, printBasicDataType);

    int num3 = 6;
    arrayListTailInsert(aList, &num3);
    arrayListPrint(aList, printBasicDataType);

    int num4 = 5;
    arrayListPosInsert(aList, 2, &num4);
    arrayListPrint(aList, printBasicDataType);

    printf("aList->capacity=%d\n", aList->capacity);
    printf("aList->len=%d\n", aList->len);
    return 0;
}