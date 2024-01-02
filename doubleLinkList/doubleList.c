#include "doubleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum STATUS_CODE
{
    CALLLOC_ERROR = -4,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
    ON_SUCCESS,
};
#define NO_POS -1
/*****************************静态函数声明*************************************/
/*判链表空*/
static int checkList(DoubleList *pList);
static int baseValGetPos(DoubleList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));
static int compareFunc(void *val1, void *val2);
/*****************************静态函数实现*************************************/
/*判链表空*/
static int checkList(DoubleList *pList)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
}
static int baseValGetPos(DoubleList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    DoubleListNode *travelNode = pList->head->next;
    int pos = 1;
    while (travelNode != NULL)
    {
        if (compareFunc(travelNode->data, val))
        {
            *pPos = pos;
            return ON_SUCCESS;
        }
        travelNode = travelNode->next;
        pos++;
    }
    /*如果没有找到置-1*/
    pos = NO_POS;
    *pPos = pos;
    return INVALID_VAL;
}
static int compareFunc(void *val1, void *val2)
{
    return *(int *)val1 == *(int *)val2 ? 1 : 0;
}
/*****************************以上为静态函数*************************************/
/*双链表初始化*/
int doubleListInit(DoubleList **pList)
{
    /*为链表分配空间*/
    DoubleList *plist = calloc(1, sizeof(DoubleListNode));
    if (plist == NULL)
    {
        return CALLLOC_ERROR;
    }
    /*为头节点分配空间*/
    plist->head = calloc(1, sizeof(DoubleListNode));
    if (plist->head == NULL)
    {
        /*如果分配头结点失败，释放整个链表，防止内存泄露*/
        free(plist);
        plist == NULL;
        return CALLLOC_ERROR;
    }
    /*表长初始化*/
    plist->len = 0;
    /*头结点初始化*/
    plist->head->data = 0;
    plist->head->next = NULL;
    plist->head->prev = plist->head;
    /*解引用*/
    *pList = plist;
}
/*******************************插入************************************/
/*头插*/
int doubleListHeadInsert(DoubleList *pList, ELEMENTTYPE val)
{
    doubleListPosInsert(pList, 0, val);
}
/*尾插*/
int doubleListTailInsert(DoubleList *pList, ELEMENTTYPE val)
{
    doubleListPosInsert(pList, pList->len, val);
}
/*指定位置插*/
int doubleListPosInsert(DoubleList *pList, int pos, ELEMENTTYPE val)
{
    checkList(pList);
    /*为新节点开辟空间*/
    DoubleListNode *newNode = calloc(1, sizeof(DoubleListNode));
    /*判空*/
    if (newNode == NULL)
    {
        return CALLLOC_ERROR;
    }
    /*维护新节点*/
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (pos < 0 || pos > pList->len)
    {
        return INVALID_POS;
    }
    DoubleListNode *travelNode = pList->head;
    for (int idx = 0; idx < pos; idx++)
    {
        travelNode = travelNode->next;
    }
    /*改变节点指针方向*/
    newNode->next = travelNode->next;
    newNode->prev = travelNode;
    travelNode->next = newNode;
    if (travelNode->next != NULL)
    {
        travelNode->next->prev = newNode;
    }

    /*长度增加*/
    pList->len++;
    return ON_SUCCESS;
}
/*******************************删除************************************/
/*头删*/
int doubleListHeadRemove(DoubleList *pList)
{
    return doubleListPosRemove(pList, 1);
}
/*尾删*/
int doubleListTailRemove(DoubleList *pList)
{
    return doubleListPosRemove(pList, pList->len);
}
/*指定位置删*/
int doubleListPosRemove(DoubleList *pList, int pos)
{
    checkList(pList);
    /*pos在1到pList->len之间才合法*/
    if (pos < 1 || pos > pList->len)
    {
        return INVALID_POS;
    }
    /*新建移动指针*/
    DoubleListNode *travelNode = pList->head;
    /*找到待删除结点的前一个结点*/
    for (int idx = 0; idx < pos - 1; idx++)
    {
        travelNode = travelNode->next;
    }
    DoubleListNode *deleteNode = travelNode->next;
    /*更新指针*/

    travelNode->next = deleteNode->next;
    if (travelNode->next != NULL)
    {
        travelNode->next->prev = deleteNode;
    }

    if (deleteNode != NULL)
    {
        free(deleteNode);
        deleteNode = NULL;
    }
    pList->len--;
    return ON_SUCCESS;
}
/*指定值删*/
int doubleListValRemove(DoubleList *pList, ELEMENTTYPE val)
{
    checkList(pList);
    DoubleListNode *travelNode = pList->head->next;
    int pos = 0;
    while (travelNode != NULL && pos != NO_POS)
    {
        baseValGetPos(pList, val, &pos, compareFunc);
        doubleListPosRemove(pList, pos);
        travelNode = travelNode->next;
    }
    if (pos == NO_POS)
    {
        return INVALID_VAL;
    }

    return ON_SUCCESS;
}
/*根据值获得位置*/
int doubleListValGetPos(DoubleList *pList, ELEMENTTYPE val, int *pos)
{
    checkList(pList);
    int idx = 1;
    DoubleListNode *travelNode = pList->head->next;
    if (travelNode == NULL)
    {
        return INVALID_VAL;
    }
    while (travelNode != NULL)
    {
        if (compareFunc(travelNode->data, val))
        {
            *pos = idx;
            return ON_SUCCESS;
        }
        travelNode = travelNode->next;
        idx++;
    }
}
/*输出链表*/
int doubleListPrint(DoubleList *pList, void (*printData)(ELEMENTTYPE))
{
    checkList(pList);
    DoubleListNode *travelNdoe = pList->head->next;
    while (travelNdoe != NULL)
    {
        printData(travelNdoe->data);
        travelNdoe = travelNdoe->next;
    }
    printf("\n");
}
/*双链表的销毁*/
int doubleListRuin(DoubleList *pList)
{
    checkList(pList);
    /*从头到尾会有内存泄露*/
    for (int idx = pList->len; idx >= 1; idx--)
    {
        doubleListTailRemove(pList);
    }
    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
    }
    if (pList != NULL)
    {
        free(pList);
        pList = NULL;
    }
    return ON_SUCCESS;
}