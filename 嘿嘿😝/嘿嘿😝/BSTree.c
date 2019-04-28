//
//  BSTree.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/29.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "BSTree.h"
#include <stdlib.h>
typedef struct _tag_TBSTree
{
    BSTreeNode *root;
    int count;

}TBSTree;

BSTree *BSTree_Create(void)
{
    TBSTree *tree = (TBSTree *)malloc(sizeof(TBSTree));
    if(tree != NULL)
    {
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}


void BSTree_Destroy(BSTree *tree)
{
    free(tree);
}

void BSTree_Clear(BSTree *tree)
{
    TBSTree *sTree = (BSTree *)tree;
    if(sTree != NULL)
    {
        sTree->count = 0;
        sTree->root = NULL;
    }
}

static int bsTreeRecursive_Insert(BSTreeNode *root,BSTreeNode *node,CompareFun *cFun)
{
    int ret = 1;
    int result = cFun(root,node);
    if(result == 0)
    {
        ret = 0;
    }else{

        if(result < 0)
        {
            if(root->left == NULL)
            {
                root->left = node;
            }else{
                ret = bsTreeRecursive_Insert(root->left, node, cFun);
            }
        }
        if(result > 0)
        {
            if(root->right == NULL)
            {
                root->right = node;
            }else{
                ret = bsTreeRecursive_Insert(root->right, node, cFun);
            }
        }
    }
    return ret;
}
int BSTree_Insert(BSTree *tree,BSTreeNode *node, CompareFun *cFun)
{
    TBSTree *sTree = (TBSTree *)tree;
    int ret = sTree != NULL && node != NULL && cFun != NULL;
    if(ret)
    {
        node->left = NULL;
        node->right = NULL;

        if(sTree->root == NULL)
        {
            sTree->root = node;
        }else{
            ret = bsTreeRecursive_Insert(sTree->root,node, cFun);
        }
    }
    if(ret)
    {
        sTree->count++;
    }
    return ret;
}

BSTreeNode * bstree_DeleteNode(BSTreeNode **pRoot)
{
    BSTreeNode *ret = *pRoot;
    if(pRoot != NULL && *pRoot != NULL)
    {
        // 左右子树中其中一个为空，则另外一个子树直接上位
        if((*pRoot)->left == NULL)
        {
            *pRoot = (*pRoot)->left;
        }else if ((*pRoot)->right == NULL)
        {
            *pRoot = (*pRoot)->right;
        }else{
            // 左右子树不为空，寻找被删节点中序遍历下的直接前驱作为替代点
            BSTreeNode *p = *pRoot;
            BSTreeNode *c = (*pRoot)->left;

            // 以被删除节点向左出发一次（左子树）
            // 之后一直向右（右子树），直到右子树为空，该点为替代点）

            // 找出替代点c
            while (c != NULL) {
                p = c;
                c = c->right;
            }
            // 寻找结果为被删节点左子树的子节点
            if(p != *pRoot)
            {
                // 使用c父节点的左子树保存c的左子树
                //（因为一直往右找，直到右子树为空结束，所以使用c父节点右子树
                // 保存c左子树，c的右子树一定为空，不用保存）
                p->right = c->left;
            }else{
                // 寻找结果c为被删节点左子树
                // p左子树直接保存c左子树的
                p->left = c->left;
            }
            // 替换点保存被替换点的左右子树
            c->left = (*pRoot)->left;
            c->right = (*pRoot)->right;
            // 修改被替换点父节点，使其指向新替换点
            *pRoot = c;
        }
    }
    return ret;
}
BSTreeNode *bsTreeRecursive_Delete(BSTreeNode **pRoot,BSKey*key,CompareFun *cFun)
{
    BSTreeNode *ret = NULL;
    int reslut = 0;
    if(pRoot != NULL && *pRoot != NULL && key != NULL)
    {
        reslut = cFun((*pRoot)->key, key);
        if(reslut == 0)
        {
           ret = bstree_DeleteNode(pRoot);
        }else if( reslut < 0)
        {
            ret = bsTreeRecursive_Delete(&(*pRoot)->left, key, cFun);
        }else if(reslut > 0)
        {
            ret = bsTreeRecursive_Delete(&(*pRoot)->right, key, cFun);
        }
    }

    return ret;
}
BSTreeNode *BSTree_Delete(BSTree *tree, BSKey *key, CompareFun *cFun)
{
    BSTreeNode *ret = NULL;
    TBSTree *sTree = (TBSTree *)tree;
    if(sTree != NULL && cFun != NULL)
    {
        ret = bsTreeRecursive_Delete(&sTree->root, key, cFun);
    }
    return ret;
}
BSTreeNode *bsTreeRecursive_Get(BSTreeNode *root, BSKey *key, CompareFun *cFun)
{
    BSTreeNode *ret = NULL;
    int result = 0;
    if(key != NULL && cFun != NULL)
    {
        result = cFun(root->key,key);
        if(result == 0)
        {
            ret = root;
        }else if (result < 0){

            ret = bsTreeRecursive_Get(root->left, key, cFun);
        }else if (result > 0){

            ret = bsTreeRecursive_Get(root->right, key, cFun);
        }

    }
    return ret;
}
BSTreeNode *BSTree_Get(BSTree *tree ,BSKey *key, CompareFun *cFun)
{
    TBSTree *sTree = (TBSTree *)tree;
    BSTreeNode *ret = NULL;
    if(sTree != NULL && key != NULL && cFun != NULL)
    {
        ret = bsTreeRecursive_Get(sTree->root, key, cFun);
    }
    return ret;
}

BSTreeNode *BSTree_Root(BSTree *tree)
{
    TBSTree *sTree = (TBSTree *)tree;
    BSTreeNode *ret = NULL;
    if(sTree != NULL)
    {
        ret = sTree->root;
    }
    return ret;
}

int BSTree_Length(BSTree *tree)
{
    TBSTree *sTree = (TBSTree *)tree;
    int ret = 0;
    if(sTree != NULL)
    {
        ret = sTree->count;
    }
    return ret;
}

int bsTreeRecursive_Degree(BSTreeNode *root)
{
    int ret = 0;
    int ld = 0;
    int rd = 0;
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            ret++;
        }
        if(root->right != NULL)
        {
            ret++;
        }
        if(ret < 2)
        {
            ld = bsTreeRecursive_Degree(root->left);
            if(ret < ld)
            {
                ret = ld;
            }
            rd = bsTreeRecursive_Degree(root->right);
            if(ret < rd)
            {
                ret = rd;
            }
        }
    }
    return ret;
}
int BSTree_Degree(BSTree *tree)
{
    TBSTree *sTree = (TBSTree *)tree;
    int ret = 0;
    if(sTree != NULL)
    {
        ret = bsTreeRecursive_Degree(sTree->root);
    }
    return ret;
}
int bsTreeRecursive_Height(BSTreeNode *root)
{
    int ret = 0;
    int lh = 0;
    int rh = 0;
    if(root != NULL)
    {
       lh = bsTreeRecursive_Height(root->left);
       rh = bsTreeRecursive_Height(root->right);
       ret = lh > rh ? lh : rh;
       ret++;
    }

    return ret;
}
int BSTree_Height(BSTree *tree)
{
    TBSTree *sTree = (TBSTree *)tree;
    int ret = 0;
    if(sTree != NULL)
    {
        ret = bsTreeRecursive_Height(sTree->root);
    }
    return ret;
}
void bsTreeRecursive_display(BSTreeNode *root,int format, char div, PrintFun *pFun)
{
    if(root != NULL)
    {
        for(int i = 0; i < format; i++)
        {
            printf("%c",div);
        }
        pFun(root);
        printf("\n");
        if(root->left != NULL || root->right != NULL)
        {
            bsTreeRecursive_display(root->left, format + 3, div, pFun);
            bsTreeRecursive_display(root->right, format + 3, div, pFun);
        }
    }else{

        // 函数有进来就打一遍格式
        for(int i = 0; i < format; i++)
        {
            printf("%c",div);
        }
        printf("\n");
    }
}
void BSTree_Display(BSTree *tree,PrintFun *pFun)
{
    TBSTree *sTree = (TBSTree *)tree;
    if(sTree != NULL && pFun != NULL)
    {
        bsTreeRecursive_display(sTree->root, 0, '-', pFun);
    }
}
