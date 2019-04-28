//
//  StaticList.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/20.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef StaticList_h
#define StaticList_h

#include <stdio.h>


typedef void StaticList;
typedef void StaticListNode;

StaticList *StaticList_Create(int capacity);

void StaticList_Destroy(StaticList *list);

void StaticList_Clear(StaticList *list);

int StaticList_Length(StaticList *list);

int StaticList_Capacity(StaticList *list);

int StaticList_Insert(StaticList *list, int pos,StaticListNode *node);

StaticListNode *StaticList_Delete(StaticList *list, int pos);

StaticListNode *StaticLIst_Get(StaticList *list, int pos);

#endif /* StaticList_h */
