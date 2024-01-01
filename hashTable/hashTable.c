#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*哈希表初始化*/
#define INITIAL_SIZE 100
enum STATUS_CODE
{
    CALLLOC_ERROR = -4,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
    ON_SUCCESS,
};
int hashTableInit(HashTable **Hash)
{
    HashTable *hash = calloc(1, sizeof(HashTable));
    if (hash == NULL)
    {
        return CALLLOC_ERROR;
    }
    hash->HashMap = calloc(INITIAL_SIZE, sizeof(LinkList));
    if (hash->HashMap == NULL)
    {
        return CALLLOC_ERROR;
    }
    for (int idx = 0; idx < INITIAL_SIZE; idx++)
    {
        hash->HashMap[idx] = calloc(1, sizeof(LinkList));
        if (hash->HashMap[idx] == NULL)
        {
            return CALLLOC_ERROR;
        }
        hash->HashMap[idx]->head = calloc(1, sizeof(ListNode));
        if (hash->HashMap[idx]->head == NULL)
        {
            return CALLLOC_ERROR;
        }
        hash->HashMap[idx]->head->Data.key = 0;
        hash->HashMap[idx]->head->Data.value = 0;
        hash->HashMap[idx]->head->next = NULL;
        hash->HashMap[idx]->head->prev = hash->HashMap[idx]->head;
    }

    /*解引用*/
    *Hash = hash;
    return ON_SUCCESS;
}
/*插入键值对*/
int hashTableInsert(HashTable *hash, Data data)
{
    
}
/*查找关键字所在位置*/
int hashTableSeek(HashTable *hash, int key)
{
}
/*删除关键字结点*/
int hashTableDeleteKey(HashTable *hash, int key)
{
}
/*哈希表的销毁*/
int ruinHashTable(HashTable *hash)
{
}