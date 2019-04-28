//
//  LinkList.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/20.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>

typedef void LinkList;

typedef struct _tag_LinkListNode LinkListNode;

struct _tag_LinkListNode
{
    LinkListNode *next;
};

LinkList *LinkList_Create(void);

void LinkList_Destroy(LinkList *list);

void  LinkList_Clear(LinkList *list);

int LinkList_Length(LinkList *list);

LinkListNode *LinkList_Get(LinkList *list, int pos);

int LinkList_Insert(LinkList *list, int pos, LinkListNode *node);

LinkListNode *LinkList_Delete(LinkList *list, int pos);




#endif /* LinkList_h */
