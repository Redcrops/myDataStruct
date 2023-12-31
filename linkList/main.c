#include "linkList.h"
#include <stdio.h>
/*需要输出什么类型数据可自行修改*/
void printBasicDataType(void *val)
{
    int num = *(int *)val;
    printf("%d\t", num);
}
int main()
{
    LinkList *singleList = NULL;
    linkListInit(&singleList);

    printf("head insert 10\n");
    int num1 = 10;
    linkListHeadInsert(singleList, &num1);
    linkListPrint(singleList, printBasicDataType);

    printf("head insert 8\n");
    int num2 = 8;
    linkListHeadInsert(singleList, &num2);
    linkListPrint(singleList, printBasicDataType);

    printf("tail insert 6\n");
    int num3 = 6;
    linkListTailInsert(singleList, &num3);
    linkListPrint(singleList, printBasicDataType);

    printf("pos2 insert 2\n");
    int num4 = 2;
    linkListPosInsert(singleList, 2, &num4);
    linkListPrint(singleList, printBasicDataType);

    return 0;
}