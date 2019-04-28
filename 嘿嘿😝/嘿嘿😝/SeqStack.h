//
//  SeqStack.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/27.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef SeqStack_h
#define SeqStack_h

#include <stdio.h>
typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destroy(SeqStack *stack);

void SeqStack_Clear(SeqStack *stack);

int SeqStack_Push(SeqStack *stack,void *item);

void* SeqStack_Pop(SeqStack *stack);

void* SeqStack_Top(SeqStack *stack);

int SeqStack_Capacity(SeqStack *stack);

int SeqStack_Size(SeqStack *stack);

#endif /* SeqStack_h */
