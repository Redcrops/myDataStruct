#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

typedef struct Data
{
    int key;
    int value;
} Data;

typedef struct ListNode
{
    struct ListNode *prev;
    struct ListNode *next;
    Data Data;
} ListNode;

typedef struct LinkList
{
    struct ListNode *head;
    int listLen;
} LinkList;

typedef struct HashTable
{
    LinkList **HashMap;
    int mapLen;
} HashTable;
/*哈希表初始化*/
int hashTableInit(HashTable **Hash);
/*插入键值对*/
int hashTableInsert(HashTable *hash, Data data);
/*查找关键字所在位置*/
int hashTableSeek(HashTable *hash, int key, , int *storeLocation);
/*删除关键字结点*/
int hashTableDeleteKey(HashTable *hash, int key);
/*哈希表的销毁*/
int ruinHashTable(HashTable *hash);
#endif