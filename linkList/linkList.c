#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*链表初始化*/
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
static int checkList(LinkList *pList);
static int baseValGetPos(LinkList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));
static int compareFunc(void *val1, void *val2);
/*****************************静态函数实现*************************************/
/*判链表空*/
static int checkList(LinkList *pList)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
}
static int baseValGetPos(LinkList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    ListNode *travelNode = pList->head->next;
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
int linkListInit(LinkList **pList)
{
    /*为链表分配空间*/
    LinkList *plist = calloc(1, sizeof(LinkList));
    if (plist == NULL)
    {
        return CALLLOC_ERROR;
    }
    /*为头节点分配空间*/
    plist->head = calloc(1, sizeof(ListNode));
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
    /*解引用*/
    *pList = plist;
}
/*******************************插入************************************/
/*头插*/
int linkListHeadInsert(LinkList *pList, ELEMENTTYPE val)
{
    return linkListPosInsert(pList, 0, val);
}
/*尾插*/
int linkListTailInsert(LinkList *pList, ELEMENTTYPE val)
{
    return linkListPosInsert(pList, pList->len, val);
}

/*指定位置插*/
int linkListPosInsert(LinkList *pList, int pos, ELEMENTTYPE val)
{
    checkList(pList);
    /*为新节点开辟空间*/
    ListNode *newNode = calloc(1, sizeof(ListNode));
    /*判空*/
    if (newNode == NULL)
    {
        return CALLLOC_ERROR;
    }
    /*维护新节点*/
    newNode->data = val;
    newNode->next = NULL;
    if (pos < 0 || pos > pList->len)
    {
        return INVALID_POS;
    }
    ListNode *travelNode = pList->head;
    for (int idx = 0; idx < pos; idx++)
    {
        travelNode = travelNode->next;
    }
    /*改变节点指针方向*/
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    /*长度增加*/
    pList->len++;
    return ON_SUCCESS;
}
/*******************************删除************************************/
/*头删*/
int linkListHeadRemove(LinkList *pList)
{
    return linkListPosRemove(pList, 1);
}
/*尾删*/
int linkListTailRemove(LinkList *pList)
{
    return linkListPosRemove(pList, pList->len);
}
/*指定位置删*/
int linkListPosRemove(LinkList *pList, int pos)
{
#if 1
    checkList(pList);
    /*pos在1到pList->len之间才合法*/
    if (pos < 1 || pos > pList->len)
    {
        return INVALID_POS;
    }
    /*新建移动指针*/
    ListNode *travelNode = pList->head;
    /*找到待删除结点的前一个结点*/
    for (int idx = 0; idx < pos - 1; idx++)
    {
        travelNode = travelNode->next;
    }
    ListNode *deleteNode = travelNode->next;
    /*更新指针*/

    travelNode->next = deleteNode->next;

    if (deleteNode != NULL)
    {
        free(deleteNode);
        deleteNode = NULL;
    }
    pList->len--;
    return ON_SUCCESS;
#endif
}
/*指定值删*/
int linkListValRemove(LinkList *pList, ELEMENTTYPE val)
{
    checkList(pList);
    ListNode *travelNode = pList->head->next;
#if 0 // bug,plist->len一直在更新，也无法像动态数组那样从尾到头遍历
    for (int idx = 1; idx <= pList->len; idx++)
    {
        if (compareFunc(travelNode->data, val))
        {
            linkListPosRemove(pList, idx);
            idx--;
        }
        travelNode = travelNode->next;
    }

#endif
    int pos = 0;
    while (travelNode != NULL && pos != NO_POS)
    {
        baseValGetPos(pList, val, &pos, compareFunc);
        linkListPosRemove(pList, pos);
        travelNode = travelNode->next;
    }
    if (pos == NO_POS)
    {
        return INVALID_VAL;
    }

    return ON_SUCCESS;
}
/*根据值获得位置*/
int linkListValGetPos(LinkList *pList, ELEMENTTYPE val, int *pos)
{
    checkList(pList);
    int idx = 1;
    ListNode *travelNode = pList->head->next;
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
int linkListPrint(LinkList *pList, void (*printData)(ELEMENTTYPE))
{
    checkList(pList);
    ListNode *travelNdoe = pList->head->next;
    while (travelNdoe != NULL)
    {
        printData(travelNdoe->data);
        travelNdoe = travelNdoe->next;
    }
    printf("\n");
}
/*链表的销毁*/
int linkListRuin(LinkList *pList)
{
    checkList(pList);
    /*从头到尾会有内存泄露*/
    for (int idx = pList->len; idx >= 1; idx--)
    {
        linkListTailRemove(pList);
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