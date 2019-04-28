//
//  DLinkList.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/27.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "DLinkList.h"
#include <stdlib.h>
typedef struct _tag_DLinkList
{
    DLinkListNode header;
    int length;
    DLinkListNode *slider;
}TDLinkList;

DLinkList* DLinkList_Create(void)
{
    TDLinkList *list = (TDLinkList *)malloc(sizeof(TDLinkList));
    if(list != NULL)
    {
        list->header.next = NULL;
        list->length = 0;
        list->slider = NULL;
    }
    return list;
}

void DLinkList_Destroy(DLinkList* list)
{
    free(list);
}

void DLinkList_Clear(DLinkList* list)
{
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL)
    {
        slist->header.next = NULL;
        slist->length = 0;
        slist->slider = NULL;
    }
}

int DLinkList_Length(DLinkList* list)
{
    int ret = -1;
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL)
    {

        ret = slist->length;

    }
    return  ret;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
    TDLinkList *slist = (TDLinkList *)list;

    int ret = slist != NULL && node != NULL;
    ret = ret && pos>= 0;
    DLinkListNode *current = (DLinkListNode *)slist;
    DLinkListNode *next = NULL;
    if(ret)
    {
        for(int i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }
        next  = current->next;
        node->next = next;
        node->pre = current;

        if(next != NULL)
        {
            next->pre = node;
        }
        current->next = node;

        if(current == (DLinkListNode *)slist)
        {
            node->pre = NULL;
        }
        if(slist->length == 0)
        {
            slist->slider = node;
        }

        slist->length++;
    }
    return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
    DLinkListNode *ret = NULL;
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL && pos >= 0 && pos < slist->length)
    {
        DLinkListNode *current = (DLinkListNode *)slist;
        for(int i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }
        ret = current->next;
    }
    return  ret;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
    DLinkListNode *ret = NULL;
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL && pos >= 0 && pos < slist->length)
    {
        DLinkListNode *current = (DLinkListNode *)slist;
        DLinkListNode *next = NULL;
        for(int i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }
        ret = current->next;
        next = ret->next;

        current->next = next;
        if(next != NULL)
        {
            next->pre = current;
            if(current == (DLinkListNode *)slist)
            {
                next->pre = NULL;
            }
        }

        if(slist->slider == ret)
        {
            slist->slider = next;
        }

        slist->length--;
    }
    return  ret;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
    DLinkListNode *ret = NULL;
    TDLinkList *slist = (TDLinkList *)list;
    int i = 0;
    if(slist != NULL && node != NULL &&  slist->length > 0)
    {
        DLinkListNode *current = (DLinkListNode *)slist;
        for( i = 0; i < slist->length; i++)
        {
            if(node == current->next)
            {
                ret = current->next;
                break;
            }
        }
        if(ret != NULL)
        {
            DLinkList_Delete(list, i);
        }
    }

    return  ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list)
{
    DLinkListNode *ret = NULL;
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL)
    {
        slist->slider = slist->header.next;
        ret = slist->slider;
    }

    return ret;

}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
    DLinkListNode *ret = NULL;
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL)
    {
        ret = slist->slider;
    }

    return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
    DLinkListNode *ret = NULL;
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL)
    {
        ret = slist->slider;
        slist->slider = ret->next;
    }

    return ret;
}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{
    DLinkListNode *ret = NULL;
    TDLinkList *slist = (TDLinkList *)list;
    if(slist != NULL)
    {
        ret = slist->slider;
        slist->slider = ret->pre;
    }
    return ret;
}
