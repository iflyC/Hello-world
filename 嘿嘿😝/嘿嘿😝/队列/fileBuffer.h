//
//  fileBuffer.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/13.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#ifndef fileBuffer_h
#define fileBuffer_h

#include <stdio.h>
#define bufferSize 4380
void initBuffer(void);
void saveByte(char byte);

int getBufferFlag(void);
struct FileBuffer
{

    char block[bufferSize];
    int head;
    int rear;
    int length;
};

struct FileBuffer buffer;

#endif /* fileBuffer_h */
