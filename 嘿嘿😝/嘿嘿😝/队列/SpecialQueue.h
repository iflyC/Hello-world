//
//  SpecialQueue.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/14.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef SpecialQueue_h
#define SpecialQueue_h

#include <stdio.h>

typedef void SpecialQueue;

SpecialQueue* SpecialQueue_Create(void);

void SpecialQueue_Destroy(SpecialQueue *queue);

void SpecialQueue_Clear(SpecialQueue *queue);

int SpecialQueue_Append(SpecialQueue *queue, void *item);

void * SpecialQueue_Retrieve(SpecialQueue *queue);

void *SpecialQueue_Header(SpecialQueue *queue);

int SpecialQueue_Length(SpecialQueue *queue);


#endif /* SpecialQueue_h */
