//
//  BTree.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/22.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef BTree_h
#define BTree_h

#include <stdio.h>

typedef void BTree;
typedef unsigned long long BTPos;
typedef struct _tag_BTreeNode BTreeNode;
struct _tag_BTreeNode
{
    BTreeNode *left;
    BTreeNode *right;
};
typedef void(PrintFun) (BTreeNode *node);

BTree *BTree_Create(void);

void BTree_Destroy(BTree *tree);

void BTree_Clear(BTree *tree);

int BTree_Insert(BTree *tree,BTreeNode *node,BTPos pos,int count,int flag);

BTreeNode *BTree_Delete(BTree *tree,BTPos pos, int count);

BTreeNode *BTree_Get(BTree *tree,BTPos pos, int count);

BTreeNode *BTree_Root(BTree *tree);

int BTree_Length(BTree *tree);

int BTree_Degree(BTree *tree);

int BTree_Height(BTree *tree);

void BTree_Display(BTree *tree,PrintFun *pFun);


#endif /* BTree_h */
