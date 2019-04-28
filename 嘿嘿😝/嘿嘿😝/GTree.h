//
//  GTree.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/19.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef GTree_h
#define GTree_h

#include <stdio.h>


typedef void GTree;
typedef void GTreeData;

GTree *GTree_Create(void);

void GTree_Destroy(GTree *tree);

void GTree_Clear(GTree *tree);

int GTree_Insert(GTree *tree,GTreeData *data,int pPos);

GTreeData *GTree_Delete(GTree *tree,int pos);

int GTree_Length(GTree *tree);

int GTree_Degree(GTree *tree);

int GTree_Height(GTree *tree);

void GTree_Display(GTree *tree);


#endif /* GTree_h */
