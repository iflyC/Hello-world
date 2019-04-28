//
//  LinkStack.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/6.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "LinkStack.h"
#include "LinkList.h"
#include <stdlib.h>

typedef struct _tag_LinkStackNode LinkStackNode;
struct _tag_LinkStackNode
{
    LinkListNode header;
    void *item;
};

LinkStack *LinkStack_Create(void)
{
    return LinkList_Create();

}

void LinkStack_Destroy(LinkStack *stack)
{
    LinkStack_Clear(stack);
    LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack * stack)
{
    while (LinkStack_Size(stack) > 0)
    {
       LinkStack_Pop(stack);
    }
}

int LinkStack_Push(LinkStack *stack, void *item)
{
    LinkStackNode *node = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    int ret = node != NULL && item != NULL;
    if(ret)
    {
        node->item = item;
        LinkList_Insert(stack, 0, (LinkListNode *)node);
    }
    if(!ret)
    {
        free(node);
    }
    return ret;
}

void *LinkStack_Pop(LinkStack *stack)
{
    LinkStackNode  *node = (LinkStackNode *)LinkList_Delete(stack, 0);

    void *ret = NULL;
    if(node)
    {
        ret = node->item;
        free(node);
    }
    return ret;
}

void *LinkStack_Top(LinkStack *stack)
{
    LinkStackNode  *node = (LinkStackNode *)LinkList_Get(stack, 0);
    void *ret = NULL;
    if(node){
         ret = node->item;
    }
    return ret;
}

int LinkStack_Size(LinkStack *stack)
{
    return LinkList_Length(stack);
}
