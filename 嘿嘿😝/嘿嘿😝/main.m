//
//  main.m
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/13.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include <stdio.h>
//#include "SequenceList_Test.h"
//#include "LinkList_Test.h"
//#include "CircleLinkList_Test.h"
//#include "DLinkList_Test.h"
//#include "Recursive.h"
//#include "StackTest.h"
//#include "Stack_Application.h"
//#include "Recursive.h"
//#include "QueueTest.h"
#include "MySort.h"
//#include "fileBuffer.h"
#include "TreeTest.h"
#include <stdlib.h>
#include "search.h"
//void countOff(int n, int m, struct Person * array)
//{
//    int index = 0;
//    int count = 0;
//    int total = n;
//    while (n > 0) {
//        while (1) {
//
//            if(array[index].flag == 1)
//            {
//                count++;
//                if(count == m)
//                    break;
//            }
//            if(index++ == total) index = 0;
//        }
//        count = 0;
//        array[index].flag = 0;
//        printf("%d ",array[index].number);
//        n--;
//
//        while (array[index].flag == 0 && n > 0) {
//            if(index++ == total) index = 0;
//        }
//    }
//}
int main(int argc, char * argv[]) {

    search_test();
//    testSequenceList();

  //  LinkListTest();

  //  CircleList_Test();
//    DLinkList_Test();

   // hannuota(3, 'a', 'b', 'c');
   // SeqStack_Test();
   // LinkStack_Test();

//    scaner("\
//    void *LinkStack_Pop(LinkStack *stack)\
//    {\
//        LinkStackNode  *node = (LinkStackNode *)LinkList_Delete(stack, 0);\
//        void *ret = NULL;\
//        if(node)\
//        {\
//            ret = node-item;\
//            free(node);\
//        }\
//        return ret;\
//    }"\
//    );
//    transform("5-2*(3-4)*1");
  //  computer("5234-*1*-");

   // reverse("Hello DTOS");

//    for(int i = 0; i < 10; i++)
//    {
//        printf("%d--%d\n",i,feibonaqi(i));
//    }
//    printf("%d-%d-%d\n",strlen_R("Hello"),strlen_R("DTOS"),strlen_R("Hello_DTOS"));
//
//    hannuota(3, 'a', 'b', 'c');
//    char s[3] = "abc";
//    permutation(s, 0, 2);

   // eightQueen(1);

    
//    initBuffer();
//    char *b = NULL;
//    int length = 0;
//    // 关中断
//    if(buffer.length >= 1460)
//    {
//        b = &buffer.block[buffer.head];
//        length = buffer.length;
//        buffer.head = (buffer.head + length) % bufferSize;
//        buffer.length = 0;
//    }
    // 开中断
  //  DMA_Read(b,length);

    // 保存数据


//    SeqQueueTest();
//    LinkQueueTest();
//    SeqProQueueTest();
//    LinkProQueueTest();
   // SpecialQueueTest();
//    sortTest();
    GTreeTest();







}
