#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*哈希表初始化*/
#define INITIAL_SIZE 100
#define PRIME_NUM 97
enum STATUS_CODE
{
    CALLLOC_ERROR = -4,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
    ON_SUCCESS,
};
/***********************静态函数前置声明*************************/
/*哈希函数*/
static int hashFunc(int key);

/*双链表头插法*/
static int headInsert(LinkList *list, Data key_value);
/***********************静态函数实现*************************/
/*除留余数法*/
static int hashFunc(int key)
{
    /*选择小于哈希表长度的最大质数来做取余*/
    int ret = key % PRIME_NUM;
    return ret;
}

/*双链表头插法*/
static int headInsert(LinkList *list, Data key_value)
{
    ListNode *newNode = calloc(1, sizeof(ListNode));
    if (newNode == NULL)
    {
        return CALLLOC_ERROR;
    }

    /*初始化新节点*/
    newNode->Data.key = key_value.key;
    newNode->Data.value = key_value.value;
    newNode->next = NULL;
    newNode->prev = NULL;
    /*修改指针指向*/
    newNode->prev = list->head;
    newNode->next = list->head->next;
    if (list->head->next != NULL)
    {
        list->head->next->prev = newNode;
    }
    list->head->next = newNode;
    return ON_SUCCESS;
}
/***********************以上为静态函数*************************/
int hashTableInit(HashTable **Hash)
{
    HashTable *hash = calloc(1, sizeof(HashTable));
    if (hash == NULL)
    {
        return CALLLOC_ERROR;
    }
    hash->mapLen = INITIAL_SIZE;
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
int hashTableInsert(HashTable *hash, Data key_value)
{
    /*通过哈希函数获得在哈希表中的存储位置*/
    int storeLocation = hashFunc(key_value.key);
    headInsert(hash->HashMap[storeLocation], key_value);
    return ON_SUCCESS;
}
/*查找关键字是否存在于哈希表中*/
bool hashTableSeek(HashTable *hash, int key)
{
    int keyLocation = hashFunc(key);
    if (hash->HashMap[keyLocation]->head->next == NULL)
    {
        return false;
    }
    ListNode *travelNode = hash->HashMap[keyLocation]->head->next;
    while (travelNode != NULL)
    {
        if (travelNode->Data.key == key)
        {
            return true;
        }
        travelNode = travelNode->next;
    }
    return false;
}
/*删除关键字结点*/
int hashTableDeleteKey(HashTable *hash, int key)
{
}
/*哈希表的销毁*/
int ruinHashTable(HashTable *hash)
{
}