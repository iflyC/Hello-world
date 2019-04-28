//
//  QueueTest.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/14.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "QueueTest.h"

#include <stdio.h>
#include "SeqQueue.h"
#include "SeqQueue_Pro.h"
#include "LinkQueue.h"
#include "LinkQueue_Pro.h"
#include "SpecialQueue.h"
void SeqQueueTest(void)
{
    SeqQueue *queue = SeqQueue_Create(10);
    for(unsigned long i = 1; i <= 10; i++)
    {
        SeqQueue_Append(queue, (void *)i);
    }
    printf("header:%d\n",(int)SeqQueue_Header(queue));
    printf("length:%d\n",(int)SeqQueue_Length(queue));

    for(int i = 0; i < 5; i++)
    {
        int temp = (int)SeqQueue_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
    printf("header:%d\n",(int)SeqQueue_Header(queue));
    printf("length:%d\n",(int)SeqQueue_Length(queue));

    while (SeqQueue_Length(queue) > 0) {
        int temp = (int)SeqQueue_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }

}
void LinkQueueTest(void)
{
    LinkQueue *queue = LinkQueue_Create();
    for(unsigned long i = 1; i <= 10; i++)
    {
        LinkQueue_Append(queue, (void *)i);
    }
    printf("header:%d\n",(int)LinkQueue_Header(queue));
    printf("length:%d\n",(int)LinkQueue_Length(queue));

    for(int i = 0; i < 5; i++)
    {
        int temp = (int)LinkQueue_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
    printf("header:%d\n",(int)LinkQueue_Header(queue));
    printf("length:%d\n",(int)LinkQueue_Length(queue));

    while (LinkQueue_Length(queue) > 0) {
        int temp = (int)LinkQueue_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
}
void SeqProQueueTest(void)
{
    SeqQueuePro *queue = SeqQueuePro_Create(20);
    for(unsigned long i = 1; i <= 10; i++)
    {
        SeqQueuePro_Append(queue, (void *)i);
    }
    printf("header:%d\n",(int)SeqQueuePro_Header(queue));
    printf("length:%d\n",(int)SeqQueuePro_Length(queue));

    for(int i = 0; i < 5; i++)
    {
        int temp = (int)SeqQueuePro_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
    printf("header:%d\n",(int)SeqQueuePro_Header(queue));
    printf("length:%d\n",(int)SeqQueuePro_Length(queue));

    while (SeqQueuePro_Length(queue) > 0) {
        int temp = (int)SeqQueuePro_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
}
void LinkProQueueTest(void)
{
    LinkQueuePro *queue = LinkQueuePro_Create();
    for(unsigned long i = 1; i <= 10; i++)
    {
        LinkQueuePro_Append(queue, (void *)i);
    }
    printf("header:%d\n",(int)LinkQueuePro_Header(queue));
    printf("length:%d\n",(int)LinkQueuePro_Length(queue));

    for(int i = 0; i < 5; i++)
    {
        int temp = (int)LinkQueuePro_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
    printf("header:%d\n",(int)LinkQueuePro_Header(queue));
    printf("length:%d\n",(int)LinkQueuePro_Length(queue));

    while (LinkQueuePro_Length(queue) > 0) {
        int temp = (int)LinkQueuePro_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
}
void SpecialQueueTest(void)
{
    SpecialQueue *queue = SpecialQueue_Create();
    for(unsigned long i = 1; i <= 10; i++)
    {
        SpecialQueue_Append(queue, (void *)i);
    }
    printf("header:%d\n",(int)SpecialQueue_Header(queue));
    printf("length:%d\n",(int)SpecialQueue_Length(queue));

    for(int i = 0; i < 5; i++)
    {
        int temp = (int)SpecialQueue_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
    printf("header:%d\n",(int)SpecialQueue_Header(queue));
    printf("length:%d\n",(int)SpecialQueue_Length(queue));

    while (SpecialQueue_Length(queue) > 0) {
        int temp = (int)SpecialQueue_Retrieve(queue);
        printf("retrieve:%d\n",temp);
    }
}
