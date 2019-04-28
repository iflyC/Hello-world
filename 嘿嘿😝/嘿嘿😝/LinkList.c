//
//  LinkList.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/20.
//  Copyright © 2018年 iflyC. All rights reserved.
//
#include "LinkList.h"
#include <stdlib.h>

typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
}TLinkList;

LinkList *LinkList_Create(void)
{
    TLinkList *ret = (TLinkList *)malloc(sizeof(TLinkList));
    if(ret != NULL)
    {
        ret->length = 0;
        ret->header.next = NULL;
    }
    return ret;
}

void LinkList_Destroy(LinkList *list)
{
    free(list) ;
}

void LinkList_Clear(LinkList *list)
{
    TLinkList *sList = (TLinkList *)list;
    if(sList != NULL)
    {
        sList->length = 0;
        sList->header.next = NULL;
    }
}
int LinkList_Length(LinkList *list)
{
    TLinkList *sList = (TLinkList *)list;
    int ret = -1;
    if(sList != NULL)
    {
        ret = sList->length;
    }
    return ret;
}

LinkListNode *LinkList_Get(LinkList *list, int pos)
{
    LinkListNode *ret = NULL;
    TLinkList *sList = (TLinkList *)list;
    if(sList != NULL && pos >= 0 && pos < sList->length)
    {
        LinkListNode *current = &sList->header;
        for(int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        ret = current->next;
    }
    return ret;
}

int LinkList_Insert(LinkList *list, int pos, LinkListNode *node)
{
    TLinkList *sList = (TLinkList *)list;
    int ret = sList != NULL;
    ret = ret && pos >= 0 && node != NULL;
    if(ret)
    {
        LinkListNode *current = &sList->header;
        for(int i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
        sList->length++;
    }
    return ret;
}

LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
    LinkListNode *ret = NULL;
    TLinkList *sList = (TLinkList *)list;
    if(sList != NULL && pos >= 0 && pos < sList->length)
    {
        LinkListNode *current = &sList->header;
        for(int i = 0; i< pos; i++)
        {
            current = current->next;
        }
        ret = current->next;

        current->next = ret->next;

        sList->length--;
    }
    return ret;
}
