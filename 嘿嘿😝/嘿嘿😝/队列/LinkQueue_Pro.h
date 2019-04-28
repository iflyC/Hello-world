//
//  LinkQueue_Pro.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/12.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef LinkQueue_Pro_h
#define LinkQueue_Pro_h

#include <stdio.h>
typedef void LinkQueuePro;

LinkQueuePro* LinkQueuePro_Create(void);

void LinkQueuePro_Destroy(LinkQueuePro *queue);

void LinkQueuePro_Clear(LinkQueuePro *queue);

int LinkQueuePro_Append(LinkQueuePro *queue, void *item);

void * LinkQueuePro_Retrieve(LinkQueuePro *queue);

void *LinkQueuePro_Header(LinkQueuePro *queue);

int LinkQueuePro_Length(LinkQueuePro *queue);

int LinkQueuePro_Capacity(LinkQueuePro *queue);

#endif /* LinkQueue_Pro_h */
