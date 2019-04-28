//
//  linkQueue.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/12.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "LinkQueue.h"
#include "LinkList.h"
#include <stdlib.h>
typedef struct _tag_LinkQueueNode TLinkQueueNode;
struct _tag_LinkQueueNode
{
    LinkListNode next;
    void *item;
};
LinkQueue* LinkQueue_Create(void)
{
    return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue *queue)
{
    LinkQueue_Clear(queue);
    LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue *queue)
{
    while (LinkList_Length(queue) > 0) {
        LinkList_Delete(queue, 0);
    }
}

int LinkQueue_Append(LinkQueue *queue, void *item)
{
    TLinkQueueNode *node = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
    int ret = node != NULL && item != NULL;
    if(ret)
    {
        node->item = item;
        ret = LinkList_Insert(queue, LinkList_Length(queue), (void *)node);

    }else{
        free(node);
    }

    return ret;
}

void * LinkQueue_Retrieve(LinkQueue *queue)
{
    TLinkQueueNode *node = (TLinkQueueNode *)LinkList_Delete(queue, 0);
    void *ret = NULL;
    if(node != NULL)
    {
        ret = node->item;
        free(node);
    }
    return ret;
}

void *LinkQueue_Header(LinkQueue *queue)
{
    TLinkQueueNode *node = (TLinkQueueNode *)LinkList_Get(queue, 0);
    void *ret = NULL;
    if(node != NULL)
    {
        ret = node->item;
    }
    return ret;
}

int LinkQueue_Length(LinkQueue *queue)
{
    return LinkList_Length(queue);
}
