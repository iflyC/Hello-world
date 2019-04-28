//
//  StackTest.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/27.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "StackTest.h"
#include "LinkStack.h"
#include "SeqStack.h"
void SeqStack_Test(void)
{
    printf("SeqStack test begin .....\n");
    SeqStack *stack = SeqStack_Create(20);
    int a[10] = {0};
    for(int i = 0; i < 10; i++)
    {
        a[i] = i;
        SeqStack_Push(stack, a + i);
    }
    printf("Top item is %d\n",*(int *)SeqStack_Top(stack));
    printf("length is %d\n",SeqStack_Size(stack));
    while (SeqStack_Size(stack) > 0) {
       int * item = (int *)SeqStack_Pop(stack);
        printf("Pop:%d\n",*item);
    }
    SeqStack_Destroy(stack);
    printf("SeqStack test end .....\n");

}
void LinkStack_Test(void)
{
    printf("LinkStack test begin .....\n");
    LinkStack *stack = LinkStack_Create();
    int a[10] = {0};
    for(int i = 0; i < 10; i++)
    {
        a[i] = i;
        LinkStack_Push(stack, a + i);
    }
    printf("Top item is %d\n",*(int *)LinkStack_Top(stack));
    printf("length is %d\n",LinkStack_Size(stack));
    while (LinkStack_Size(stack) > 0) {
        int * item = (int *)LinkStack_Pop(stack);
        printf("pop:%d \n",*item);
    }
    LinkStack_Destroy(stack);
    printf("LinkStack test end .....\n");
}
