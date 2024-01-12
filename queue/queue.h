#ifndef __QUEUE_H_
#define __QUEUE_H_
#include "common.h"

/*队列初始化*/
int queueInit(Queue **queue);
/*入队*/
int queuePush(Queue *queue, ELEMENTTYPE val);
/*出队*/
int queuePop(Queue *queue);
/*获取栈顶元素*/
int quequeTop(Queue *queue, ELEMENTTYPE *val);
/*输出队列*/
int queuePrint(Queue *queue, void (*pirnt)(ELEMENTTYPE));
/*销毁队列*/
int queueDestroy(Queue *queue);
#endif /*__QUEUE_H_*/