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
/*****************************静态函数声明*************************************/
/*判链表空*/
static int checkList(LinkList *aList);
/*****************************静态函数实现*************************************/
/*判链表空*/
static int checkList(LinkList *aList)
{
    if (aList == NULL)
    {
        return NULL_PTR;
    }
}
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
}
/*尾删*/
int linkListTailRemove(LinkList *pList)
{
}
/*指定位置删*/
int linkListPosRemove(LinkList *pList, int pos)
{
}
/*指定值删*/
int linkListValRemove(LinkList *pList, ELEMENTTYPE val)
{
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
}