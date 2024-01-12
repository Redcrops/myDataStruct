#ifndef __COMMON_H_
#define __COMMON_H_

#define ELEMENTTYPE void *
typedef struct arrayList
{
    int len;           // 动态数组现有元素个数（长度）
    int capacity;      // 动态数组最大容量
    ELEMENTTYPE *data; // 动态数组元素
} arrayList;

typedef arrayList Queue;

enum STATUS_CODE
{
    MALLLOC_ERROR = -4,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
    ON_SUCCESS,
};
#endif /*__COMMON_H_*/
