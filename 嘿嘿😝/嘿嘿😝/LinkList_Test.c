//
//  LinkList_Test.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/20.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "LinkList_Test.h"
#include "LinkList.h"
struct Value
{
    LinkListNode header;
    int value;
};
void LinkListTest(void)
{

    LinkList *list = LinkList_Create();
    printf("current length:%d\n",LinkList_Length(list));

    struct Value v1;
    struct Value v2;
    struct Value v3;
    struct Value v4;

    v1.value = 1;
    v2.value = 2;
    v3.value = 3;
    v4.value = 4;

    LinkList_Insert(list, 0, (LinkListNode *)&v1);
    LinkList_Insert(list, 0, (LinkListNode *)&v2);
    LinkList_Insert(list, 0, (LinkListNode *)&v3);
    LinkList_Insert(list, 0, (LinkListNode *)&v4);

    for(int i = 0; i < LinkList_Length(list); i++)
    {
        struct Value *node = (struct Value *)LinkList_Get(list, i);
        printf("%d\n",node->value);
    }
    printf("current length:%d\n",LinkList_Length(list));

    while(LinkList_Length(list) > 0)
    {
        struct Value *node = (struct Value *)LinkList_Delete(list, 0);
        printf("%d\n",node->value);
    }
    printf("current length:%d\n",LinkList_Length(list));

    LinkList_Destroy(list);
}
