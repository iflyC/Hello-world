//
//  LinkQueue_Pro.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/12.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "LinkQueue_Pro.h"
#include <stdlib.h>
typedef struct _tag_LinkQueueNode PLinkQueueNode;
struct _tag_LinkQueueNode
{
    PLinkQueueNode *next;
    void *item;
};

typedef struct _tag_PLinkQueue
{
    PLinkQueueNode *front;
    PLinkQueueNode *rear;
    int length;

}PLinkQueue;


LinkQueuePro* LinkQueuePro_Create(void)
{
    PLinkQueue *ret = (PLinkQueue *)malloc(sizeof(PLinkQueue));
    if(ret != NULL)
    {
        ret->length = 0;
        ret->front = NULL;
        ret->rear = NULL;
    }
    return ret;
}

void LinkQueuePro_Destroy(LinkQueuePro *queue)
{
    LinkQueuePro_Clear(queue);
    free(queue);
}

void LinkQueuePro_Clear(LinkQueuePro *queue)
{
    while (LinkQueuePro_Length(queue) > 0) {
        LinkQueuePro_Retrieve(queue);
    }
}

int LinkQueuePro_Append(LinkQueuePro *queue, void *item)
{
    PLinkQueue *pQueue = (PLinkQueue *)queue;
    PLinkQueueNode *node = (PLinkQueueNode *)malloc(sizeof(PLinkQueueNode));
    int ret = pQueue != NULL && item != NULL && node != NULL;
    if(ret)
    {
        node->item = item;
        node->next = NULL;
        if(pQueue->length == 0)
        {
            pQueue->front = node;
            pQueue->rear = node;

        }else{
            pQueue->rear->next = node;
            pQueue->rear = node;
        }
        pQueue->length++;

    }else{
        free(node);
    }
    return ret;
}

void * LinkQueuePro_Retrieve(LinkQueuePro *queue)
{
    PLinkQueue *pQueue = (PLinkQueue *)queue;
    void *ret = NULL;
    if(pQueue != NULL && pQueue->length > 0)
    {

        PLinkQueueNode *node = pQueue->front;
        pQueue->front = node->next;
        ret = node->item;
        free(node);

        pQueue->length--;
        if(pQueue->length == 0)
        {
            pQueue->front = NULL;
            pQueue->rear = NULL;
        }
    }
    return ret;
}


void *LinkQueuePro_Header(LinkQueuePro *queue)
{
    PLinkQueue *pQueue = (PLinkQueue *)queue;
    void *ret = NULL;
    if(pQueue != NULL && pQueue->length > 0)
    {
        ret = pQueue->front->item;
    }
    return ret;
}

int LinkQueuePro_Length(LinkQueuePro *queue)
{
    PLinkQueue *pQueue = (PLinkQueue *)queue;
    int ret = -1;
    if(pQueue!= NULL)
    {
        ret =  pQueue->length;
    }

    return ret;
}


