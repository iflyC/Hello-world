//
//  LinkStack.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/6.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>


typedef void LinkStack;

LinkStack *LinkStack_Create(void);

void LinkStack_Destroy(LinkStack *stack);

void LinkStack_Clear(LinkStack * stack);

int LinkStack_Push(LinkStack *stack, void *item);

void *LinkStack_Pop(LinkStack *stack);

void *LinkStack_Top(LinkStack *stack);

int LinkStack_Size(LinkStack *stack);


#endif /* LinkStack_h */
