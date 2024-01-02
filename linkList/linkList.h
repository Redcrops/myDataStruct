#ifndef __LINK_LIST_H_
#define __LINK_LIST_H_
#define ELEMENTTYPE void *
typedef struct ListNode
{
    ELEMENTTYPE data;
    struct ListNode *next;
} ListNode;

typedef struct LinkList
{
    int len;
    ListNode *head;
} LinkList;

/*链表初始化*/
int linkListInit(LinkList **pList);
/*******************************插入************************************/
/*头插*/
int linkListHeadInsert(LinkList *pList, ELEMENTTYPE val);
/*尾插*/
int linkListTailInsert(LinkList *pList, ELEMENTTYPE val);
/*指定位置插*/
int linkListPosInsert(LinkList *pList, int pos, ELEMENTTYPE val);
/*******************************删除************************************/
/*头删*/
int linkListHeadRemove(LinkList *pList);
/*尾删*/
int linkListTailRemove(LinkList *pList);
/*指定位置删*/
int linkListPosRemove(LinkList *pList, int pos);
/*指定值删*/
int linkListValRemove(LinkList *pList, ELEMENTTYPE val);
/*根据值获得位置*/
int linkListValGetPos(LinkList *pList, ELEMENTTYPE val,int *pos);
/*输出链表*/
int linkListPrint(LinkList *pList, void (*printData)(ELEMENTTYPE));
/*链表的销毁*/
int linkListRuin(LinkList *pList);
#endif /*__LINK_LIST_H_*/