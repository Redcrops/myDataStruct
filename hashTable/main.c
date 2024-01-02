#include <stdio.h>
#include "hashTable.h"
#define BUFFER_SIZE 3
int main()
{
    HashTable *hash = NULL;
    hashTableInit(&hash);
    Data keyValArray[BUFFER_SIZE] = {
        {155, 1},
        {289, 2},
        {346, 3}};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        hashTableInsert(hash, keyValArray[idx]);
    }
    int status = hashTableSeek(hash, 289);
    printf("status=%d\n", status);

    hashTableDeleteKey(hash, 289);
    status = hashTableSeek(hash, 289);
    printf("status=%d\n", status);

    ruinHashTable(hash);
    return 0;
}