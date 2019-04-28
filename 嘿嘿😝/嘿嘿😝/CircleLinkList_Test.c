//
//  CircleLinkList_Test.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/27.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "CircleLinkList_Test.h"
#include "CircleLinkList.h"
struct Value1
{
    CircleListNode header;
    int value;
};
void CircleList_Test(void)
{
    struct Value1 v1;
    struct Value1 v2;
    struct Value1 v3;
    struct Value1 v4;
    struct Value1 v5;
    struct Value1 v6;
    struct Value1 v7;
    struct Value1 v8;
    struct Value1 v9;
    struct Value1 v10;
    v1.value = 1;
    v2.value = 2;
    v3.value = 3;
    v4.value = 4;
    v5.value = 5;
    v6.value = 6;
    v7.value = 7;
    v8.value = 8;
    v9.value = 9;
    v10.value = 10;
    CircleList *list = CircleList_Create();

    CircleList_Insert(list, (CircleListNode *)&v1, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v2, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v3, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v4, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v5, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v6, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v7, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v8, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v9, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode *)&v10, CircleList_Length(list));

    // 约瑟夫问题
//    while (CircleList_Length(list) > 0) {
//
//        CircleListNode *node = NULL;
//        for(int i = 0; i < 3; i++)
//        {
//           node = CircleList_Next(list);
//        }
//
//       struct Value1 *v = (struct Value1 *) CircleList_DeleteNode(list, node);
//        printf("%d\n",v->value);
//    }



//    while (CircleList_Length(list) > 0) {
//        struct Value1 *v = (struct Value1 *) CircleList_Delete(list, 0);
//        printf("%d\n",v->value);
//    }
/*
    Node * node1 = header;
    Node *node2 = header;
    int i = 0;
    for( i = 0; node2 != NULL;i++)
    {
        node1 = node1->next;

        if(node1 = NULL)
        {
            break;
        }
        node2 = node2->next;
        node2 = node2->next;
    }



*/

    CircleList_Destroy(list);
}
/*
 无头结点链表找中间节点
Node *getMiddleNode(Node *header)
{
    Node *p1 = header;
    Node *p2 = header;
    while (p2) {
        p2 = p2->next;
        if(p2)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    return p1;
}
*/
