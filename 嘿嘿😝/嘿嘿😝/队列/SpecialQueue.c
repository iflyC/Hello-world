//
//  SpecialQueue.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/14.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "SpecialQueue.h"
#include "LinkList.h"
#include "LinkStack.h"
#include <stdlib.h>

typedef struct _tag_SpecialQueue
{
    LinkStack *inStack;
    LinkStack *outStack;
}TSpecialQueue;

SpecialQueue* SpecialQueue_Create(void)
{
    TSpecialQueue *ret = (TSpecialQueue *)malloc(sizeof(TSpecialQueue));
    if(ret != NULL)
    {
        ret->inStack = LinkStack_Create();
        ret->outStack = LinkStack_Create();

        if(ret->inStack == NULL || ret->outStack == NULL)
        {
            free(ret->inStack);
            free(ret->outStack);
            free(ret);
            ret = NULL;
        }
    }
    return ret;
}

void SpecialQueue_Destroy(SpecialQueue *queue)
{
    SpecialQueue_Clear(queue);
    free(queue);
}

void SpecialQueue_Clear(SpecialQueue *queue)
{
    TSpecialQueue *sQueue = (TSpecialQueue *)queue;
    if(sQueue != NULL)
    {
        LinkStack_Clear(sQueue->inStack);
        LinkStack_Clear(sQueue->outStack);
    }

}

int SpecialQueue_Append(SpecialQueue *queue, void *item)
{
    TSpecialQueue *sQueue = (TSpecialQueue *)queue;
    int ret = sQueue != NULL && item != NULL;
    if(ret)
    {
        LinkStack_Push(sQueue->inStack, item);
    }
    return ret;
}

void * SpecialQueue_Retrieve(SpecialQueue *queue)
{
    TSpecialQueue *sQueue = (TSpecialQueue *)queue;
    void *ret = NULL;
    if(sQueue != NULL)
    {
        if(LinkStack_Size(sQueue->outStack) == 0)
        {
            while(LinkStack_Size(sQueue->inStack) > 0)
            {
                LinkStack_Push(sQueue->outStack, LinkStack_Pop(sQueue->inStack));
            }
        }
        ret = LinkStack_Pop(sQueue->outStack);

    }
    return ret;
}

void *SpecialQueue_Header(SpecialQueue *queue)
{
    TSpecialQueue *sQueue = (TSpecialQueue *)queue;
    void *ret = NULL;
    if(sQueue != NULL)
    {
        if(LinkStack_Size(sQueue->outStack) == 0)
        {
            while(LinkStack_Size(sQueue->inStack) > 0)
            {
                LinkStack_Push(sQueue->outStack, LinkStack_Pop(sQueue->inStack));
            }
        }
        ret = LinkStack_Top(sQueue->outStack);
    }
    return ret;
}

int SpecialQueue_Length(SpecialQueue *queue)
{
    TSpecialQueue *sQueue = (TSpecialQueue *)queue;
    int ret = -1;
    if(sQueue != NULL)
    {
        ret = LinkStack_Size(sQueue->inStack) + LinkStack_Size(sQueue->outStack);
    }
    return ret;
}

