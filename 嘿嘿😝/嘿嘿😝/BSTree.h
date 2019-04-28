//
//  BSTree.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/29.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef BSTree_h
#define BSTree_h

#include <stdio.h>

typedef void BSTree;
typedef void BSKey;
typedef struct _tagBSTreeNode BSTreeNode;
struct _tagBSTreeNode
{
    BSKey *key;
    BSTreeNode *left;
    BSTreeNode *right;
};
typedef int (CompareFun)(BSKey *key1, BSKey *key2);

typedef void(PrintFun) (BSTreeNode *node);

BSTree *BTree_Create(void);

void BSTree_Destroy(BSTree *tree);

void BSTree_Clear(BSTree *tree);

int BSTree_Insert(BSTree *tree,BSTreeNode *node, CompareFun *cFun);

BSTreeNode *BSTree_Delete(BSTree *tree, BSKey *key, CompareFun *cFun);

BSTreeNode *BSTree_Get(BSTree *tree ,BSKey *key, CompareFun *cFun);

BSTreeNode *BSTree_Root(BSTree *tree);

int BSTree_Length(BSTree *tree);

int BSTree_Degree(BSTree *tree);

int BSTree_Height(BSTree *tree);

void BSTree_Display(BSTree *tree,PrintFun *pFun);

#endif /* BSTree_h */
