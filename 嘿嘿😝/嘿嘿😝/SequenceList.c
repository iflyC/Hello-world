//
//  SequenceList.c
//  数据结构
//
//  Created by iflyC on 2018/9/13.
//  Copyright © 2018年 iflyC. All rights reserved.
//

/*
 数据封装&定义
 第pos个元素，移动pos次的下一个
 */
#include <stdlib.h>
#include "SequenceList.h"

typedef unsigned long TSequenceListNode;
typedef struct _tag_SequenceList
{
    int capacity;
    int length;
    TSequenceListNode *node;
}TSequenceList;

SequenceList *SeqList_Create(int capacity)
{
    TSequenceList *ret = NULL;
    if(capacity > 0)
    {
        ret = (TSequenceList *)malloc(sizeof(TSequenceList) + sizeof(TSequenceListNode) * capacity);

    }
    if(ret != NULL)
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSequenceListNode *)(ret + 1);
    }

    return ret;
}

void SeqList_Destroy(SequenceList *list)
{
    free(list);
}

void SeqList_Clear(SequenceList *list)
{
    TSequenceList *sList = (TSequenceList *)list;
    if(sList != NULL)
    {
        sList->length = 0;
    }
}

int SeqList_Length(SequenceList *list)
{
    int ret = -1;
    TSequenceList *sList = (TSequenceList *)list;
    if(sList != NULL)
    {
        ret = sList->length;
    }

    return ret;
}

int SeqList_Capacity(SequenceList *list)
{
    int ret = -1;
    TSequenceList *sList = (TSequenceList *)list;
    if(sList != NULL)
    {
        ret = sList->capacity;
    }

    return ret;
}
SequenceListNode *SeqList_Get(SequenceList *list, int pos)
{
    SequenceListNode *ret = NULL;
    TSequenceList *sList = (TSequenceList *)list;
    if(sList != NULL && pos >= 0 && pos < sList->length)
    {
        ret = (SequenceListNode *)sList->node[pos];
    }

    return ret;

}
int SeqList_Insert(SequenceList *list,SequenceListNode *node,int pos)// O(n)
{
    int i= 0;
    TSequenceList *sList = (TSequenceList *)list;
    int ret = (sList != NULL);
    ret = ret && node != NULL && pos >= 0;
    ret = ret  && sList->length + 1 <= sList->capacity;

    if(ret)
    {
        if(pos > sList ->length)
        {
            pos = sList->length;
        }
        for(i = sList->length; i > pos; i--)
        {
            sList->node[i] = sList->node[i - 1];
        }
        sList->node[pos] = (TSequenceListNode)node;
        sList->length++;

    }
    return ret;
}

SequenceListNode * SeqList_Delete(SequenceList *list,int pos) // O(n)
{
    TSequenceList *sList = (TSequenceList *)list;
    int i = 0;
    SequenceListNode *ret = SeqList_Get(list, pos);
    if(ret)
    {

        for(i = pos + 1; i < sList->length; i++)
        {
            sList->node[i - 1] = sList->node[i];
        }
        sList->length--;
    }
    return ret;
}
