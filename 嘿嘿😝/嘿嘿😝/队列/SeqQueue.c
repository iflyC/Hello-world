

//
//  SequenceQueue.c
//  鍢垮樋馃槤
//
//  Created by iflyC on 2018/11/12.
//  Copyright 漏 2018骞iflyC. All rights reserved.
//

#include "SeqQueue.h"
#include "SequenceList.h"

SeqQueue* SeqQueue_Create(int capacity) // O(1)
{
    return SeqList_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue *queue) // O(1)
{
    SeqList_Destroy(queue);
}

void SeqQueue_Clear(SeqQueue *queue) // O(1)
{
    SeqList_Destroy(queue);
}

int SeqQueue_Append(SeqQueue *queue, void *item) // O(1)
{
    return SeqList_Insert(queue, item, SeqList_Length(queue));

}

void * SeqQueue_Retrieve(SeqQueue *queue) // O(n)
{
    return SeqList_Delete(queue, 0);
}

void *SeqQueue_Header(SeqQueue *queue) // O(1)
{
    return SeqList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue *queue) // O(1)
{
    return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue *queue) // O(1)
{
    return SeqList_Capacity(queue);
}

