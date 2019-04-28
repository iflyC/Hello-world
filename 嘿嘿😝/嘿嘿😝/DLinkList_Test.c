//
//  DLinkList_Test.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/27.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "DLinkList_Test.h"
#include "DLinkList.h"
#include <string.h>
struct Value2
{
    DLinkListNode header;
    int value;
};
char *format(char *string)
{

    string = "03-12-2017";
    char temp[10] = {0};
    int i = 0;
    for( i = 0; i < 5;i++)
    {

        temp[i+5] = string[i];
    }
    for( i = 0; i < 4;i++)
    {

        temp[i] = string[i+6];
    }
    temp[i] = '-';
    printf("%s\n",temp);


    return temp;

}
void DLinkList_Test(void)
{
    DLinkList *list = DLinkList_Create();

    struct Value2 v1;
    struct Value2 v2;
    struct Value2 v3;
    struct Value2 v4;
    struct Value2 v5;
    struct Value2 v6;
    struct Value2 v7;
    struct Value2 v8;
    struct Value2 v9;

    v1.value = 1;
    v2.value = 2;
    v3.value = 3;
    v4.value = 4;
    v5.value = 5;
    v6.value = 6;
    v7.value = 7;
    v8.value = 8;
    v9.value = 9;


    DLinkList_Insert(list, (DLinkListNode *)&v1, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v2, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v3, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v4, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v5, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v6, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v7, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v8, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode *)&v9, DLinkList_Length(list));

    for(int i = 0; i < DLinkList_Length(list); i++)
    {
        struct Value2 *v = (struct Value2 *)DLinkList_Get(list, i);
        printf("%d",v->value);
    }
    DLinkList_Destroy(list);
}
