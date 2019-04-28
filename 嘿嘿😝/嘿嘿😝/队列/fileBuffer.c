//
//  fileBuffer.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/13.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "fileBuffer.h"


void initBuffer(void)
{
    buffer.head = 0;
    buffer.rear = 0;
    buffer.length = 0;
}
void saveByte(char byte)
{
    buffer.block[buffer.rear] = byte;
    buffer.rear = (buffer.rear + 1) % bufferSize;
    buffer.length++;
}


