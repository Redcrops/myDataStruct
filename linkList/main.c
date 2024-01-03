#include "linkList.h"
#include <stdio.h>
#define BUFFER_SIZE 3
/*需要输出什么类型数据可自行修改*/
void printBasicDataType(void *val)
{
    int num = *(int *)val;
    printf("%d\t", num);
}

int compareFunc(void *num1, void *num2)
{
    return *(int *)num1 <= *(int *)num2 ? 1 : 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*合并两个有序链表*/
LinkList *mergeTwoLists(LinkList *list1, LinkList *list2)
{
    /*pList1指向链表1的第一个结点*/
    ListNode *pList1 = list1->head->next;
    /*如果链表1为空直接返回链表2*/
    if (pList1 == NULL)
    {
        return list2;
    }
    /*pList2指向链表2的第一个结点*/
    ListNode *pList2 = list2->head->next;
    /*如果链表2为空直接返回链表1*/
    if (pList2 == NULL)
    {
        return list1;
    }
    /*如果list1和list2都为空，则返回NULL*/
    if (pList2 == NULL && pList1 == NULL)
    {
        return NULL;
    }
    /*创建一个新链表，用来存放合并后的链表*/
    LinkList *newList = NULL;
    linkListInit(&newList);

    while (pList1 != NULL && pList2 != NULL)
    {
        /*如果表1数据小于等于表2数据则尾插进入新链表*/
        if (compareFunc(pList1->data, pList2->data))
        {
            linkListTailInsert(newList, pList1->data);
            /*指针后移*/
            pList1 = pList1->next;
        }
        else
        /*如果表2数据小于表1数据则尾插进入新链表*/
        {
            linkListTailInsert(newList, pList2->data);
            /*指针后移*/
            pList2 = pList2->next;
        }
    }
    /*退出条件为表1遍历完成或者表2遍历完成*/

    /*如果表1遍历完成，表2还没有，则表2全部元素直接尾插进入新链表*/
    while (pList2 != NULL)
    {
        linkListTailInsert(newList, pList2->data);
        /*指针后移*/
        pList2 = pList2->next;
    }
    /*如果表2遍历完成，表1还没有，则表2全部元素直接尾插进入新链表*/
    while (pList1 != NULL)
    {
        linkListTailInsert(newList, pList1->data);
        /*指针后移*/
        pList1 = pList1->next;
    }
    return newList;
}
int main()
{
/*测试用例*/
#if 0 // 链表增删改查测试
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

    // printf("pos2 remove \n");
    // linkListPosRemove(singleList, 2);
    // linkListPrint(singleList, printBasicDataType);

    // printf("head remove \n");
    // linkListHeadRemove(singleList);
    // linkListPrint(singleList, printBasicDataType);

    // printf("tail remove \n");
    // linkListTailRemove(singleList);
    // linkListPrint(singleList, printBasicDataType);

    printf("tail insert 2,1,2\n");
    int num[BUFFER_SIZE] = {2, 1, 2};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        linkListTailInsert(singleList, (void *)&num[idx]);
    }
    linkListPrint(singleList, printBasicDataType);

    printf("val remove 2 \n");
    int num5 = 2;
    linkListValRemove(singleList, &num5);
    linkListPrint(singleList, printBasicDataType);

    linkListRuin(singleList);
#endif
#if 1 // 合并两个有序链表

    LinkList *list1 = NULL;
    LinkList *list2 = NULL;
    linkListInit(&list1);
    linkListInit(&list2);
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        linkListTailInsert(list1, &arr1[idx]);
    }
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        linkListTailInsert(list2, &arr2[idx]);
    }
    printf("list1:");
    linkListPrint(list1, printBasicDataType);
    printf("list2:");
    linkListPrint(list2, printBasicDataType);
    LinkList *totalList = mergeTwoLists(list1, list2);
    printf("totalList:");
    linkListPrint(totalList, printBasicDataType);

#endif
    return 0;
}