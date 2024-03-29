#ifndef __BSTREE_H_
#define __BSTREE_H_

#define ELEMENTTYPE void *

typedef struct BstreeNode
{
    ELEMENTTYPE val;
    struct BstreeNode *parent;
    struct BstreeNode *left;
    struct BstreeNode *right;
} BstreeNode;

typedef struct Bstree
{
    BstreeNode *root;
    int high;
    /* 树的节点个数 */
    int size;
    int (*compare)(ELEMENTTYPE, ELEMENTTYPE);
    void (*printTree)(ELEMENTTYPE);
} Bstree;
/*二叉搜索树初始化*/
int bstreeInit(Bstree **bstree, int (*pCompare)(ELEMENTTYPE, ELEMENTTYPE), void (*printTree)(ELEMENTTYPE));

/*二叉搜索树插入*/
int bstreeInsert(Bstree *bstree, ELEMENTTYPE data);

/*二叉搜索树查找*/
BstreeNode *bstreeSearch(Bstree *bstree, ELEMENTTYPE data);

/*二叉搜索树删除*/
int bstreeRemove(Bstree *bstree, ELEMENTTYPE data);

/*二叉搜索树前序遍历*/
int bstreePrePrint(Bstree *bstree);

/*二叉搜索树中序遍历*/
int bstreeInorderPrint(Bstree *bstree);

/*二叉搜索树后序遍历*/
int bstreePostPrint(Bstree *bstree);

/*二叉搜索树层序遍历*/
int bstreeLevelPrint(Bstree *bstree);

/*二叉搜索树销毁*/
int bstreeDestroy(Bstree *bstree);
#endif /*__BSTREE_H_*/