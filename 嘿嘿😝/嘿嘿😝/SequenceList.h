//
//  SequenceList.h
//  数据结构
//
//  Created by iflyC on 2018/9/13.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>

typedef void SequenceList;
typedef void SequenceListNode;

SequenceList *SeqList_Create(int capacity);

void SeqList_Destroy(SequenceList *list);

void SeqList_Clear(SequenceList *list);

int SeqList_Length(SequenceList *list);

int SeqList_Capacity(SequenceList *list);

int SeqList_Insert(SequenceList *list,SequenceListNode *node,int pos);

SequenceListNode* SeqList_Delete(SequenceList *list,int pos);

SequenceListNode *SeqList_Get(SequenceList *list, int pos);

#endif /* SequenceList_h */
