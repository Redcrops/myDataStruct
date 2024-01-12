#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    MALLLOC_ERROR = -5,
    NULL_NODE,
    NULL_TREE,
    INVALID_POS,
    INVALID_VAL,
    ON_SUCCESS,
};
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
int bstreeInit(Bstree **bstree, int (*pCompare)(ELEMENTTYPE, ELEMENTTYPE))
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
    /*初始化回调函数*/
    tree->compare = pCompare;

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

    newNode = bstreeSearch(bstree, data);

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
}

/*二叉搜索树销毁*/
int bstreeDestroy(Bstree *bstree)
{
}