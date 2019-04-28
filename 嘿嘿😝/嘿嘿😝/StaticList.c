//
//  StaticList.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/20.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "StaticList.h"
#include <stdio.h>
#include <stdlib.h>
#define AVAILABLE -1
typedef struct _tag_StaticListNode
{
    unsigned long data;
    int next;
}TStaticListNode;
typedef struct _tag_StaticList
{
    int capacity;
    TStaticListNode header;
    TStaticListNode node[];
}TStaticList;
StaticList* StaticList_Create(int capacity)
{
    TStaticList *ret = (TStaticList *)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity + 1));
    if(ret != NULL)
    {
        ret->capacity = capacity;
        ret->header.data = 0; // the length of the list
        ret->header.next = 0;
        for(int i = 1; i <= capacity; i++)
        {
            ret->node[i].next = AVAILABLE;
        }
    }
    return ret;
}

void StaticList_Destroy(StaticList *list)
{
    free(list);
}

void StaticList_Clear(StaticList *list)
{
    TStaticList *sList = (TStaticList *)list;
    if(sList != NULL)
    {
        sList->header.data = 0;
        sList->header.next = 0;

        for(int i = 1; i <= sList->capacity; i++)
        {
            sList->node[i].next = AVAILABLE;
        }
    }
}

int StaticList_Length(StaticList *list)
{
    int ret = -1;
    TStaticList *sList = (TStaticList *)list;
    if(sList != NULL)
    {
        ret = (int)sList->header.data;
    }
    return ret;
}

int StaticList_Capacity(StaticList *list)
{
    int ret = -1;
    TStaticList *sList = (TStaticList *)list;
    if(sList != NULL)
    {
        ret = sList->capacity;
    }
    return ret;
}

int StaticList_Insert(StaticList *list, int pos,StaticListNode *node)
{
    TStaticList *sList = (TStaticList *)list;
    int ret = sList != NULL;
    ret = ret && pos >= 0 && sList->header.data +1 <= sList->capacity;

    if(ret)
    {
        int current = 0;
        int index = 0;

        for(int i = 1; i <= sList->capacity; i++)
        {
            if(sList->node[i].next == AVAILABLE)
            {
                index = i;
                break;
            }
        }
        sList->node[index].data = (unsigned long)node;
        sList->node[0] = sList->header;
        for(int i = 0; i < pos; i++)
        {
            current = sList->node[current].next;
        }
        sList->node[index].next = sList->node[current].next;
        sList->node[current].next = index;
        sList->node[0].data++;

        sList->header = sList->node[0];
    }
    return ret;
}

StaticListNode *StaticList_Delete(StaticList *list, int pos)
{
    StaticListNode *ret = NULL;
    TStaticList *sList = (TStaticList *)list;
    int current = 0;
    int object =  0;
    if(sList != NULL && pos >= 0 && pos < sList->header.data)
    {
        sList->node[0] = sList->header;
        for(int i = 0; i < pos; i++)
        {
            current = sList->node[current].next;
        }

        object = sList->node[current].next;
        sList->node[current].next = sList->node[object].next;
        sList->node[0].data--;

        sList->header = sList->node[0];
        sList->node[object].next = AVAILABLE;
        ret = (StaticListNode *)sList->node[object].data;
    }

    return ret;
}

StaticListNode *StaticLIst_Get(StaticList *list, int pos)
{
    StaticListNode *ret = NULL;
    TStaticList *sList = (TStaticList *)list;
    int current = 0;
    int object =  0;
    if(sList != NULL && pos >= 0 && pos < sList->header.data)
    {
        for(int i = 0; i < pos; i++)
        {
            current = sList->node[current].next;
        }
        object = sList->node[current].next;
        ret = (StaticListNode *)sList->node[object].data;
    }
    return ret;;
}
