#ifndef __DOUBLE_LIST_H_
#define __DOUBLE_LIST_H_
#define ELEMENTTYPE void *
typedef struct DoubleListNode
{
    ELEMENTTYPE data;
    struct DoubleListNode *next;
    struct DoubleListNode *prev;
} DoubleListNode;

typedef struct DoubleList
{
    int len;
    DoubleListNode *head;
} DoubleList;

/*链表初始化*/
int doubleListInit(DoubleList **pList);
/*******************************插入************************************/
/*头插*/
int doubleListHeadInsert(DoubleList *pList, ELEMENTTYPE val);
/*尾插*/
int doubleListTailInsert(DoubleList *pList, ELEMENTTYPE val);
/*指定位置插*/
int doubleListPosInsert(DoubleList *pList, int pos, ELEMENTTYPE val);
/*******************************删除************************************/
/*头删*/
int doubleListHeadRemove(DoubleList *pList);
/*尾删*/
int doubleListTailRemove(DoubleList *pList);
/*指定位置删*/
int doubleListPosRemove(DoubleList *pList, int pos);
/*指定值删*/
int doubleListValRemove(DoubleList *pList, ELEMENTTYPE val);
/*根据值获得位置*/
int doubleListValGetPos(DoubleList *pList, ELEMENTTYPE val, int *pos);
/*输出链表*/
int doubleListPrint(DoubleList *pList, void (*printData)(ELEMENTTYPE));
/*链表的销毁*/
int doubleListRuin(DoubleList *pList);
#endif /*__DOUBLE_LIST_H_*/