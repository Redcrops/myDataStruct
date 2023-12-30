#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

#define INITIAL_SIZE 10
enum STATUS_CODE
{
    MALLLOC_ERROR = -2,
    NULL_PTR,
    ON_SUCCESS,
};
static int checkMalloc(arrayList *aList)
{
    if (aList == NULL)
    {
        return MALLLOC_ERROR;
    }
    memset(aList, 0, sizeof(aList));
}
// 动态数组初始化
int arrayListInit(arrayList **aList)
{
    /*为动态数组分配空间*/
    arrayList *alist = (arrayList *)malloc(sizeof(arrayList) * 1);
    /*判空以及清除脏数据*/
    checkMalloc(alist);

    /*为data分配空间*/
    alist->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * INITIAL_SIZE);
    /*判空*/
    if (alist->data == NULL)
    {
        return MALLLOC_ERROR;
    }
    /*清除脏数据*/
    memset(alist->data, 0, sizeof(ELEMENTTYPE) * INITIAL_SIZE);

    /*初始化动态数组的容量和长度*/
    alist->capacity = INITIAL_SIZE;
    alist->len = 0;

    /*解引用*/
    *aList = alist;
}
/*插入*/
/*头插*/
int arrayListHeadInsert(arrayList *aList)
{
}
/*尾插*/
int arrayListTailInsert(arrayList *aList)
{
}
/*指定位置插入*/
int arrayListPosInsert(arrayList *aList, int pos)
{
}

/*************************************************************************/

/*删除*/
/*头删*/
int arrayListHeadRemove(arrayList *aList)
{
}
/*尾删*/
int arrayListTailRemove(arrayList *aList)
{
}
/*指定位置删除*/
int arrayListPosRemove(arrayList *aList, int pos)
{
}
/*动态数组销毁*/
int arrayListRuin(arrayList *aList)
{
}