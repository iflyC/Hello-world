//
//  test.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/12/4.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Person{
    int number;
    int flag;
};
void countOff(int n, int m, struct Person * array)
{
    int index = 0;
    int count = 0;
    int total = n;
    while (n > 0) {
        // 数m下,确定一个人退出，并记录index
        while (1) {

            if(array[index].flag == 1)
            {
                count++;
                if(count == m)
                    break;
            }
            if(index++ == total) index = 0; // 数到最后一个，从头开始
        }
        // 清数据
        count = 0;
        // 退出的人标志0
        array[index].flag = 0;
        // 打印
        printf("%d ",array[index].number);
        // 总数减1
        n--;
        // index 指向下一个没有出去的人
        while (array[index].flag == 0 && n > 0) {
            if(index++ == total) index = 0;
        }
    }
}
int __main(int argc, char * argv[]) {

    int n = 10;
    struct Person *array = (struct Person *)malloc(sizeof(struct Person) * n);

    for(int i = 0; i < n; i++)
    {
        struct Person *person = &array[i];

        person->flag = 1;

        person->number = i;
        printf("person%d number:%d\n",i,person->number);
    }

    countOff(10, 3, array);

    printf("\n--------------end---------------\n");
    return 0;
}
