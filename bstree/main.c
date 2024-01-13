#include "bstree.h"
#include <stdio.h>
#define BUFFER_SIZE 3
int pCompare(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    int num1 = *(int *)val1;
    int num2 = *(int *)val2;
    if (num1 > num2)
    {
        return 1;
    }
    else if (num1 < num2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
void printBasicDataType(ELEMENTTYPE val)
{
    int num = *(int *)val;
    printf("%d\t", num);
}
int main()
{
    Bstree *tree = NULL;
    bstreeInit(&tree, pCompare, printBasicDataType);
    int num = 10;
    bstreeInsert(tree, (void *)&num);

    int arr[BUFFER_SIZE] = {6, 12, 8};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        bstreeInsert(tree, (void *)&arr[idx]);
    }

    int num1 = 7;
    bstreeInsert(tree, (void *)&num1);

    printf("size=%d\n", tree->size);
    bstreeLevelPrint(tree);
    return 0;
}