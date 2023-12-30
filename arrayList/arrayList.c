#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

#define INITIAL_SIZE 10
enum STATUS_CODE
{
    MALLLOC_ERROR = -3,
    NULL_PTR,
    INVALID_POS,
    ON_SUCCESS,
};
/*********************静态函数前置声明*******************************/
/*判断传入动态数组是否为空*/
static int checkAlist(arrayList *aList);
/*动态数组分配判空和清除脏数据*/
static int checkMalloc(arrayList *aList);
/*判断插入或者删除位置是否合法*/
static int checkPos(arrayList *aList, int pos);
/*********************静态函数实现**********************************/
static int checkMalloc(arrayList *aList)
{
    if (aList == NULL)
    {
        return MALLLOC_ERROR;
    }
    memset(aList, 0, sizeof(aList));
}
static int checkAlist(arrayList *aList)
{
    if (aList == NULL)
    {
        return NULL_PTR;
    }
}
static int checkPos(arrayList *aList, int pos)
{
    if (pos < 0 || pos > aList->len)
    {
        return INVALID_POS;
    }
}
/*********************以上为静态函数*******************************/
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
    return ON_SUCCESS;
}
/*插入*/
/*头插*/
int arrayListHeadInsert(arrayList *aList, ELEMENTTYPE val)
{
    return arrayListPosInsert(aList, 0, val);
}
/*尾插*/
int arrayListTailInsert(arrayList *aList, ELEMENTTYPE val)
{
    return arrayListPosInsert(aList, aList->len, val);
}

/*指定位置插入*/
int arrayListPosInsert(arrayList *aList, int pos, ELEMENTTYPE val)
{
    /*动态数组判空*/
    checkAlist(aList);
    /*检查插入位置*/
    checkPos(aList, pos);
    /*从数组尾部开始后移，如果从中间位置开始后移会覆盖*/
    for (int idx = aList->len - 1; idx >= pos; idx--)
    {
        aList->data[idx + 1] = aList->data[idx];
    }
    /*插入值*/
    aList->data[pos] = val;
    /*更新动态数组长度*/
    aList->len++;
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
/*输出动态数组*/
int arrayListPrint(arrayList *aList, void (*printFunc)(ELEMENTTYPE))
{
    for (int idx = 0; idx < aList->len; idx++)
    {
        printFunc(aList->data[idx]);
    }
    printf("\n");
}
/*动态数组销毁*/
int arrayListRuin(arrayList *aList)
{
}