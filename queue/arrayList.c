#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

#define INITIAL_SIZE 10

/*********************静态函数前置声明*******************************/
/*判断传入动态数组是否为空*/
static int checkAlist(arrayList *aList);
/*动态数组分配判空和清除脏数据*/
static int checkMalloc(arrayList *aList);
/*判断插入或者删除位置是否合法*/
static int checkPos(arrayList *aList, int pos);
/*扩容*/
static int expandCapacity(arrayList *aList);
/*缩容*/
static int reduceCapacity(arrayList *aList);
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
/*扩容*/
static int expandCapacity(arrayList *aList)
{
    /*容量为原来的1.5倍*/
    int biggerCapacity = aList->capacity + (aList->capacity >> 1);
    /*为新数组开辟空间*/
    ELEMENTTYPE *biggerArray = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * biggerCapacity);
    /*判空*/
    if (biggerArray == NULL)
    {
        return MALLLOC_ERROR;
    }
    /*清除脏数据*/
    memset(biggerArray, 0, sizeof(ELEMENTTYPE) * biggerCapacity);
    /*拷贝原数据*/
    memcpy(biggerArray, aList->data, sizeof(ELEMENTTYPE) * (aList->len));
    /*释放原来的数组*/
    if (aList->data != NULL)
    {
        free(aList->data);
        aList->data = NULL;
    }
    /*更新动态数组*/
    aList->data = biggerArray;
    /*更新容量*/
    aList->capacity = biggerCapacity;
    return ON_SUCCESS;
}
/*缩容*/
static int reduceCapacity(arrayList *aList)
{
    /*容量为原来的0.5倍*/
    int smallerCapacity = aList->capacity - (aList->capacity >> 1);
    /*为新数组开辟空间*/
    ELEMENTTYPE *smallerArray = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * smallerCapacity);
    /*判空*/
    if (smallerArray == NULL)
    {
        return MALLLOC_ERROR;
    }
    /*清除脏数据*/
    memset(smallerArray, 0, sizeof(ELEMENTTYPE) * smallerCapacity);
    /*拷贝原数据*/
    memcpy(smallerArray, aList->data, sizeof(ELEMENTTYPE) * (aList->len));

    /*释放原来的数组*/
    if (aList->data != NULL)
    {
        free(aList->data);
        aList->data = NULL;
    }
    /*更新动态数组*/
    aList->data = smallerArray;
    /*更新容量*/
    aList->capacity = smallerCapacity;
    return ON_SUCCESS;
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
    /*如果当前数组长度的1.5倍大于容量就扩容*/
    if ((aList->len + (aList->len >> 1)) > aList->capacity)
    {
        expandCapacity(aList);
    }
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
    return arrayListPosRemove(aList, 0);
}
/*尾删*/
int arrayListTailRemove(arrayList *aList)
{
    return arrayListPosRemove(aList, aList->len - 1);
}
/*指定位置删除*/
int arrayListPosRemove(arrayList *aList, int pos)
{
    checkAlist(aList);
    checkPos(aList, pos);
#if 0
    // if (pos < 0 || pos > aList->len)
    // {
    //     printf("非法位置删除!\n");
    //     return 0;
    // }
#endif
    /*如果容量的0.5倍还是大于长度就缩容*/
    if (aList->capacity - (aList->capacity >> 1) > aList->len)
    {
        reduceCapacity(aList);
    }
    for (int idx = pos; idx < aList->len - 1; idx++)
    {
        aList->data[idx] = aList->data[idx + 1];
    }

    /*更新长度*/
    aList->len--;
    return ON_SUCCESS;
}
/*删除指定值*/
int arrayListValRemove(arrayList *aList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    checkAlist(aList);

#if 0 /*只能删除一个数值*/
    for (int idx = aList->len - 1; idx >= 0; idx--)
    {
        if (val == aList->data[idx])
        {
            arrayListPosRemove(aList, idx);
        }
    }
#endif
    /*从后往前遍历删除*/
    for (int idx = aList->len - 1; idx >= 0; idx--)
    {
        /*优化*/
        if (compareFunc(aList->data[idx], val))
        {
            arrayListPosRemove(aList, idx);
        }
    }

    return ON_SUCCESS;
}

/*输出动态数组*/
int arrayListPrint(arrayList *aList, void (*printFunc)(ELEMENTTYPE))
{
    checkAlist(aList);
    for (int idx = 0; idx < aList->len; idx++)
    {
        printFunc(aList->data[idx]);
    }
    printf("\n");
}
/*动态数组销毁*/
int arrayListRuin(arrayList *aList)
{
    checkAlist(aList);
    for (int idx = 0; idx < aList->len; idx++)
    {
        arrayListTailRemove(aList);
    }
    if (aList->data != NULL)
    {
        free(aList->data);
        aList->data = NULL;
    }
    if (aList != NULL)
    {
        free(aList);
        aList = NULL;
    }
}