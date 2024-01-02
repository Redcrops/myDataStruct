#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INITIAL_SIZE 100
#define PRIME_NUM 97
enum STATUS_CODE
{
    CALLLOC_ERROR = -4,
    NULL_PTR,
    INVALID_KEY,
    INVALID_VAL,
    ON_SUCCESS,
};
/***********************静态函数前置声明*************************/
/*哈希函数*/
static int hashFunc(int key);

/*双链表头插法*/
static int headInsert(LinkList *list, Data key_value);

/*删除当前节点*/
static int deleteCurrentNode(ListNode *node);
/*尾删*/
static int deleteTailNode(LinkList *list);
/*清空头结点*/
static int freeHead(LinkList *list);
/*判空哈希表*/
static int checkHash(HashTable *hash);
/***********************静态函数实现*************************/
/*判空哈希表*/
static int checkHash(HashTable *hash)
{
    if (hash == NULL)
    {
        return NULL_PTR;
    }
}
/*清空头结点*/
static int freeHead(LinkList *list)
{
    if (list->head != NULL)
    {
        free(list->head);
        list->head = NULL;
    }
}
/*尾删*/
static int deleteTailNode(LinkList *list)
{
    ListNode *travelNode = list->head->next;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
    }
    if (travelNode != NULL)
    {
        free(travelNode);
        travelNode = NULL;
    }
}
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
    list->listLen++;
    return ON_SUCCESS;
}
static int deleteCurrentNode(ListNode *deleteNode)
{
    ListNode *preDeleteNode = deleteNode->prev;
    preDeleteNode->next = deleteNode->next;
    if (deleteNode->next != NULL)
    {
        deleteNode->next->prev = preDeleteNode;
    }

    if (deleteNode != NULL)
    {
        free(deleteNode);
        deleteNode = NULL;
    }
}
/***********************以上为静态函数*************************/
/*哈希表初始化*/
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
        hash->HashMap[idx]->listLen = 0;
    }

    /*解引用*/
    *Hash = hash;
    return ON_SUCCESS;
}
/*插入键值对*/
int hashTableInsert(HashTable *hash, Data key_value)
{
    checkHash(hash);
    /*通过哈希函数获得在哈希表中的存储位置*/
    int storeLocation = hashFunc(key_value.key);
    headInsert(hash->HashMap[storeLocation], key_value);
    return ON_SUCCESS;
}
/*查找关键字是否存在于哈希表中*/
bool hashTableSeek(HashTable *hash, int key)
{
    checkHash(hash);
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
    int keyLocation = hashFunc(key);
    if (hash->HashMap[keyLocation]->head->next == NULL)
    {
        return INVALID_KEY;
    }
    ListNode *travelNode = hash->HashMap[keyLocation]->head->next;
    while (travelNode != NULL)
    {
        if (travelNode->Data.key == key)
        {
            /*删除当前结点*/
            deleteCurrentNode(travelNode);
            break;
        }
        travelNode = travelNode->next;
    }
    return ON_SUCCESS;
}
/*哈希表的销毁*/
int ruinHashTable(HashTable *hash)
{
    checkHash(hash);
    /*清空哈希表中的每一个链表*/
    for (int idx = 0; idx < INITIAL_SIZE; idx++)
    {
        if (hash->HashMap[idx]->head->next != NULL)
        {
            ListNode *travelNode = hash->HashMap[idx]->head->next;
            while (travelNode != NULL)
            {
                /*释放链表节点*/
                ListNode *temp = travelNode->next;
                deleteCurrentNode(travelNode);
                travelNode = temp;
            }
            /*释放头结点*/
            if (hash->HashMap[idx]->head != NULL)
            {
                free(hash->HashMap[idx]->head);
                hash->HashMap[idx]->head = NULL;
            }
            /*释放链表*/
            if (hash->HashMap[idx] != NULL)
            {
                free(hash->HashMap[idx]);
                hash->HashMap[idx] = NULL;
            }
        }
    }
    /*清空哈希表*/
    if (hash->HashMap != NULL)
    {
        free(hash->HashMap);
        hash->HashMap = NULL;
    }
    if (hash != NULL)
    {
        free(hash);
        hash = NULL;
    }
    return ON_SUCCESS;
}