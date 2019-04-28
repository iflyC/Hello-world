//
//  SeqQueue_Pro.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/12.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef SeqQueue_Pro_h
#define SeqQueue_Pro_h

#include <stdio.h>

typedef void SeqQueuePro;

SeqQueuePro* SeqQueuePro_Create(int capacity);

void SeqQueuePro_Destroy(SeqQueuePro *queue);

void SeqQueuePro_Clear(SeqQueuePro *queue);

int SeqQueuePro_Append(SeqQueuePro *queue, void *item);

void * SeqQueuePro_Retrieve(SeqQueuePro *queue);

void *SeqQueuePro_Header(SeqQueuePro *queue);

int SeqQueuePro_Length(SeqQueuePro *queue);

int SeqQueuePro_Capacity(SeqQueuePro *queue);

#endif /* SeqQueue_Pro_h */
