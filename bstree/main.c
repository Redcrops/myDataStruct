#include "bstree.h"
#include <stdio.h>
int pCompare(ELEMENTTYPE num1, ELEMENTTYPE num2)
{
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
int main()
{
    Bstree *tree = NULL;
    bstreeInit(&tree, pCompare);
    int num = 10;
    bstreeInsert(tree, (void *)&num);
    return 0;
}