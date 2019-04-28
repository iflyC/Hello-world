//
//  linkQueue.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/12.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef linkQueue_h
#define linkQueue_h

#include <stdio.h>

typedef void LinkQueue;

LinkQueue* LinkQueue_Create(void);

void LinkQueue_Destroy(LinkQueue *queue);

void LinkQueue_Clear(LinkQueue *queue);

int LinkQueue_Append(LinkQueue *queue, void *item);

void * LinkQueue_Retrieve(LinkQueue *queue);

void *LinkQueue_Header(LinkQueue *queue);

int LinkQueue_Length(LinkQueue *queue);



#endif /* linkQueue_h */
