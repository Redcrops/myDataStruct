#ifndef __ARRAY_LIST_H_
#define __ARRAY_LIST_H_

#define ELEMENTTYPE void *
#include <stdbool.h>
typedef struct arrayList
{
    int len;           // 动态数组现有元素个数（长度）
    int capacity;      // 动态数组最大容量
    ELEMENTTYPE *data; // 动态数组元素
} arrayList;

// 动态数组初始化
int arrayListInit(arrayList **aList);
/*插入*/
/*头插*/
int arrayListHeadInsert(arrayList *aList, ELEMENTTYPE val);
/*尾插*/
int arrayListTailInsert(arrayList *aList, ELEMENTTYPE val);
/*指定位置插入*/
int arrayListPosInsert(arrayList *aList, int pos, ELEMENTTYPE val);
/*********************************************************************/
/*删除*/
/*头删*/
int arrayListHeadRemove(arrayList *aList);
/*尾删*/
int arrayListTailRemove(arrayList *aList);
/*指定位置删除*/
int arrayListPosRemove(arrayList *aList, int pos);
/*删除指定值*/
int arrayListValRemove(arrayList *aList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));
/*输出动态数组*/
int arrayListPrint(arrayList *arrayList, void (*printFunc)(ELEMENTTYPE));
/*动态数组销毁*/
int arrayListRuin(arrayList *aList);
#endif