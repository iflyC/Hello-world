//
//  CirCleLinkList.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/27.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "CircleLinkList.h"
#include <stdlib.h>
typedef struct _tag_CircleList
{
    CircleListNode header;
    CircleListNode *slider;
    int length;
}TCircleList;

CircleList* CircleList_Create()
{
    TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
    if(ret != NULL)
    {
        ret->header.next = NULL;
        ret->length = 0;
        ret->slider = NULL;
    }
    return ret;
}

void CircleList_Destroy(CircleList* list)
{
    free(list);
}

void CircleList_Clear(CircleList* list)
{
    TCircleList *slist = (TCircleList *)list;
    if(slist != NULL)
    {
        slist->length = 0;
        slist->header.next = NULL;
        slist->slider = NULL;
    }
}

int CircleList_Length(CircleList* list)
{
    int ret = -1;
    TCircleList *slist = (TCircleList *)list;
    if(slist != NULL)
    {
        ret = slist->length;
    }
    return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
    TCircleList *slist = (TCircleList *)list;
    int ret = slist != NULL;
    ret = ret && node != NULL && pos >= 0;
    CircleListNode *current = (CircleListNode *)slist;
    CircleListNode *last = NULL;
    if(ret)
    {
        for(int i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;

        // 插入的元素是首个元素时
        if(slist->length == 0)
        {
            node->next = node;
            slist->slider = node;
        }
        slist->length++;
        // 插入的元素位置为0时
        if(current == (CircleListNode *)slist)
        {
            last = CircleList_Get(list, slist->length -1);
            last->next = node;
        }

    }

    return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
    CircleListNode *ret = NULL;
    TCircleList *slist = (TCircleList *)list;
    if(slist != NULL && pos >= 0 && slist->length > 0)
    {
        CircleListNode *current = (CircleListNode *)slist;
        for(int i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }
        ret = current->next;
    }
    return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
    CircleListNode *ret = NULL;
    TCircleList *slist = (TCircleList *)list;
    if(slist != NULL && pos >= 0 && slist->length > 0)
    {
        CircleListNode *current = (CircleListNode *)slist;
        CircleListNode *last = NULL;
        //定位
        for(int i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }

        // 特殊情况 删除的是pos为0的节点
        if(current == (CircleListNode *)slist)
        {
            last = CircleList_Get(list, slist->length - 1);
        }
        // 常规删除节点
        ret = current->next;

        current->next = ret->next;

        slist->length--;

        if(last != NULL)
        {
            last->next = ret->next;
            slist->header.next = ret->next;
        }
        if(slist->slider == ret)
        {
            slist->slider = ret->next;
        }
        if(slist->length == 0)
        {
            slist->header.next = NULL;
            slist->slider = NULL;
        }
    }
    return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
    CircleListNode *ret = NULL;
    TCircleList *slist = (TCircleList *)list;
    int i = 0;
    if(slist != NULL && node != NULL)
    {
        CircleListNode *current = (CircleListNode *)slist;
        for( i = 0; i < slist->length; i++)
        {

            if(current->next == node)
            {
                ret = current->next;
                break;
            }
            current = current->next;
        }
        if(ret != NULL)
        {
            CircleList_Delete(list, i);
        }
    }
    return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
    CircleListNode *ret = NULL;
    TCircleList *slist = (TCircleList *)list;
    if(slist != NULL)
    {
        slist->slider = slist->header.next;
        ret = slist->slider;
    }
    return ret;
}

CircleListNode* CircleList_Current(CircleList* list)
{
    CircleListNode *ret = NULL;
    TCircleList *slist = (TCircleList *)list;
    if(slist != NULL)
    {
        ret = slist->slider;
    }
    return ret;
}

CircleListNode* CircleList_Next(CircleList* list)
{
    CircleListNode *ret = NULL;
    TCircleList *slist = (TCircleList *)list;
    if(slist != NULL)
    {
        ret = slist->slider;
        slist->slider = ret->next;
    }
    return ret;
}
