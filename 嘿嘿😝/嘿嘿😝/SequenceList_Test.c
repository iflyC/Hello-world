//
//  SequenceList_Test.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/20.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include <stdio.h>

#include "SequenceList.h"
void testSequenceList(void)
{
    SequenceList *list = SeqList_Create(10);

    int a = 0;
    int b = 1;
    int c = 2;

    SeqList_Insert(list, &a, 0);
    SeqList_Insert(list, &b, 0);
    SeqList_Insert(list, &c, 0);

    for(int i = 0; i < SeqList_Length(list); i ++)
    {
        int *p = SeqList_Get(list, i);
        printf("%d\n",*p);
    }

    while (SeqList_Length(list) > 0) {
        int *p = SeqList_Delete(list, 0);
        printf("%d\n",*p);
    }
    printf("length: %d\n",SeqList_Length(list));

    SeqList_Destroy(list);
}
