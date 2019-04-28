//
//  TreeTest.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/20.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "TreeTest.h"
#include "GTree.h"
void GTreeTest(void)
{
    GTree *tree = GTree_Create();
    GTree_Insert(tree, (GTreeData *)'A', -1);
    GTree_Insert(tree, (GTreeData *)'B', 0);
    GTree_Insert(tree, (GTreeData *)'C', 0);
    GTree_Insert(tree, (GTreeData *)'D', 0);
    GTree_Insert(tree, (GTreeData *)'E', 3);
    GTree_Insert(tree, (GTreeData *)'F', 3);

    GTree_Insert(tree, (GTreeData *)'G', 2);
    GTree_Insert(tree, (GTreeData *)'H', 2);
    GTree_Display(tree);
    printf("after delete D:\n");
    GTree_Delete(tree, 3);
    GTree_Display(tree);
}
