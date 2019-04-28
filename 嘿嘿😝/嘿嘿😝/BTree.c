//
//  BTree.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/22.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "BTree.h"
#include <stdlib.h>
#include "LinkQueue.h"
#include "SequenceList.h"

typedef struct _tag_BTree TBTree;
struct _tag_BTree
{
    BTreeNode *root;
    int length;
};
#define BT_LEFT 0
#define BTreeRIGHT 1
BTree *BTree_Create(void)
{

    TBTree *ret = (TBTree *)malloc(sizeof(TBTree));
    if(ret != NULL)
    {
        ret->root = NULL;
        ret->length = 0;
    }
    return ret;
}
void BTree_Destroy(BTree *tree)
{
    BTree_Clear(tree);
    free(tree);
}

void BTree_Clear(BTree *tree)
{
    TBTree *sTree = (TBTree *)tree;
    if(sTree != NULL)
    {
        sTree->length = 0;
        sTree->root = NULL;
    }
}

int BTree_Insert(BTree *tree,BTreeNode *node,BTPos pos,int count,int flag)
{
    TBTree *sTree = (TBTree *)tree;
    int ret = 0;
    ret = sTree != NULL && node != NULL && (flag == 0 || flag == 1);
    if(ret)
    {
        int bit = 0;
        BTreeNode *parent = NULL;
        BTreeNode *current = sTree->root;

        node->left = NULL;
        node->right = NULL;

        while (count > 0 && current != NULL)
        {
            bit = pos & 1;
            pos = pos >> 1;
            parent = current;

            if(bit == BT_LEFT)
            {
                current = current->left;
            }else{
                current = current->right;
            }
        }
        if(flag)
        {
            node->left = current;
        }else{
            node->right = current;
        }
        if(parent != NULL)
        {
            if(bit == BT_LEFT)
            {
                parent->left = node;
            }else{
                parent->right = node;
            }
        }else{
            sTree->root = node;
        }
        sTree->length++;
    }
    return ret;
}
static int recursive_length(BTreeNode *node)
{
    int ret = 0;
    if(node != NULL)
    {
        ret = recursive_length(node->left) + 1 + recursive_length(node->right);
    }
    return ret;
}
BTreeNode *BTree_Delete(BTree *tree,BTPos pos, int count)
{
    TBTree *sTree = (TBTree *)tree;
    BTreeNode *ret = NULL;
    if(sTree != NULL && count > 0)
    {
        BTreeNode *parent = NULL;
        BTreeNode *current = sTree->root;
        int bit = 0;
        while (count > 0 && current != NULL) {

            bit = pos & 1;
            pos = pos >> 1;
            parent = current;
            if(bit == BT_LEFT)
            {
                current = current->left;
            }else{
                current = current->right;
            }
            count--;
        }

        if(parent != NULL)
        {
            if(bit == BT_LEFT)
            {
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }

        }else{
            sTree->root = NULL;
        }
        ret = current;
        sTree->length = sTree->length - recursive_length(ret);
    }

    return ret;
}

BTreeNode *BTree_Get(BTree *tree,BTPos pos, int count)
{
    BTreeNode *ret = NULL;
    TBTree *sTree = (TBTree *)tree;
    int bit = 0;
    if(sTree != NULL && count > 0)
    {
        BTreeNode *current = sTree->root;
        // 找到位置
        while (count > 0 && current != NULL) {

            bit = pos & 1;
            pos = pos >> 1;

            if(bit == BT_LEFT)
            {
                current = current->left;
            }else{
                current = current->right;
            }
            count--;
        }
        // 返回
        ret = current;
    }
    return ret;
}

BTreeNode *BTree_Root(BTree *tree)
{
    BTreeNode *ret = NULL;
    TBTree *sTree = (TBTree *)tree;
    if(sTree != NULL)
    {
        ret = sTree->root;
    }
    return ret;
}


int BTree_Length(BTree *tree)
{
    TBTree *sTree = (TBTree *)tree;
    int ret = 0;
    if(sTree != NULL)
    {
        ret = sTree->length;
    }
    return ret;
}

static int recursive_degree(BTreeNode *node)
{
    int ret = 0;
    int degree1 = 0;
    int degree2 = 0;
    if(node != NULL)
    {
        if(node->left != NULL)
        {
            ret++;
        }

        if(node->right != NULL)
        {
            ret++;
        }
        if(ret == 1)
        {
            degree1 = recursive_degree(node->left);
            if(ret < degree1)
            {
                ret = degree1;
            }
            degree2 = recursive_degree(node->right);

            if(ret < degree2)
            {
                ret = degree2;
            }
        }
    }
    return ret;
}

int BTree_Degree(BTree *tree)
{
    TBTree *sTree = (TBTree *)tree;
    int ret = 0;
    if(sTree != NULL)
    {
        ret = recursive_degree(sTree->root);
    }
    return ret;
}
static int recursive_height(BTreeNode *node)
{
    int ret = 0;

    int lh = 0;
    int rh = 0;
    if( node != NULL)
    {
        lh = recursive_height(node->left);
        rh = recursive_height(node->right);
        ret = (lh > rh ? lh : rh) + 1;
    }
    return ret;
}
int BTree_Height(BTree *tree)
{
    TBTree *sTree = (TBTree *)tree;
    int ret = 0;
    if(sTree != NULL)
    {
        ret = recursive_height(sTree->root);
    }
    return ret;
}
void recursive_display(BTreeNode *node,PrintFun *pFun,int format, int gap)
{
    if(node != NULL)
    {
        for(int i = 0; i < format; i++)
        {
            printf("-");
        }
        pFun(node);
        if(node->left != NULL || node->right != NULL)
        {
            recursive_display(node->left,pFun,format+gap,gap);
            recursive_display(node->right,pFun,format+gap,gap);
        }
    }else{
        for(int i = 0; i < format; i++)
        {
            printf("-");
        }
    }
}
void BTree_Display(BTree *tree,PrintFun *pFun)
{
    TBTree *sTree = (TBTree *)tree;
    if(sTree != NULL)
    {
        recursive_display(sTree->root, pFun, 0, 2);
    }
}

void preOrderTraversal(BTreeNode *node,PrintFun *pFun)
{
    if(node!= NULL)
    {
        pFun(node);
        preOrderTraversal(node->left,pFun);
        preOrderTraversal(node->right,pFun);
    }
}
void middleOrderTraversal(BTreeNode *node,PrintFun *pFun)
{
    if(node!= NULL)
    {
        middleOrderTraversal(node->left,pFun);
        pFun(node);
        middleOrderTraversal(node->right,pFun);
    }
}
void postOrderTraversal(BTreeNode *node,PrintFun *pFun)
{
    if(node!= NULL)
    {
        postOrderTraversal(node->left,pFun);
        postOrderTraversal(node->right,pFun);
        pFun(node);
    }
}

void levelOrderTreversal(BTreeNode *node,PrintFun *pFun)
{
    if(node != NULL)
    {
        LinkQueue *queue = LinkQueue_Create();

        LinkQueue_Append(queue, node);

        while (LinkQueue_Length(queue) > 0)
        {
            BTreeNode *node = (BTreeNode *)LinkQueue_Retrieve(queue);
            pFun(node);
            LinkQueue_Append(queue, node->left);
            LinkQueue_Append(queue, node->right);
        }

        LinkQueue_Destroy(queue);
    }
}
void threadViaLeft(BTreeNode *node,BTreeNode **p)
{

}

void threadViaList(BTreeNode *node, SequenceList *list)
{
    if(node != NULL && list != NULL)
    {
        SeqList_Insert(list, node, SeqList_Length(list));
        threadViaList(node->left,list);
        threadViaList(node->right,list);
    }
}


