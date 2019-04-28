//
//  SequenceQueue.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/12.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef SequenceQueue_h
#define SequenceQueue_h

#include <stdio.h>

typedef void SeqQueue;

SeqQueue* SeqQueue_Create(int capacity);

void SeqQueue_Destroy(SeqQueue *queue);

void SeqQueue_Clear(SeqQueue *queue);

int SeqQueue_Append(SeqQueue *queue, void *item);

void * SeqQueue_Retrieve(SeqQueue *queue);

void *SeqQueue_Header(SeqQueue *queue);

int SeqQueue_Length(SeqQueue *queue);

int SeqQueue_Capacity(SeqQueue *queue);

#endif /* SequenceQueue_h */
