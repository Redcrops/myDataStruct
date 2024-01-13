#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
/*************************静态函数前置声明****************************/
static int checkBstree(Bstree *bstree);
static int checkBstreeNode(BstreeNode *node);
/*************************静态函数前置实现****************************/
static int checkBstree(Bstree *bstree)
{
    if (bstree == NULL)
    {
        return NULL_TREE;
    }
}
static int checkBstreeNode(BstreeNode *node)
{
    if (node == NULL)
    {
        return NULL_NODE;
    }
}
/*************************静态函数---实现函数分割线*************************/
/*二叉搜索树初始化*/
int bstreeInit(Bstree **bstree, int (*pCompare)(ELEMENTTYPE, ELEMENTTYPE), void (*print)(ELEMENTTYPE))
{
    Bstree *tree = calloc(1, sizeof(Bstree));
    checkBstree(tree);
    tree->root = calloc(1, sizeof(BstreeNode));
    checkBstreeNode(tree->root);

    /*维护根节点*/
    tree->root->left == NULL;
    tree->root->right == NULL;
    tree->root->parent == NULL;

    tree->high = 0;
    /**/
    tree->size = 0;
    /*初始化回调函数*/
    tree->compare = pCompare;
    tree->printTree = print;

    /*解引用*/
    *bstree = tree;
    return ON_SUCCESS;
}

/*二叉搜索树插入*/
int bstreeInsert(Bstree *bstree, ELEMENTTYPE data)
{
    checkBstree(bstree);

    BstreeNode *newNode = calloc(1, sizeof(BstreeNode));
    checkBstreeNode(newNode);

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->val = data;

    /*判断树中是否存在根节点*/
    if (bstree->size == 0)
    {
        /*没有根节点，新节点成为根节点*/
        bstree->root = newNode;
    }
    else
    {
        /*有根节点，寻找新节点位置*/
        BstreeNode *travel = bstree->root;
        /*parentNode记录travel的父节点位置*/
        BstreeNode *parentNode = NULL;
        while (travel != NULL)
        {
            /*寻找待插入结点的父节点*/
            parentNode = travel;
            if (bstree->compare(data, travel->val) > 0)
            {
                travel = travel->right;
            }
            else if (bstree->compare(data, travel->val) < 0)
            {
                travel = travel->left;
            }
            else
            {
                /*如果树中已经存在待插入值，直接返回*/
                return ON_SUCCESS;
            }
        }
        newNode->parent = parentNode;
        if (bstree->compare(newNode->val, parentNode->val) < 0)
        {
            parentNode->left = newNode;
        }
        else
        {
            parentNode->right = newNode;
        }
    }
    bstree->size++;

    return ON_SUCCESS;
}

/*二叉搜索树查找*/
BstreeNode *bstreeSearch(Bstree *bstree, ELEMENTTYPE data)
{
    checkBstree(bstree);
    BstreeNode *travel = bstree->root;
    while (travel != NULL)
    {
        if (bstree->compare(data, travel->val) > 0)
        {
            travel = travel->right;
        }
        else if (bstree->compare(data, travel->val) < 0)
        {
            travel = travel->left;
        }
        else
        {
            return travel;
        }
    }
    return travel;
}

/*二叉搜索树删除*/
int bstreeRemove(Bstree *bstree, ELEMENTTYPE data)
{
}

/*二叉搜索树前序遍历*/
int bstreePrePrint(Bstree *bstree)
{
}

/*二叉搜索树中序遍历*/
int bstreeInorderPrint(Bstree *bstree)
{
}

/*二叉搜索树后序遍历*/
int bstreePostPrint(Bstree *bstree)
{
}

/*二叉搜索树层序遍历*/
int bstreeLevelPrint(Bstree *bstree)
{
    checkBstree(bstree);
    Queue *que = NULL;
    queueInit(&que);
    queuePush(que, bstree->root);
    BstreeNode *popNode = NULL;

    while (!queueEmpty(que))
    {
        queueTop(que, (void **)&popNode);
        bstree->printTree(popNode->val);
        queuePop(que);

        if (popNode->left != NULL)
        {
            queuePush(que, popNode->left);
        }
        if (popNode->right != NULL)
        {
            queuePush(que, popNode->right);
        }
    }
    printf("\n");
    return ON_SUCCESS;
}

/*二叉搜索树销毁*/
int bstreeDestroy(Bstree *bstree)
{
}