//
//  SeqQueue_Pro.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/12.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "SeqQueue_Pro.h"
#include <stdlib.h>
typedef unsigned long TSeqQueueProNode;
typedef struct _tag_SeqQueue TSeqQueue;
struct _tag_SeqQueue
{
    int capacity;
    int length;
    int front;
    int rear;
    TSeqQueueProNode *node;
};
SeqQueuePro* SeqQueuePro_Create(int capacity)
{
    TSeqQueue *ret = (TSeqQueue *)malloc(sizeof(TSeqQueue) + sizeof(TSeqQueueProNode) * capacity);
    if(ret != NULL)
    {
        ret->capacity = capacity;
        ret->front = 0;
        ret->rear = 0;
        ret->length = 0;
        ret->node = (TSeqQueueProNode *)(ret + 1);
    }
    return ret;
}

void SeqQueuePro_Destroy(SeqQueuePro *queue)
{
    free(queue);
}

void SeqQueuePro_Clear(SeqQueuePro *queue)
{
    TSeqQueue *sQueue = (TSeqQueue *)queue;
    if(sQueue != NULL)
    {
        sQueue->front = 0;
        sQueue->rear = 0;
        sQueue->length = 0;
    }
}

int SeqQueuePro_Append(SeqQueuePro *queue, void *item)
{
    TSeqQueue *sQueue = (TSeqQueue *)queue;
    int ret = sQueue != NULL && item != NULL && sQueue->length + 1 <= sQueue->capacity ;
    if(ret)
    {
        sQueue->node[sQueue->rear] = (TSeqQueueProNode)item;
        sQueue->rear = (sQueue->rear + 1 ) % sQueue->capacity;
        sQueue->length++;

    }
    return ret;
}

void * SeqQueuePro_Retrieve(SeqQueuePro *queue)
{
    TSeqQueue *sQueue = (TSeqQueue *)queue;
    void *ret = NULL;
    if(sQueue != NULL && sQueue->length > 0)
    {
        ret = (void *)sQueue->node[sQueue->front];
        sQueue->front = (sQueue->front + 1) % sQueue->capacity;
        sQueue->length--;
    }

    return ret;
}

void *SeqQueuePro_Header(SeqQueuePro *queue)
{
    TSeqQueue *sQueue = (TSeqQueue *)queue;
    void *ret = NULL;
    if(sQueue != NULL && sQueue->length > 0)
    {
        ret = (void *)sQueue->node[sQueue->front];
    }

    return ret;

}

int SeqQueuePro_Length(SeqQueuePro *queue)
{
    TSeqQueue *sQueue = (TSeqQueue *)queue;
    int ret = -1;
    if(sQueue != NULL)
    {
        ret = sQueue->length;
    }
    return ret;
}

int SeqQueuePro_Capacity(SeqQueuePro *queue)
{
    TSeqQueue *sQueue = (TSeqQueue *)queue;
    int ret = -1;
    if(sQueue != NULL)
    {
        ret = sQueue->capacity;
    }
    return ret;
}
