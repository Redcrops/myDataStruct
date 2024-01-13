#include "queue.h"
#include "arrayList.h"
#include <stdio.h>
/*队列初始化*/
int queueInit(Queue **queue)
{
    return arrayListInit(queue);
}
/*入队*/
int queuePush(Queue *queue, ELEMENTTYPE val)
{
    return arrayListTailInsert(queue, val);
}
/*出队*/
int queuePop(Queue *queue)
{
    return arrayListHeadRemove(queue);
}
/*获取栈顶元素*/
int queueTop(Queue *queue, ELEMENTTYPE *val)
{
    if (queue == NULL)
    {
        return NULL_PTR;
    }
    if (val == NULL)
    {
        return INVALID_VAL;
    }
    /*解引用*/
    *val = queue->data[0];

    return ON_SUCCESS;
}

/*输出队列*/
int queuePrint(Queue *queue, void (*pirnt)(ELEMENTTYPE))
{
    return arrayListPrint(queue, pirnt);
}

/*判断队列是否为空*/
int queueEmpty(Queue *queue)
{
    return queue->len == 0 ? 1 : 0;
}

/*销毁队列*/
int queueDestroy(Queue *queue)
{
    return arrayListRuin(queue);
}